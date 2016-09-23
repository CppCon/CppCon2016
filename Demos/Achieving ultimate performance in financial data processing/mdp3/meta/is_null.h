#pragma once

// Copyright Crabel Capital Management 2016
// All rights reserved

#include "../mdp3.h"
#include "void_t.h"

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
