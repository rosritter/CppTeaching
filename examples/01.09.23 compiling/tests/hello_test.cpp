#include <string>
#include <algorithm>
#include "square.hpp"

using namespace std;

int hello_test(){
    if (square(3) == 10) {
        return 0;
    } 
    return -1;
}

int main(){
    return hello_test();
}