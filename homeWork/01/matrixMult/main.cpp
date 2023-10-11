#include<iostream>
#include "func.hpp"


int main() 
{
    std::cout << "Hello World!\n";
    
    int A[3][4];
    int B[4][2];

    std::cout << "Enter matrix A\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Enter " << i + 1 << " row\n";
        for (int j = 0; j < 4; j++)
        {
            std::cin >> A[i][j];
        }
    }
    std::cout << "Enter matrix B\n";
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Enter " << i + 1 << " row\n";
        for (int j = 0; j < 2; j++)
        {
            std::cin >> B[i][j];
        }
    }
    execStatic(A, B);


    execDynamic();
    return 0;
}
