#include "imNumbers.hpp"
#include "cstack.hpp"
#include <iostream>

using namespace std;

int main() {
    CStack<int> cstack;
    for (int i = 1; i <= 5; i++) {
        cstack.push(i);
    }
    
    std::cout << "Top of the stack: " << cstack.top() << std::endl;
    
    cstack *= 2;
    
    std::cout << "Stack elements: ";
    for (size_t i = 0; i < 5; i++) {
        std::cout << cstack[i] << " ";
    }
    std::cout << std::endl;
    
    cstack.pop();
    std::cout << "Stack elements after pop: ";
    for (size_t i = 0; i < 4; i++) {
        std::cout << cstack[i] << " ";
    }
    std::cout << std::endl;

    ImNumber<float> n1(1, 2);
    ImNumber<float> n2(3, 4);
    
    ImNumber<float> sum = n1 + n2;
    ImNumber<float> product = n1 * n2;
    
    std::cout << "n1: " << n1 << std::endl;
    std::cout << "n2: " << n2 << std::endl;
    std::cout << "n1 + n2: " << sum << std::endl;
    std::cout << "n1 * n2: " << product << std::endl;

    return 0;
}