#pragma once
#include <cstdint>

/*
Необходимо реализовать шаблонные классы node<T> и CStack<T> - стэк элементов T с помощью односвязного списка (node)


Функциональность такая же, как и во второй домашке!


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

Дата последней сдачи 30.10.23
*/

template <typename T>
struct Node
{
    T info;
    Node<T>* next = nullptr;
    bool operator< (Node<T> n_2) {
        return info < n_2.info;
    }
    Node<T>() {}
    Node<T>(T value) : info(value){}
};

template <typename T>
class CStack{
    Node<T>* first = nullptr;
    Node<T>* last = nullptr; //ptop
    void clear();
public:
    CStack();
    ~CStack(); //clears all memory  
    void pop(); //	removes the top element
    void push(T val); //inserts element at the top
    T top(); //accesses the top element
    bool empty(); //checks whether the underlying container is empty
    void operator *= (T value) {
        Node<T>* nd = first;
        while (nd) {
            nd->info *= value;
            nd = nd->next;
        }
    }
    void operator = (CStack<T>& copy) {
        Node<T>* nd = copy.first;
        while (nd) {
            this->push(nd->info);
            nd = nd->next;
        }
    }
    T& operator [] (int n) {
        Node<T>* nd = first;
        for (int i = 0; i < n; i++) {
            nd = nd->next;
        }
        return nd->info;
    }
};

template <typename T>
CStack<T>::~CStack() {
    clear();
}

template <typename T>
CStack<T>::CStack() {}

template <typename T>
void CStack<T>::pop(){
    if (empty()) return;
    Node<T>* nd = first;
    if (first != last) {
        while (nd->next != last) 
            nd = nd->next;
        nd->next = nullptr;
        delete last;
        last = nd;
    } else {
        delete first;
        first = nullptr;
    }
}
template <typename T>
void CStack<T>::push(T val){
    Node<T>* new_Node = new Node<T>(val);
    if (empty()) {
        first = new_Node;
        last = first;
        return;
    }
    last->next = new_Node;
    last = new_Node;
}
template <typename T>
T CStack<T>::top(){
    if (!empty()) {
        return last->info;
    } else {
        return -1;
    }
}

template <typename T>
void CStack<T>::clear(){
    if (empty()) {
        while(first) {
            pop();
        }
    }
}
template <typename T>
bool CStack<T>::empty(){
    return first == nullptr;
}
