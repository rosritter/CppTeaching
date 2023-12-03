#include "cstack.hpp"
using namespace std;

CStack::CStack(){}

CStack::~CStack(){
    //destroy me!)
    clear();
}

void CStack::pop(){
    if (ptop == nullptr) return;
    Node* ptr = ptop ->next;
    delete ptop;
    ptop = ptr;

}

void CStack::clear(){
    while (ptop != nullptr) {
        pop();
    }
    

}

void CStack::push(uint32_t val){
    Node* node = new Node();
    node ->next = ptop;
    node ->info = val;
    ptop = node;

}

uint32_t CStack::top(){

    return ptop->info;
}

bool CStack::empty(){
    return ptop==nullptr;
}


void CStack::printStack() {
    Node* ptr = ptop;
    while(ptr != nullptr) {
        cout << ptr ->info << " ";
        ptr = ptr ->next;

    }
    cout << "\n";
}



CStack& CStack::operator=(const CStack& cstack) {
    if (this != &cstack) {
        while (ptop != nullptr) {
        pop();
        }
        Node* ptr = cstack.ptop;
        while (ptr != nullptr) {
            push(ptr->info);
            ptr = ptr ->next;
        }


    }
    
    return *this;
}

CStack& CStack::operator*=(int multi) {
    Node* ptr = ptop;
    while (ptr != nullptr) {
        ptr->info *= multi;
        ptr = ptr->next;
    }
    return *this;
}

int CStack::operator[](int ind) {
    Node* ptr =ptop;
    for (int i = 0; i< ind;i++) {
        if (ptr == nullptr) {
            throw out_of_range("Нету такого элементыта");
        } 
        ptr = ptr -> next;
    }
    if (ptr == nullptr) throw out_of_range("Нету такого элементыта");
    
    return ptr ->info;

}


bool Node::operator<(const Node& node) {
    return info < node.info;
}


















/*
CStack& CStack::operator=(const CStack& newStack) {
        if(this != &newStack)
        {
            CStack(newStack).swap(*this);
        }
        return *this;
    }


void CStack::swap(CStack & other)
    {
        swap(top, other.top);
    }
*/





