#pragma once 
#include <cmath>
#include <complex>
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
class ImNumber
{
public:
    double real;
    double im;

    ImNumber() : real(0.0), im(0.0) {}
    ImNumber(double real, double im) : real(real), im(im) {}

    ImNumber operator+(const ImNumber& other) const {
        return ImNumber(real + other.real, im + other.im);
    }

    ImNumber operator-(const ImNumber& other) const {
        return ImNumber(real - other.real, im - other.im);
    }

    ImNumber operator*(const ImNumber& other) const {
        return ImNumber(real * other.real - im * other.im, real * other.im + im * other.real);
    }

    ImNumber operator/(const ImNumber& other) const {
        double denominator = other.real * other.real + other.im * other.im;
        return ImNumber((real * other.real + im * other.im) / denominator,
            (im * other.real - real * other.im) / denominator);
    }

    ImNumber& operator+=(const ImNumber& other) {
        real += other.real;
        im += other.im;
        return *this;
    }

    ImNumber& operator-=(const ImNumber& other) {
        real -= other.real;
        im -= other.im;
        return *this;
    }

    ImNumber& operator*=(const ImNumber& other) {
        double tmpReal = real;
        real = real * other.real - im * other.im;
        im = tmpReal * other.im + im * other.real;
        return *this;
    }

    ImNumber& operator/=(const ImNumber& other) {
        double denominator = other.real * other.real + other.im * other.im;
        double tmpReal = real;
        real = (real * other.real + im * other.im) / denominator;
        im = (im * other.real - tmpReal * other.im) / denominator;
        return *this;
    }

    ImNumber operator!() const {
        return ImNumber(real, -im);
    }

    double operator()() const {
        return std::sqrt(real * real + im * im);
    }

    bool operator==(const ImNumber& other) const {
        return (real == other.real) && (im == other.im);
    }

    bool operator<(const ImNumber& other) const {
        return ((*this)() < other());
    }

    friend std::ostream& operator<<(std::ostream& os, const ImNumber& num) {
        if (num.im > 0)
            os << num.real << '+' << 'i' << num.im;
        else
            os << num.real << '-' << 'i' <<  fabs(num.im);
        return os;
    }

    double phi() const {
        return std::arg(std::complex<double>(real, im));
    }
};
