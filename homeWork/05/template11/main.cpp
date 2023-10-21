#include "template.hpp"
#include <iostream>
#include "template.hpp"

using namespace std;

int main() {
    constexpr int result1 = fibonacci<4>();
    constexpr int result2 = Fibonacci<4>::value;

    std::cout << "fibonacci<4>() = " << result1 << std::endl;
    std::cout << "Fibonacci<4>::value = " << result2 << std::endl;

    return 0;
}