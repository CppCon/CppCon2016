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



// generated with code_generator/templates2Cpp.plx

namespace mdp3 {

using Asset = char[6]; ///< Asset
// has semantic type String
using CFICode = char[6];
// has semantic type String
using CHAR = char; ///< char
using Currency = char[3]; ///< Currency
// has semantic type Currency
using InstAttribType = int8_t;
using Int16 = int16_t; ///< int16
using Int32 = int32_t; ///< int32
using Int32NULL = optional<int32_t, 2147483647>;
using Int8 = int8_t; ///< int8
using Int8NULL = optional<int8_t, 127>;
using LocalMktDate = optional<uint16_t, 65535>;
using MDEntryTypeChannelReset = char;
using MDEntryTypeLimits = char;
using MDEntryTypeTrade = char;
using MDEntryTypeVol = char;
using MDFeedType = char[3];
// has semantic type String
using MDUpdateActionNew = int8_t;
using MDUpdateTypeNew = int8_t;
using QuoteReqId = char[23];
// has semantic type String
using SecurityExchange = char[4];
// has semantic type Exchange
using SecurityGroup = char[6];
// has semantic type String
using SecurityIDSource = char;
using SecuritySubType = char[5];
// has semantic type String
using SecurityType = char[6]; ///< SecurityType
// has semantic type String
using Symbol = char[20]; ///< Symbol
// has semantic type String
using Text = char[180]; ///< Text
// has semantic type String
using UnderlyingSymbol = char[20];
// has semantic type String
using UnitOfMeasure = char[30];
// has semantic type String
using UserDefinedInstrument = char;
// has semantic type char
using uInt32 = uint32_t; ///< uInt32
using uInt32NULL = optional<uint32_t, 4294967295>;
using uInt64 = uint64_t; ///< uInt64
using uInt8 = uint8_t; ///< uInt8
using uInt8NULL = optional<uint8_t, 255>;

/// A number representing quantity
/// \note semantic type Qty
struct DecimalQty {
    optional<int32_t, 2147483647> mantissa; ///< mantissa  
    constexpr static int8_t exponent = -4; ///< exponent 
} EXACT_LAYOUT;

/// Decimal
struct FLOAT {
    int64_t mantissa; ///< mantissa
    constexpr static int8_t exponent = -7; ///< exponent 
} EXACT_LAYOUT;

/// Year, Month and Date
/// \note semantic type MonthYear
struct MaturityMonthYear {
    optional<uint16_t, 65535> year; ///< YYYY 
    optional<uint8_t, 255> month; ///< MM 
    optional<uint8_t, 255> day; ///< DD 
    optional<uint8_t, 255> week; ///< WW 
} EXACT_LAYOUT;

template<> struct Members<MaturityMonthYear> {
    using type = Pack<
        Member<decltype(&MaturityMonthYear::year), &MaturityMonthYear::year>,
        Member<decltype(&MaturityMonthYear::month), &MaturityMonthYear::month>,
        Member<decltype(&MaturityMonthYear::day), &MaturityMonthYear::day>,
        Member<decltype(&MaturityMonthYear::week), &MaturityMonthYear::week>
    >;
    static const char **names() {
        static const char *rv[] = { "year", "month", "day", "week" };
        return rv;
    }
    static const char *name() { return "MaturityMonthYear"; }
};

}

namespace mdp3 {

template<typename...> struct voider { using type = void; };
template<typename... Pack> using void_t = typename voider<Pack...>::type;

/// Implementation detail of a meta tool to convert \c true into a SFINAE type
template<bool> struct TrueImpl {};
/// Specialization: if argument is true, member type exists
template<> struct TrueImpl<true> { using type = void; };
/// Meta tool to convert true into a SFINAE type
template<bool b> using True = typename TrueImpl<b>::type;

}

#include <type_traits>

namespace mdp3 { namespace meta {

/// User-facing API to drive detection of null values
///
/// Drives the implementation overloads through a type-token parameter
/// \note user code is allowed to further overload this
template<typename T> inline constexpr bool is_null(const T &v);

/// Captures the pattern of \c T being an optional
template<typename T, T NullValue> inline constexpr bool
is_null(optional<T, NullValue> v)
    { return NullValue == v; }

namespace detail {

/// Implementation of is_null
/// 
/// \tparam T unrestricted type, used when all the other overloads fail
/// \param v any value
/// \param ... variable arguments to make this the overload of last resort
/// \return false
/// \note User code is allowed to overload is_null_impl
    template<typename T> constexpr inline bool
is_null_impl(T v, ...) { return false; }

/// Captures the pattern of \c T being an enumeration and have null_value
    template<typename T> constexpr inline bool
is_null_impl(T v, void_t<True<std::is_enum<T>::value>, decltype(T::null_value)> *)
    { return T::null_value == v; }

/// Captures the pattern of \c T being an union with a field NullValue
template<typename T> constexpr inline bool
is_null_impl(T v, void_t<True<std::is_union<T>::value>, decltype(T::NullValue)> *)
    { return v.NullValue; }

template<typename A> inline constexpr bool
packIsNull(const A &, Pack<> *) { return true; }

/// Captures a non-empty \c Pack pattern
template<typename A, typename T, T MemberPtr, typename... Tail>
inline constexpr bool
packIsNull(const A &agg, Pack<Member<T, MemberPtr>, Tail...> *);

/// Captures the pattern of there being an specialization of \c Members for \c T
template<typename T> constexpr inline bool
is_null_impl(const T &v, void_t<typename Members<T>::type> *) {
    return packIsNull(v, (typename Members<T>::type *)nullptr);
}

template<typename A, typename T, T MemberPtr, typename... Tail>
inline constexpr bool
packIsNull(const A &agg, Pack<Member<T, MemberPtr>, Tail...> *) {
    return
        is_null(agg.*MemberPtr) && packIsNull(agg, (Pack<Tail...> *)nullptr);
}

}

template<typename T> inline constexpr bool is_null(const T &v)
{ return detail::is_null_impl(v, (void *)nullptr); }

}}

bool meta_test(const mdp3::MaturityMonthYear &m) {
    return mdp3::meta::is_null(m);
}
