#pragma once

// Copyright Crabel Capital Management 2016
// All rights reserved

#include <stdint.h>

#define EXACT_LAYOUT  __attribute__((aligned(1), packed))

namespace mdp3 {

inline namespace implementation {

template<typename T, T NullValue> struct optional {
    T value;
    constexpr operator T() const noexcept { return value; }
    constexpr bool valid() const noexcept { return NullValue != value; }
};

/// \brief View of repeating groups
/// \tparam Element repeating group element
/// \tparam Controller "group size" that indicates span and count of elements
/// \note: The group is represented as the first element instead of the
/// controller to improve runtime support for the indexing operation
template<
    typename Element, typename Controller
> struct flyweight {
    /// \param edge one-past-the-end of the previous repeating group or message
    template<typename T> flyweight(T *edge):
        element(
            reinterpret_cast<Element *>(
                reinterpret_cast<Controller *>(edge) + 1
            )
        )
    {}

    Element *begin() noexcept { return element; }
    const Element *begin() const noexcept { return unconst()->begin(); }

    Element *end() noexcept { return element + controller()->numInGroup; }
    const Element *end() const noexcept { return unconst()->end(); }

    unsigned size() const noexcept {
        return unconst()->controller()->numInGroup;
    }

    Element &operator[](unsigned index) { return element[index]; }
    const Element &operator[](unsigned index) const { return element[index]; }

    Controller *controller() {
        return reinterpret_cast<Controller *>(element) - 1;
    }
    const Controller *controller() const { return unconst()->controller(); }

protected:
    Element *element;

    flyweight *unconst() const { return const_cast<flyweight *>(this); }
};

template<typename E, typename C> struct const_flyweight:
    flyweight<const E, const C>
{
    template<typename T> const_flyweight(T *edge):
        flyweight<const E, const C>(edge)
    {}
    const_flyweight(const flyweight<E, C> &model):
        flyweight<const E, const C>(model.controller())
    {}
};

template<
    typename T1, typename T2
> unsigned byte_span(const T1 *p1, const T2 *p2) {
    return
        reinterpret_cast<const char *>(p1) - reinterpret_cast<const char *>(p2);
}

}

/// All MDP3 messages will be specializations of message on their id
/// \note Just a template declaration! must be specialized
template<unsigned id> struct message_t;

/// Used to indicate a member suitable as template type parameter
template<typename T, T MemberPtr> struct Member {};

/// Used to specify packs of types
template<typename... Members> struct Pack {};

/// Template to be specialized with a \c Pack of members
/// \note Just a declaration! must be specialized
template<typename T> struct Members;

/// Template to be specialized with identifiers member of enumerations
/// \note Just a declaration! must be specialized
template<typename T> struct Identifiers;

/// All repeating groups will be specializations of \c RepeatingGroup
///
/// Repeating groups will have a type \c dimension to indicate the controller
/// \note Just a declaration! must be specialized
template<unsigned MessageId, unsigned Index> struct group_element_t;

template<typename T> struct message_id_trait;
template<unsigned Id> struct message_id_trait<message_t<Id>> {
    constexpr static unsigned value = Id;
};

}
