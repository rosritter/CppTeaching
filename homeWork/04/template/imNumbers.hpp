#pragma once 
#include <cmath>
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

class ImNumber{
    T real;
    T im;
    ImNumber(){};
    ImNumber(T real, T im);
    bool operator=(const ImNumber& num)const;
    const double phi();
};

bool ImNumber<T>::operator=(const ImNumber<T>& num)const{
    return fabs(real - num.real) < EPS && fabs(im - num.im) < EPS;
}