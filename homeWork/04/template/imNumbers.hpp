#pragma once 

#include <cmath>
#include <iostream>
using namespace std;

#define EPS 1e-10

/*
Необходимо реализовать шаблонный класс ImNumber - комплексное число


Функциональность смотреть в домашнем задании 3!!!!
Перегрузить операторы 
'+', '-', '/', '*', '+=', '-=', '*=', '/=', '!'(сопряженное), '()' - взятие модуля числа,
'=', '==', '<' (по модулю), '<<' - оператор вывода (например 2+i3)

Реализовать функцию
const double phi() - наименьший положительный угол покательной формы комплекного числа
ImNumber(); - инициализация нулями
ImNumber(T real, T im);


10 баллов
Перед сдачей необходимо создать pull reequest(назвать ветку своей фамилией), чтобы пройти тесты.

Дата последней сдачи 30.10.23 включительно
*/
template <typename T> class ImNumber{
public:
    T real;
    T im;
    ImNumber<T>(){this->real = 0; this->im = 0;};
    ImNumber<T>(T real, T im){this->real = real; this->im = im;};
    bool operator==(const ImNumber<T>& num)const;
    bool operator<(const ImNumber<T>& num)const;
    ImNumber<T> operator+(const ImNumber<T>& num)const;
    ImNumber<T> operator-(const ImNumber<T>& num)const;
    ImNumber<T> operator/(const ImNumber<T>& num)const;
    ImNumber<T> operator*(const ImNumber<T>& num)const;
    ImNumber<T>& operator+=(const ImNumber<T>& num);
    ImNumber<T>& operator-=(const ImNumber<T>& num);
    ImNumber<T>& operator/=(const ImNumber<T>& num);
    ImNumber<T>& operator*=(const ImNumber<T>& num);
    ImNumber<T> operator!()const;
    T operator()()const;
    const T phi()const;
};
template <typename T> decltype(auto) operator<<(std::ostream& stream, const ImNumber<T> num) {
    stream << num.real;
    num.im > 0 ? stream << "+i" << num.im : stream << "-i" << fabs(num.im);
    return stream;
}
template <typename T>
ImNumber<T> ImNumber<T>::operator+(const ImNumber<T>& num)const {
    return ImNumber<T>(real + num.real, im + num.im);
}
template <typename T>
ImNumber<T> ImNumber<T>::operator-(const ImNumber<T>& num)const {
    return ImNumber<T>(real - num.real, im - num.im);
}
template <typename T>
ImNumber<T> ImNumber<T>::operator/(const ImNumber<T>& num)const {
    return ImNumber<T>((real*num.real + im*num.im)/(pow(num.real,2) + pow(num.im,2)), (num.real*im - real*num.im)/(pow(num.real,2) + pow(num.im,2)));
}
template <typename T>
ImNumber<T> ImNumber<T>::operator*(const ImNumber<T>& num)const {
    return ImNumber<T>(real * num.real - im * num.im, real * num.im + num.real * im);
}
template <typename T>
ImNumber<T>& ImNumber<T>::operator+=(const ImNumber<T>& num) {
    real += num.real;
    im += num.im;
    return *this;
}
template <typename T>
ImNumber<T>& ImNumber<T>::operator-=(const ImNumber<T>& num) {
    real -= num.real;
    im -= num.im;
    return *this;
}
template <typename T>
ImNumber<T>& ImNumber<T>::operator/=(const ImNumber<T>& num) {
    double realt = real, imt = im;
    real = (realt*num.real + imt*num.im)/(pow(num.real,2) + pow(num.im,2));
    im = (num.real*imt - realt*num.im)/(pow(num.real,2) + pow(num.im,2));
    return *this;
}
template <typename T>
ImNumber<T>& ImNumber<T>::operator*=(const ImNumber<T>& num) {
    double realt = real, imt = im;
    real = realt * num.real - imt * num.im;
    im =  realt * num.im + num.real * imt;
    return *this;
}
template <typename T>
ImNumber<T> ImNumber<T>::operator!()const {
    return ImNumber<T>(real, -im);
}
template <typename T>
T ImNumber<T>::operator()()const {
    return sqrt(pow(real,2) + pow(im,2));
}
template <typename T>
bool ImNumber<T>::operator==(const ImNumber<T>& num)const {
    return fabs(real - num.real) < EPS && fabs(im - num.im) < EPS;
}
template <typename T>
bool ImNumber<T>::operator<(const ImNumber<T>& num)const {
    ImNumber<T> t(real, im);
    return t() < num();
}
template <typename T>
const T ImNumber<T>::phi()const {
    return atan2(im, real);
}