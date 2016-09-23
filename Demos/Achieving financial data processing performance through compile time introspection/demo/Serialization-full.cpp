template<typename> struct Members {}; ///< Specializations have "type" member

/// Relates a member pointer to an index
template<typename T, T mPtr, unsigned Index>
struct MemberBinding {
    constexpr static T value = mPtr;
    constexpr static unsigned index = Index;
};

template<typename...> struct Pack {};

template<typename...> using void_t = void;

/// vvvv generated with code generator vvvv
#include <string>

struct SubAg {
    double value;
};

template<> struct Members<SubAg> {
    using type = Pack<
        MemberBinding<decltype(&SubAg::value), &SubAg::value, 0>
    >;
    constexpr static const char *name = "SubAg";
    static const char *const *names() {
        static const char *rv[] = { "value" };
        return rv;
    }
};

struct Aggregate {
    int member1;
    SubAg sa;
    std::string member2;
};

template<> struct Members<Aggregate> {
    using type = Pack<
        MemberBinding<decltype(&Aggregate::member1), &Aggregate::member1, 0>,
        MemberBinding<decltype(&Aggregate::sa), &Aggregate::sa, 1>,
        MemberBinding<decltype(&Aggregate::member2), &Aggregate::member2, 2>
    >;
    constexpr static const char *name = "Aggregate";
    static const char *const *names() {
        static const char *rv[] = { "member1", "sa", "member2" };
        return rv;
    }
};
// ^^^^ generated with code generator ^^^^

// vvvv Introspection library code vvvv
#include <sstream>

/// Overload for T where there is a Members<T> specialization
template<typename T>
void to_str_impl(
    std::ostream &out,
    const T &v,
    void_t<typename Members<T>::type> *
);
/// Less specific overload
template<typename T>
void to_str_impl(
    std::ostream &out,
    const T &v,
    ...
) {
    out << v;
}

/// General case
template<typename A, typename MT, MT MPTR, unsigned Ndx, typename... Rest>
void printPack(
    std::ostream &out,
    const A &v,
    Pack<MemberBinding<MT, MPTR, Ndx>, Rest...> *
) {
    using M = Members<A>;
    out << ' ' << Ndx << ':' << M::names()[Ndx] << ':';
    to_str_impl(out, v.*MPTR, (void *)nullptr);
    printPack(out, v, (Pack<Rest...> *)nullptr);
}
/// Recursion end case
template<typename A>
void printPack(std::ostream &out, const A &v, Pack<> *) {}


template<typename T>
void to_str_impl(
    std::ostream &out, const T &v, void_t<typename Members<T>::type> *
) {
    using M = Members<T>;
    out << '(' << M::name;
    printPack(out, v, (typename M::type *)nullptr);
    out << ')';
}

template<typename T> std::string to_str(const T &v) {
    std::ostringstream prv;
    to_str_impl(prv, v, (void *)nullptr);
    return prv.str();
}
/// ^^^^ Introspection library code ^^^^

// vvvv User code vvvv
std::string fun(Aggregate &a) { return to_str(a); }

#include <iostream>

int main(int argc, const char *argv[]) {
    Aggregate a{ 5, { 3.14 }, "Bellevue" };
    std::cout << to_str(a) << std::endl;
    return 0;
}
