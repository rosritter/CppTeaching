#include "cstack.hpp"

CStack::~CStack() {
    clear();
}

CStack::CStack() :first(nullptr), last(nullptr) {}

void CStack::pop(){
    if (empty()) return;
    Node* nd = first;
    if (first != last) {
        while (nd->next != last) 
            nd = nd->next;
        nd->next = nullptr;
        delete last;
        last = nd;
    } else {
        delete first;
    }
}

void CStack::push(uint32_t val){
    Node* new_Node = new Node(val);
    if (empty()) {
        first = new_Node;
        last = first;
        return;
    }
    last->next = new_Node;
    last = new_Node;
}

uint32_t CStack::top(){
    if (!empty()) {
        return last->info;
    } else {
        return -1;
    }
}

void CStack::clear(){
    if (empty()) {
        while(first) {
            pop();
        }
    }
}

bool CStack::empty(){
    return first == nullptr;
}