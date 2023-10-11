#include<iostream>
#include<string>
#include<sstream>
#include "func.hpp"

void execStatic(int mat1[3][4], int mat2[4][2])
{
	int rslt[3][2];

	std::cout << "Multiplication of two given matrixes is: \n";

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			rslt[i][j] = 0;
			for (int k = 0; k < 4; k++)
			{
				rslt[i][j] += mat1[i][k] * mat2[k][j];
			}
			std::cout << rslt[i][j] << "\t";
		}
		std::cout << std::endl;
	}
};
void execDynamic()
{
	int i, j, k, N, M, L;
	//описание двойных указателей для матриц A, B, С
	double** a, ** b, ** c;
	//ввод размерности матриц
	std::cout << "N = "; std::cin >> N;
	std::cout << "M = "; std::cin >> M;
	std::cout << "L = "; std::cin >> L;
	//выделение памяти для массива а, каждый элемент массива -
	//указатель на double
	a = new double* [N];
	for (i = 0; i < N; i++)
		//выделение памяти для каждого элемента
		//a[i], a[i] адресует М элементов типа double
		a[i] = new double[M];
	//выделение памяти для массива b, каждый элемент массива -
	//указатель на double
	b = new double* [M];
	for (i = 0; i < M; i++)
		//выделение памяти для каждого элемента
		//b[i], b[i] адресует М элементов типа double
		b[i] = new double[L];
	//выделение памяти для массива c, каждый элемент массива -
	//указатель на double
	c = new double* [N];
	for (i = 0; i < N; i++)
		//выделение памяти для каждого элемента
		//c[i], c[i] адресует L элементов типа double
		c[i] = new double[L];
	//ввод матриц А и В
	std::cout << "Enter matrix А" << std::endl;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			std::cin >> a[i][j];
	std::cout << "Enter matrix B" << std::endl;
	for (i = 0; i < M; i++)
		for (j = 0; j < L; j++)
			std::cin >> b[i][j];
	//умножение матриц A и B
	for (i = 0; i < N; i++)
		for (j = 0; j < L; j++)
			//цикл для умножения i-й строки матрицы А на j-й столбец матрицы В
			for (c[i][j] = 0, k = 0; k < M; k++)
				c[i][j] += a[i][k] * b[k][j];
	//вывод матрицы С
	std::cout << "Result " << std::endl;
	for (i = 0; i < N; std::cout << std::endl, i++)
		for (j = 0; j < L; j++)
			std::cout << c[i][j] << "\t";
	for (i = 0; i < N; i++)
		//освобождение памяти для каждого элемнта a[i]
		delete[] a[i];
	//освобождение памяти для а
	delete[]a;
	for (i = 0; i < M; i++)
		//освобождение памяти для каждого элемнта b[i]
		delete[] b[i];
	//освобождение памяти для b
	delete[] b;
	for (i = 0; i < N; i++)
		//освобождение памяти для каждого элемнта c[i]
		delete[] c[i];
	//освобождение памяти c
	delete[]c;
};
