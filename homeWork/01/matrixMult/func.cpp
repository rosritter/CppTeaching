#include "func.hpp"
#include <iostream>
using namespace std;

void execStatic() {
    int arr1[3][4];
    int arr2[4][2];
    int arr3[3][2];
    int znach = 1, kostil = 0;

    for (int i = 0;i<3;i++) {
        for (int j = 0;j < 4;j++) {
            arr1[i][j] = znach;
            znach++;
        }
    }

    for (int i = 0;i<4;i++) {
        for (int j = 0;j < 2;j++) {
            arr2[i][j] = znach;
            znach++;
        }
    }

    for (int i = 0;i<3;i++) {
        for (int j = 0;j<2;j++) {
            for (int h = 0; h <4;h++) {
                kostil += arr1[i][h] * arr2[h][j];
            }
            arr3[i][j] = kostil;
            kostil = 0;
        }
    }


    for (int i = 0;i<3;i++) {
        cout <<arr3[i][0];
        for (int j = 1;j<2;j++) {
            cout << " " <<arr3[i][j];
        }
        cout << "\n";
    }
}

void execDynamic() {

    int n, m, l ;

    cin >> n >> m >> l;
    
    int **arr1 = new int* [n];
    int **arr2 = new int* [m];
    int **arr3 = new int* [n];


    for (int i = 0; i<n;i++) {
        arr1[i] = new int[m]; 
        for (int j = 0;j < m;j++) {
            cin >> arr1[i][j] ;
        }
    }
    
    for (int i = 0; i<m;i++) {
        arr2[i] = new int[l]; 
        for (int j = 0; j<l;j++) {
            cin >> arr2[i][j];
        }
    }

    for (int i = 0; i<n;i++) {
        arr3[i] = new int[l]; 
        for (int j = 0; j<l;j++) {
            for (int h = 0; h <m;h++) {
                arr3[i][j] += arr1[i][h] * arr2[h][j];
            }
        }
    }


    for (int i = 0;i<n;i++) {
        cout <<arr3[i][0];
        for (int j = 1;j<l;j++) {
            cout << " " <<arr3[i][j];
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        delete[] arr1[i];
        delete[] arr3[i];
    }
    delete[] arr1;
    delete[] arr3;

    for (int i = 0; i < m; i++)
    {
        delete[] arr2[i];
    }
    delete[] arr2;

}
