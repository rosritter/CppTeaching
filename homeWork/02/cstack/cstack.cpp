#include "cstack.hpp"

using namespace std;


CStack::CStack()
{
    ptop = nullptr;
}

CStack::~CStack(){
    clear();
}

void CStack::pop()
{
    if (!empty()) 
    {
        Node* temp = ptop;
        ptop = ptop->next;

    }
}

void CStack::clear()
{
    while (!empty()) {
        pop();
    }
    Node* current = ptop;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void CStack::push(uint32_t val)
{
    Node* temp = new Node(val);
    temp->info = val;
    temp->next = ptop;
    ptop = temp;
}

void CStack::display()
{
    Node* temp;
    if (ptop == NULL) {
        cout << "\nStack Underflow";
        exit(1);
    }
    else {
        temp = ptop;
        while (temp != NULL) 
        {
            cout << temp->info;
            temp = temp->next;
            if (temp != NULL)
                cout << " ";
        }
    }
}

uint32_t CStack::top()
{
    if (ptop != nullptr) 
    {
        return ptop->info;
    }
    return 0;
}

bool CStack::empty(){
    return ptop==nullptr;
}

void CStack::operator*=(uint32_t multiplier) 
{
    Node* current = ptop;
    while (current != nullptr) {
        current->info *= multiplier;
        current = current->next;
    }
}

uint32_t CStack::operator[](size_t index) const {
    Node* current = ptop;
    size_t currentIndex = 0;
    while (current != nullptr) {
        if (currentIndex == index) {
            return current->info;
        }
        currentIndex++;
        current = current->next;
    }
    throw std::out_of_range("Mistake");
}