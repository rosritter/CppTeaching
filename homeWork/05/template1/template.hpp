#pragma once 
#include <cmath>
#define EPS 1e-10

/*
Необходимо реализовать подсчет чисел фибоначчи с помощью шаблонного класса и функции во время компиляции

Поле класса, в котором хранится ответ value


Эталонная функция

int fibonacci(int x) {
   if((x==1)||(x==0)) {
      return(x);
   }else {
      return(fib(x-1)+fib(x-2));
   }
}

Пример подсчета для функции
fibonacci<4>()

Пример подсчета для класса
Fibonacci<4>::value

10 баллов
Перед сдачей необходимо создать pull reequest(назвать ветку своей фамилией), чтобы пройти тесты.

Дата последней сдачи 6.10.23 включительно
*/
template <int T> constexpr auto fibonacci() -> decltype(T){ 
   return fibonacci<T-1>()+fibonacci<T-2>();
}

template <> constexpr auto fibonacci<0>() -> int {return 0;}

template <> constexpr auto fibonacci<1>() -> int {return 1;}

template <int T>
class Fibonacci;

template <>
class Fibonacci<0> {
public:
   static constexpr int value = 0;
};

template <>
class Fibonacci<1> {
public:
   static constexpr int value = 1;
};

template <int T>
class Fibonacci{
public:
   static constexpr int value = Fibonacci<T-1>::value + Fibonacci<T-2>::value;
};