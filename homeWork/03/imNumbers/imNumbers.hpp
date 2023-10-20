#pragma once 
#include <cmath>
#define EPS 1e-10

/*
Необходимо реализовать класс ImNumber - комплексное число
Перегрузить операторы 
'+', '-', '/', '*', '+=', '-=', '*=', '/=', '!'(сопряженное), '()' - взятие модуля числа,
'=', '==', '<' (по модулю), '<<' - оператор вывода (например 2+i3)

Реализовать функцию
const double phi() - наименьший положительный угол покательной формы комплекного числа
ImNumber(); - инициализация нулями
ImNumber(double real, double im);


10 баллов
Перед сдачей необходимо создать pull reequest(назвать ветку своей фамилией), чтобы пройти тесты.

Дата последней сдачи 20.10.23 включительно
*/


class ImNumber{

public:
    
    double real;
    double im;

    ImNumber(double real = 0.0, double im = 0.0) : real(real), im(im) {}
    friend std::ostream& operator<<(std::ostream& os, const ImNumber& complex);
    friend ImNumber operator!(const ImNumber& c)
    {
        return ImNumber(c.real, -c.im);
    };

    bool operator=(const ImNumber& num)const;
    double operator()() const;
    bool operator==(const ImNumber& operand2) const;
    ImNumber operator+(const ImNumber& rhs)const;
    ImNumber operator-(const ImNumber& rhs)const;
    ImNumber operator*(const ImNumber& rhs) const;
    ImNumber operator/(const ImNumber& other)const;
    ImNumber operator+=(const ImNumber& other);
    ImNumber operator-=(const ImNumber& other);
    ImNumber operator*=(const ImNumber& other);
    ImNumber operator/=(const ImNumber& rhs);

    //const double phi();
};