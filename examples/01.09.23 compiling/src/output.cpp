#include "output.hpp"

string output::printIntValue(int val){
    hello();
    return to_string(val);
}


void output::hello(){
    cout << "Hello!" << endl << "Current value is -> ";
}