#include "cstack.hpp"

CStack::CStack(){}


CStack::~CStack(){
    clear();
}



void CStack::pop(){
    if (empty())
    return;
    if(first != ptop)
    {
        Node* nod = first;
        while(nod->next != ptop)
            nod = nod->next;
        nod->next = nullptr;
        delete ptop;
        ptop = nod;
    }
    else
    {
        delete ptop;
        delete first;
        ptop = nullptr;
        first = nullptr;
    }
}

void CStack::clear(){
if (empty()) {
    while(first != nullptr) {
        pop();
    }
}
}


void CStack::push(uint32_t val){
Node* nnode = new Node(val);
if(empty())
{
    ptop = nnode;
    first = ptop;
}
else
{
    ptop->next = nnode;
    ptop = nnode;
}

}

uint32_t CStack::top(){
    if(!empty()){
        return ptop->info;
    }
    else {
        return -1;
    }
}

bool CStack::empty(){
    return ptop == nullptr;
}