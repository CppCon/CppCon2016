#pragma once

// Copyright Crabel Capital Management 2016
// All rights reserved


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
