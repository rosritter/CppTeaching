#include "cstack.hpp"
/* 
template <class T>
CStack<T>::~CStack<T>() {
    clear();
}

template <class T>
CStack<T>::CStack<T>() {}

template <class T>
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
template <class T>
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
template <class T>
T CStack<T>::top(){
    if (!empty()) {
        return last->info;
    } else {
        return -1;
    }
}

template <class T>
void CStack<T>::clear(){
    if (empty()) {
        while(first) {
            pop();
        }
    }
}
template <class T>
bool CStack<T>::empty(){
    return first == nullptr;
}
 */
