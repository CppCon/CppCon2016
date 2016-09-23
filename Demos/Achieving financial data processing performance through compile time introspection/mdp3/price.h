#pragma once

// Copyright Crabel Capital Management 2016
// All rights reserved

#include "mdp3.h"

namespace mdp3 {

constexpr long constexpr_abs(long arg) { return arg < 0 ? -arg : arg; }
constexpr long constexpr_pow10(unsigned exp) {
    return exp ? 10 * constexpr_pow10(exp - 1) : 1;
}

/// Note: workaround to overcome GCC's up to 5.3 bad optimizing is to capture
/// the power into a constexpr
template<typename T> double priceTemplate(T v) {
    constexpr bool divide = T::exponent < 0;
    constexpr long power = constexpr_pow10(constexpr_abs(T::exponent));
    return divide ? double(v.mantissa)/power : double(v.mantissa) * power;
}

inline double price(PRICE p) { return priceTemplate(p); }
inline double price(PRICENULL pn) { return priceTemplate(pn); }
inline double price(FLOAT f) { return priceTemplate(f); }

}
