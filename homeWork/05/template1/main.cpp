#include "template.hpp"
#include <iostream>

using namespace std;

int main(){
    constexpr int fibFuncResult1 = fibonacci<4>();   // 3 (0, 1, 1, 2, 3)
    constexpr int fibFuncResult2 = fibonacci<6>();   // 8
    constexpr int fibFuncResult3 = fibonacci<10>();  // 55
    

    constexpr int fibClassResult1 = Fibonacci<4>::value;    // 3
    constexpr int fibClassResult2 = Fibonacci<6>::value;    // 8
    constexpr int fibClassResult3 = Fibonacci<10>::value;   // 55

    std::cout << "fibonacci<4>() = " << fibFuncResult1 << std::endl;
    std::cout << "fibonacci<6>() = " << fibFuncResult2 << std::endl;
    std::cout << "fibonacci<10>() = " << fibFuncResult3 << std::endl;
    std::cout << "Fibonacci<4>::value = " << fibClassResult1 << std::endl;
    std::cout << "Fibonacci<6>::value = " << fibClassResult2 << std::endl;
    std::cout << "Fibonacci<10>::value = " << fibClassResult3 << std::endl;
    
    return 0;
}