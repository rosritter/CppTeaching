#pragma once
#include <cstdint>
#include <cstddef>
#include <stdexcept>
#include <stack>

template <typename T>
struct Node
{
    T info;
    Node* next = nullptr;
    
    bool operator<(const Node& other) const {
        return info < other.info;
    }
};

template <typename T>
class CStack {
private:
    Node<T>* ptop = nullptr;

public:
    CStack();
    ~CStack(); // Clears all memory
    void pop(); // Removes the top element
    void push(T val); // Inserts element at the top
    T top(); // Accesses the top element
    bool empty(); // Checks whether the underlying container is empty
    void operator*=(T multiplier);
    CStack& operator=(const CStack& other);
    T operator[](size_t index) const;
    bool operator<(const CStack& other) const;

private:
    void clear();
};

template <typename T>
CStack<T>::CStack() {
    ptop = nullptr;
}

template <typename T>
CStack<T>::~CStack() {
    clear();
}


template <typename T>
void CStack<T>::pop() {
    if (!empty()) {
        Node<T>* temp = ptop;
        ptop = ptop->next;
    }
}


template <typename T>
void CStack<T>::clear() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
void CStack<T>::push(T val) {
    Node<T>* newNode = new Node<T>;
    newNode->info = val;
    newNode->next = ptop;
    ptop = newNode;
}

template <typename T>
T CStack<T>::top() {
    if (!empty()) {
        return ptop->info;
    }
    throw std::out_of_range("Stack is empty");
}

template <typename T>
bool CStack<T>::empty() {
    return ptop == nullptr;
}

template <typename T>
void CStack<T>::operator*=(T multiplier) {
    Node<T>* current = ptop;
    while (current != nullptr) {
        current->info *= multiplier;
        current = current->next;
    }
}

template <typename T>
CStack<T>& CStack<T>::operator=(const CStack<T>& other) {
    if (this == &other) {
        return *this;
    }
    clear();  

    Node<T>* current = other.ptop;
    Node<T>* previous = nullptr;

    while (current != nullptr) {
        Node<T>* newNode = new Node<T>;
        newNode->info = current->info;
        newNode->next = nullptr;

        if (previous != nullptr) {
            previous->next = newNode;
        } else {
            ptop = newNode;
        }

        previous = newNode;
        current = current->next;
    }

    return *this;
}


template <typename T>
T CStack<T>::operator[](size_t index) const {
    Node<T>* current = ptop;
    size_t currentIndex = 0;
    while (current != nullptr) {
        if (currentIndex == index) {
            return current->info;
        }
        currentIndex++;
        current = current->next;
    }
    throw std::out_of_range("Index out of range");
}

template <typename T>
bool CStack<T>::operator<(const CStack<T>& other) const {
    Node<T>* current1 = ptop;
    Node<T>* current2 = other.ptop;

    while (current1 != nullptr && current2 != nullptr) {
        if (current1->info < current2->info) {
            return true;
        } else if (current1->info > current2->info) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return current1 == nullptr && current2 != nullptr;
}