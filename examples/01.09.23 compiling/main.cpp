#include "headers/output.hpp"
#include "headers/square.hpp"

using std::cout;

#ifdef CHECK
#include <omp.h>
void pr(int i){
    cout << "Hello CHECK is workig " << i << "th time!" << std::endl;
}
#endif

int main(){
#ifdef CHECK
#pragma omp parallel num_threads(4)
    pr(omp_get_thread_num());
#endif  
    cout << output::printIntValue(square(3));
    return 0;
}
