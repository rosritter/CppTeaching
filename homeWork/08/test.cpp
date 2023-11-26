#include <iostream>
#include <cassert>
#include <vector>
#include <memory>

#include "file_reader_raii.h"
#include "rectangle.h"

int main() {
    int* ptr = new int{20};
    std::vector<int>* vector_ptr = new std::vector<int>();
    int* i = new int{0};
    for (i; *i < 20; ++(*i)) {
        vector_ptr->push_back(*ptr * *i);
    }
    delete ptr;
    delete vector_ptr;
    delete i;
    return 0;
}