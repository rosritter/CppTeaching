#include "cstack.hpp"
#include <stack>

using namespace std;

int main(){
    CStack s;
    CStack s1;
    s.push(1);
    s.push(4);
    s.push(3);
    s1 = s;
    std::cout << s1[1] << std::endl;
    return 0;
}