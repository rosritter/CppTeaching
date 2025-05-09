#pragma once

template <int N>
constexpr int fibonacci() {
    return fibonacci<N-1>() + fibonacci<N-2>();
}

template <>
constexpr int fibonacci<0>() {
    return 0;
}

template <>
constexpr int fibonacci<1>() {
    return 1;
}

template <int N>
struct Fibonacci {
    static constexpr int value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
};

template <>
struct Fibonacci<0> {
    static constexpr int value = 0;
};

template <>
struct Fibonacci<1> {
    static constexpr int value = 1;
};

