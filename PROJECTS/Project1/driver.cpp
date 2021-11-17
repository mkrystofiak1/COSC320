//Program: driver.cpp
//Author: Mitchell Krystofiak
//Description: This program will test the main functionality of the matrix operations:
//	       addition, subtraction, multiplication, inverses, transpose. It will also
//	       test the matrix types: singularity, symmetry, identity, triangular, etc.
//	       This will keep track of the number of operations and the time it takes for
//	       operations to be completed.
//Date: March 14, 2021

#include<iostream>
#include"Matrix.h"

using namespace std;

void init_upper(Matrix & A)
{
	srand(time(0));

	for (int i = 0; i < A.rows; i++)
		for (int j = i + 1; j < A.columns; j++)
			A.arr[i][j] = 0;
	for (int i = 0; i < A.rows; i++)
		for (int j = i; j < A.columns; j++)
			A.arr[i][j] = (rand() % 9) + 1;
}

void init_lower(Matrix & A)
{
	srand(time(0));

	for (int i = 1; i < A.rows; i++)
		for (int j = 0; j < i; j++)
			A.arr[i][j] = 0;
	for (int i = 0; i < A.rows; i++)
		for (int j = 0; j <= i; j++)
			A.arr[i][j] = (rand() % 9) + 1;
}

void init_iden(Matrix & A)
{
	long i = 0;
	long j = 0;
	while (i < A.rows && j < A.columns)
	{
		A.arr[i][j] = 1;
		i++;
		j++;
	}
}

void init_dia(Matrix & A)
{
	srand(time(0));

	long i = 0;
	long j = 0;
	while (i < A.rows && j < A.columns)
	{
		A.arr[i][j] = (rand() % 9) + 1;
		i++;
		j++;
	}
}
void init_random(Matrix & A)
{
	srand(time(0));

	for (int i = 0; i < A.rows; i++)
		for (int j = 0; j < A.columns; j++)
			A.arr[i][j] = (rand() % 9) + 1;
}

int main()
{
	//Test for making different types of matrices: identity, upper triangular,
	//	lower triangular, identity, symmetric, randomly allocated.
	
	cout << "Upper triangular matrix" << endl;
	Matrix A(5,5);
	init_upper(A);
	A.print();
	
	cout << endl;

	cout << "Upper triangular transpose" << endl;
	Matrix At = A.transpose();
	At.print();
	
	cout << endl;
	
	cout << "Inverse of matrix A" << endl;
	Matrix Ainv = A.inverse();
	Ainv.print();

	/*cout << "Test padding algorithm" << endl;
	Matrix Apadded = A.pad();
	Apadded.print();

	cout << endl;
	
	cout << "Make 9x9 matrix" << endl;
	Matrix test1(9,9);
	init_random(test1);
	test1.print();
	
	cout << endl;

	cout << "Test pad two" << endl;
	Matrix test1padded = test1.pad();
	test1padded.print();


	cout << endl;

	cout << "Lower triangular matrix" << endl;
	Matrix B(5,5);
	init_lower(B);
	B.print();
	
	cout << endl;

	cout << "Diagonal matrix" << endl;
	Matrix C(5,5);
	init_dia(C);
	C.print();

	cout << endl;

	cout <<"Identity matrix" << endl;
	Matrix D(5,5);
	init_iden(D);
	D.print();
	*/
	
	//Test for performing operations: subtraction, addition, multiplication
	//	inverses, transpose.
	

	//Timing and counts for the operations to happen.


	return 0;
}
