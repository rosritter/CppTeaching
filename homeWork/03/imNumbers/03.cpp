// 03.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "imNumbers.hpp"
#include <iostream>
#include "imNumbers.cpp"

int main() {
    setlocale(LC_ALL, "Russian");
    ImNumber a(2, 3);
    ImNumber b(4, 5);

    ImNumber sum = a + b;
    std::cout << "a + b = " << sum << std::endl;

    ImNumber diff = a - b;
    std::cout << "a - b = " << diff << std::endl;

    ImNumber pr = a * b;
    std::cout << "a * b = " << pr << std::endl;

    ImNumber dell = a / b;
    std::cout << "a / b = " << dell << std::endl;

    a += b;
    std::cout << "a += b: a = " << a << std::endl;

    a -= b;
    std::cout << "a -= b: a = " << a << std::endl;

    a *= b;
    std::cout << "a *= b: a = " << a << std::endl;

    a /= b;
    std::cout << "a /= b: a = " << a << std::endl;

    ImNumber sopr= !a;
    std::cout << "Сопряженное: " << sopr<< std::endl;

    double modulus = a();
    std::cout << "Модуль: " << modulus << std::endl;

    if (a == b)
        std::cout << "a = b" << std::endl;
    else
        std::cout << "a != b" << std::endl;

    if (a < b)
        std::cout << "a меньше b" << std::endl;
    else
        std::cout << "a не меньше b" << std::endl;

    double angle = a.phi();
    std::cout << "наименьший положительный угол покательной формы комплекного числа: " << angle << std::endl;

    return 0;
}

