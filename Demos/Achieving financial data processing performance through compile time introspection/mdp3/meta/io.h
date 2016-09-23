#pragma once

// Copyright Crabel Capital Management 2016
// All rights reserved

#include "../price.h"
#include "./is_null.h"
#include "./repeating_group.h"

#include <ostream>

namespace mdp3 { namespace meta {

/// The default implementation of the type to print is the type itself
template<typename T> struct StreamableChar { using type = T; };
/// For unsigned chars will print unsigned instead
template<> struct StreamableChar<unsigned char> { using type = unsigned; };
/// For signed chars will print integer instead
template<> struct StreamableChar<signed char> { using type = int; };

/// User interface alias
template<typename T> using Streamable = typename StreamableChar<T>::type;

/// Trait implementation of how to convert a value into a streamable
template<typename T, typename = void> struct StreamableTraitImpl {
    using type = Streamable<T>;
    static constexpr type convert(T v) { return v; }
};
/// For enumerations, print the underlying
template<typename T> struct StreamableTraitImpl<T, void_t<True<std::is_enum<T>::value>>> {
    using type = Streamable<typename std::underlying_type<T>::type>;
    static constexpr type convert(T v) { return type(v); }
};

/// For unions, print the code
template<typename T> struct StreamableTraitImpl<T, void_t<True<std::is_union<T>::value>>> {
    using type = Streamable<decltype(T::code)>;
    static constexpr type convert(T v) { return v.code; };
};
/// User interface for the trait that converts the values into streamables
template<typename T> using StreamableTrait = typename StreamableTraitImpl<T>::type;

template<typename T> constexpr inline StreamableTrait<T> 
streamable(T v) { return StreamableTraitImpl<T>::convert(v); }

template<typename T, T NullValue> constexpr inline StreamableTrait<T>
streamable(optional<T, NullValue> v) { return streamable(T(v)); }

template<unsigned Length> inline std::string
streamable(const char (&arg)[Length]) { return std::string(arg, arg + Length).c_str(); }

inline double streamable(PRICENULL pn) { return price(pn); }
inline double streamable(PRICE p) { return price(p); }
inline std::string streamable(MatchEventIndicator mei) {
    std::string rv("TVQSIRE");
    if(!mei.LastTradeMsg) { rv[0] = '-'; }
    if(!mei.LastVolumeMsg) { rv[1] = '-'; }
    if(!mei.LastQuoteMsg) { rv[2] = '-'; }
    if(!mei.LastStatsMsg) { rv[3] = '-'; }
    if(!mei.LastImpliedMsg) { rv[4] = '-'; }
    if(!mei.RecoveryMsg) { rv[5] = '-'; }
    if(!mei.EndOfEvent) { rv[6] = '-'; }
    return rv;
}

template<typename T> std::ostream &to_stream_weak(std::ostream &out, const T &v);
inline std::ostream &to_stream_weak(std::ostream &out, signed char v) { return out << int(v); }
inline std::ostream &to_stream_weak(std::ostream &out, unsigned char v) { return out << unsigned(v); }
inline std::ostream &to_stream_weak(std::ostream &out, PRICENULL pn) { return out << streamable(pn); }
inline std::ostream &to_stream_weak(std::ostream &out, PRICE p) { return out << streamable(p); }
template<typename T, T NullValue> std::ostream &to_stream_weak(std::ostream &out, const optional<T, NullValue> &v) {
    if(is_null(v)) { return out; }
    return to_stream_weak(out, v.value);
}

namespace detail {

template<typename A> inline std::ostream &
to_stream_pack(std::ostream &out, const A &v, const char **names, Pack<> *) { return out; }
template<typename A, typename T, T MPtr, typename... Tail> inline std::ostream &
to_stream_pack(std::ostream &out, const A &v, const char **names, Pack<Member<T, MPtr>, Tail...> *);


template<unsigned MId, unsigned Ndx> std::ostream &to_stream_weak_group(std::ostream &out, const message_t<MId> &m, ...) { return out; }
template<unsigned MId, unsigned Ndx> std::ostream &to_stream_weak_group(std::ostream &out, const message_t<MId> &m, void_t<typename group_element_t<MId, Ndx>::dimension> *) {
    out << '#' << Ndx;
    auto v = const_cast<message_t<MId> *>(&m);
    auto flyw = repeating_group_by_indices<Ndx>(*v);
    out << ':' << flyw.size() << '[';
    for(auto &e: flyw) {
        to_stream_weak(out, e);
    }
    out << ']';
    return to_stream_weak_group<MId, 1 + Ndx>(out, m, (void *)nullptr);
}

template<typename T> std::ostream &to_stream_default(std::ostream &out, const T &v) { return out << streamable(v); }
template<typename T> std::ostream &to_stream_weak_impl(std::ostream &out, const T &v, ...) { return to_stream_default(out, v); }

template<typename T> std::ostream &to_stream_weak_members(std::ostream &out, const T &v) {
    if(is_null(v)) { return out; }
    using MemberSpecialization = Members<T>;
    out << '(' << MemberSpecialization::name() << ':';
    return to_stream_pack(out, v, MemberSpecialization::names(), (typename MemberSpecialization::type *)nullptr) << ')';
}
template<typename T> std::ostream &to_stream_weak_impl(std::ostream &out, const T &v, void_t<typename Members<T>::type> *) { return to_stream_weak_members(out, v); }

template<unsigned MId> std::ostream &to_stream_weak_message(std::ostream &out, const message_t<MId> &m) {
    using MemberSpecialization = Members<message_t<MId>>;
    out << "message<" << MemberSpecialization::name() << ':' << MId << ">{";
    to_stream_weak_members(out, m);
    return to_stream_weak_group<MId, 0>(out, m, (void *)nullptr) << '}' << std::endl;
}
template<unsigned MId> std::ostream &to_stream_weak_impl(std::ostream &out, const message_t<MId> &m, void_t<typename Members<message_t<MId>>::type> *) { return to_stream_weak_message(out, m); }

template<typename A, typename T, T MPtr, typename... Tail> inline std::ostream &
to_stream_pack(std::ostream &out, const A &v, const char **names, Pack<Member<T, MPtr>, Tail...> *) {
    if(!is_null(v.*MPtr)) { to_stream_weak(out << '(' << *names << ':', v.*MPtr) << ')'; }
    return to_stream_pack(out, v, names + 1, (Pack<Tail...> *)nullptr);
}

}

template<typename T> std::ostream &to_stream_weak(std::ostream &out, const T &v) {
    return detail::to_stream_weak_impl(out, v, (void *)nullptr);
}

template<unsigned L> std::string characters_to_string(const char (&chars)[L]) {
    return std::string(chars, chars + L).c_str();
}

}}
