#include "cstack.hpp"
#include <stack>
#include <iostream>

using namespace std;

int main(){
    CStack cstack, cstack2;
    cstack.push(100);
    cout << cstack.top() << "\n";
    cstack.push(200);
    cstack.pop();
    cout << cstack.top() << "\n";
    cstack.push(200);
    cstack.push(300);
    cstack.push(400);
    cstack.printStack();
    cstack *= 3;
    cstack.printStack();

    cstack2.push(3);
    cstack2.push(2);
    cstack2.push(5);
    cstack2.push(6);
    cstack2.push(1);
    cstack2.push(23123);
    cstack2.printStack();

    cstack2 = cstack;
    cstack2.printStack();
    cstack.printStack();
    cout << cstack2[2] << "\n";

    if (cstack.empty()) cout <<"ПУСТОЙ ЕПТЫ ЫЫЫЫЫЫЫЫ\n";
    else cout << "НОРМАЛЬНО ЖИРНЫЙ ЕЩЕ\n";


    Node n1,n2;
        n1.info = 1;
        n2.info = 2;
        if (n1 < n2)
            std::cout << "Congratulations!\n";
        else
            std::cout << "Commiserations!\n";
    return 0;
}