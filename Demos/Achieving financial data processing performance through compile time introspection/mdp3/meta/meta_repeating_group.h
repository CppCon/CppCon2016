#pragma once

// Copyright Crabel Capital Management 2016
// All rights reserved

#include "./repeating_group.h"
#include "./void_t.h"

#include <type_traits>

namespace mdp3 {

template<unsigned MId, typename = void>
struct HasGroups_impl: std::false_type {};
template<unsigned MId>
struct HasGroups_impl<MId, void_t<group_element_t<MId, 0>>>: std::true_type {};
template<typename M> using HasGroups = HasGroups_impl<IdDeducer<M>::value>;
    
template<unsigned MId, unsigned Ndx, typename = void>
struct HasNext_impl: std::false_type {};
template<unsigned MId, unsigned Ndx>
struct HasNext_impl<MId, Ndx, void_t<group_element_t<MId, Ndx + 1>>>:
    std::true_type
{};


template<unsigned MId>
Flyweight<group_element_t<MId, 0>> first_group(message_t<MId> &m) {
    return repeating_group_by_indices<0>(m);
}

}
