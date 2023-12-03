#pragma once 
#include <cstdint>
#include <iostream>
/*
Необходимо реализовать класс CStack - стэк элементов uint32_t с помощью односвязного списка (node)

пример работы стандартной реализации методов
https://en.cppreference.com/w/cpp/container/stack

Особенности вашей реализации в том, что
1) если в стеке элементов нет, то метод pop ничего не делает(не выбрасывает ошибки)
2) логику деструктора (освободить все использованные ресурсы) реализовать в функции clear()!

Добавить самостоятельно и реализовать для класса CStack операторы:
1) "*=" - умножает каждый все элементы стека(именно поле info в node) на число
    Пример:
        Cstack c;
        c.push(1);
        c.push(2);
        c.push(3);
        c*=3;
    Итог:   
        Элементы в стеке c=={9,6,3}
2) "=" - копирует стек в другой объект стека без уничтожения
    Пример:
        Cstack c,c1;
        c.push(1);
        c.push(2);
        c.push(3);
        c1 = c;
    Итог:   
        Элементы в стеке c1=={3,2,1}
3) "[]" - возвращает  элемент(именно поле info в node) стека под определенным номером.
    Пример:
        Cstack c;
        c.push(1);
        c.push(2);
        c.push(3);
        uint32_t a = c[1];
    Итог: 
        a==2

Реализовать operator< для структуры node
    Пример:
        Node n,n1;
        n.info = 1;
        n1.info = 2;
        if (n1 < n2)
            std::cout << "Congratulations!";
        else
            std::cout << "Commiserations!";
    Итог: 
        Вывод Congratulations!


10 баллов
Перед сдачей необходимо создать pull reequest(назвать ветку своей фамилией), чтобы пройти тесты.

Дата последней сдачи 13.10.23
Следующие домашки будут чаще!
*/


struct Node
{
    uint32_t info;
    Node* next = nullptr;
    bool operator<(const Node& node);
};


class CStack{
    Node* ptop = nullptr;
    void clear();
public:
    CStack();
    ~CStack(); //clears all memory  
    void pop(); //	removes the top element
    void push(uint32_t val); //inserts element at the top
    uint32_t top(); //accesses the top element
    bool empty(); //checks whether the underlying container is empty
    void printStack();
    CStack& operator*=(int multi);
    CStack& operator=(const CStack& cstack);
    int operator[](int ind);
    // void swap(CStack & other);
};