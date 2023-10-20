#include "cstack.hpp"
#include <iostream>


using namespace std;

CStack::CStack()
{
    ptop = NULL;
}

bool CStack::empty()
{
    return ptop == nullptr;
}

void CStack::pop()
{
    Node* temp;
    // Check for stack underflow
    if (empty())
    {
    }
    else
    {
        // Assign top to temp
        temp = ptop;

        // Assign second node to top
        ptop = ptop->next;

        // This will automatically destroy
        // the link between first node and second node

        // Release memory of top node
        // i.e delete the node
        free(temp);
    }
}

void CStack::push(uint32_t val)
{
    // Create new node temp and allocate memory in heap
    Node* temp = new Node(val);
    // Initialize data into temp data field
    temp->info = val;
    // Put top pointer reference into temp link
    temp->next = ptop;
    // Make temp as top of Stack
    ptop = temp;
}

void CStack::display()
{
    Node* temp;
    // Check for stack underflow
    if (ptop == NULL) {
        cout << "\nStack Underflow";
        exit(1);
    }
    else {
        temp = ptop;
        while (temp != NULL) {

            // Print node data
            cout << temp->info;

            // Assign temp link to temp
            temp = temp->next;
            if (temp != NULL)
                cout << " ";
        }
    }
}

uint32_t CStack::top()
{
    if (!empty()) {
        return ptop->info;
    }
    else {
        return -1;
    }
}

void CStack::clear()
{
    if (empty()) {
        while (ptop != nullptr) {
            pop();
        }
    }

}

CStack::~CStack()
{
    clear();
}