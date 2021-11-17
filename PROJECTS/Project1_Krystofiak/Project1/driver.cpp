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
#include<iomanip>
#include<chrono>

using namespace std;

void init_upper(Matrix & A)
{
	srand(time(0));
	for (int i = 0; i < A.rows; i++)
		for (int j = i + 1; j < A.columns; j++)
			A.arr[i][j] = 0.0;
	for (int i = 0; i < A.rows; i++)
		for (int j = i; j < A.columns; j++)
			A.arr[i][j] = (rand() % 9) + 1;
}

void init_lower(Matrix & A)
{
	srand(time(0));

	for (int i = 1; i < A.rows; i++)
		for (int j = 0; j < i; j++)
			A.arr[i][j] = 0.0;
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
		A.arr[i][j] = 1.0;
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
	
	//upper triangular
	cout << "Upper Triangular matrix" << endl;
	Matrix A(5,5);
	init_upper(A);
	A.print();
	
	cout << endl;
	//upper triangular transpose
	cout << "Upper Triangular transpose" << endl;
	auto start = std::chrono::system_clock::now();
	Matrix At = A.transpose();
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end-start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	At.print();

	cout << endl;
	//lower triangular
	cout << "Lower Triangular matrix" << endl;
	Matrix B(5,5);
	init_lower(B);
	B.print();
	
	cout << endl;

	//lower triangular transpose
	cout << "Lower Triangular transpose" << endl;
	start = std::chrono::system_clock::now();
	Matrix Bt = B.transpose();
	end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        end_time = std::chrono::system_clock::to_time_t(end);
        std::cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	Bt.print();

	cout << endl;
	
	//diagonal matrix
	cout << "Diagonal matrix" << endl;
	Matrix C(4,4);
	init_dia(C);
	C.print();

	cout << endl;

	cout << "Diagonal matrix inverse" << endl;
	start = std::chrono::system_clock::now();
	Matrix Cinv = C.inverse();
	end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        end_time = std::chrono::system_clock::to_time_t(end);
        std::cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	Cinv.print();

	cout << endl;
	
	//diagonal matrix transpose
	cout << "Diagonal matrix transpose" << endl;
	start = std::chrono::system_clock::now();
	Matrix Ct = C.transpose();
	end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        end_time = std::chrono::system_clock::to_time_t(end);
        std::cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	Ct.print();
	
	cout << endl;

	//identity matrix
	cout <<"Identity matrix" << endl;
	Matrix D(5,5);
	init_iden(D);
	D.print();
		
	cout << endl;

	cout <<"2x2 Matrix" << endl;
	Matrix test2(2,2);
	init_random(test2);
	test2.print();

	cout << endl;
	
	cout <<"Another 2x2 Matrix" << endl;
	Matrix test3(2,2);
	init_random(test3);
	test3.print();

	cout << endl;

	cout <<"Big matrix 10x10" << endl;
	Matrix big(10,10);
	init_random(big);
	big.print();
	
	cout << endl;

	cout << "Another matrix Big 10x10" << endl;
	Matrix big2(10,10);
	init_upper(big2);
	big2.print();
	
	cout << endl;
	
	//Test for performing operations: subtraction, addition, multiplication
	//	inverses, transpose.
	
	cout << "Now to test some operations. " << endl;

	//big matrices
	
	cout << "Adding the two big matrices: " << endl;
	start = std::chrono::system_clock::now();
	Matrix big3 = big + big2;
	end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        end_time = std::chrono::system_clock::to_time_t(end);
        std::cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	big3.print();

	cout << endl;

	cout << "Subtracting the two big matrices: " << endl;
	start = std::chrono::system_clock::now();
	big3 = big - big2;
	end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        end_time = std::chrono::system_clock::to_time_t(end);
        std::cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	big3.print();

	cout << endl;

	cout << "Multiplying the big matrix by a constant 5: " << endl;
	start = std::chrono::system_clock::now();
	big3 = big * 5;
	end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        end_time = std::chrono::system_clock::to_time_t(end);
        std::cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	big3.print();

	cout << endl;

	cout << "Multiplying the two big matrices together: " << endl;
	start = std::chrono::system_clock::now();
	big3 = big * big2;
	end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        end_time = std::chrono::system_clock::to_time_t(end);
        std::cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	big3.print();

	cout << endl;
	//average cases
	cout << "Adding lower and upper triangular matrices: " << endl;
	start = std::chrono::system_clock::now();
	Matrix sum = A + B;
	end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        end_time = std::chrono::system_clock::to_time_t(end);
        std::cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	sum.print();

	cout << endl;

	cout << "Subtracting lower and upper triangular matrices: " << endl;
	start = std::chrono::system_clock::now();
	sum = A-B;
	end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        end_time = std::chrono::system_clock::to_time_t(end);
        std::cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	sum.print();

	cout << endl;

	cout << "Multiplying lower and upper triangular matrices: " << endl;
	start = std::chrono::system_clock::now();
	sum = A*B;
	end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        end_time = std::chrono::system_clock::to_time_t(end);
        std::cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	sum.print();

	cout << endl;

	cout << endl;

	return 0;
}
