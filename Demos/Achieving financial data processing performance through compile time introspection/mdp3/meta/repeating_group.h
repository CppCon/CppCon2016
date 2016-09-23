#pragma once

// Copyright Crabel Capital Management 2016
// All rights reserved

#include "../mdp3.h"

namespace mdp3 { namespace meta {

template<unsigned MId, unsigned Ndx> using dimension_t =
    typename group_element_t<MId, Ndx>::dimension;

template<typename T> struct GroupDeducer;
template<unsigned MId, unsigned Ndx>
struct GroupDeducer<group_element_t<MId, Ndx>> {
    constexpr static unsigned MessageId = MId;
    constexpr static unsigned Index = Ndx;
};

template<typename> struct IdDeducer;
template<unsigned MId> struct IdDeducer<message_t<MId>>
{ constexpr static unsigned value = MId; };

template<typename T> using Flyweight = flyweight<T, typename T::dimension>;

template<unsigned MId, unsigned Ndx> struct RepeatingGroup {
    using type = Flyweight<group_element_t<MId, Ndx>>;
    constexpr static type group(message_t<MId> &m) {
        return type(RepeatingGroup<MId, Ndx - 1>::group(m).end());
    }
};
template<unsigned MId> struct RepeatingGroup<MId, 0> {
    using type = Flyweight<group_element_t<MId, 0>>;
    constexpr static type group(message_t<MId> &m) {
        return type(&m + 1);
    }
};

template<unsigned Ndx, unsigned MId>
constexpr Flyweight<group_element_t<MId, Ndx>>
repeating_group_by_indices(message_t<MId> &message) {
    return RepeatingGroup<MId, Ndx>::group(message);
}

template<typename T>
constexpr Flyweight<T>
repeating_group(message_t<GroupDeducer<T>::MessageId> &message) {
    return repeating_group_by_indices<GroupDeducer<T>::Index>(message);
}

template<typename> struct NextGroup;
template<unsigned MId, unsigned Ndx>
struct NextGroup<Flyweight<group_element_t<MId, Ndx>>> {
    using type = Flyweight<group_element_t<MId, Ndx + 1>>;
};

template<typename G>
constexpr typename NextGroup<G>::type next_group(G &g) {
    return typename NextGroup<G>::type(g.end());
}

}}
