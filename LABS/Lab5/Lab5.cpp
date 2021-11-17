//Program: Lab5.cpp
//Author: Mitchell Krystofiak
//Description: Test file for the matrix class: addition, subtraction, multiplication, 
//             scalar multiplication, diagonal, upper T, lower T, identiy, and vectors.
//Date: March 5, 2021

#include"Matrix.h"
#include<iostream>
#include<chrono> //might move to the cpp file
#include<ctime>

using namespace std;

void make_Matrix(int n, int m);

int main()
{
	//Different test cases:
	//  Diagonal
	//  Vector
	//  Identity
	//  Upper Triangular
	//  Lower Triangular
	
	cout << "Testing matrices: " << endl;
	cout << endl;

	Matrix upper(4,4);
	upper.arr[0][0] = upper.arr[1][1] = upper.arr[2][2] = upper.arr[3][3] = 2;
	upper.arr[0][1] = upper.arr[0][2] = upper.arr[0][3] = upper.arr[1][2] = upper.arr[1][3] = upper.arr[2][3] = 0;
	upper.arr[3][0] = 1;	
	
	Matrix lower(2,2);
	lower.arr[0][0] = lower.arr[1][1] = 1;
	lower.arr[0][1] = 1;
	
	Matrix diagonal(6, 3);
	diagonal.arr[0][0] = diagonal.arr[1][1] = diagonal.arr[2][2] = 3;

	Matrix vector(7,1);

	Matrix sum(2,2);
	sum.arr[0][0] = 3;
	sum.arr[1][1] = 7;
	sum.arr[0][1] = 9;
	sum.arr[1][0] = 14;
	
	Matrix product(2, 2);
	product.arr[0][0] = 34;
	product.arr[1][1] = 2;
	product.arr[0][1] = 0;
	product.arr[1][0] = -1;
	
	Matrix identity(3,3);
	identity.arr[0][0] = identity.arr[1][1] = identity.arr[2][2] = 1;
	//Upper Triangular
	
	cout << endl;
	cout << "---1---" << endl;
	upper.print();
	cout << "Is Upper Triangular: " << upper.is_Upper_T() << endl;
	cout << "Is Lower Triangular: " << upper.is_Lower_T() << endl;
	cout << "Is Diagonal: " << upper.is_Diagonal() << endl;
	cout << "Is Vector: " << upper.is_Vector() << endl;	
	cout << "Is Identity: " << upper.is_Identity() << endl;
	cout << "Is Square: " << upper.is_Square() << endl;

	cout << endl;
        cout << "---2---" << endl;
	lower.print();
        cout << "Is Upper Triangular: " << lower.is_Upper_T() << endl;
        cout << "Is Lower Triangular: " << lower.is_Lower_T() << endl;
        cout << "Is Diagonal: " << lower.is_Diagonal() << endl;
        cout << "Is Vector: " << lower.is_Vector() << endl;
        cout << "Is Identity: " << lower.is_Identity() << endl;
	cout << "Is Square: " << lower.is_Square() << endl;

	cout << endl;
        cout << "---3---" << endl;
        diagonal.print();
	cout << "Is Upper Triangular: " << diagonal.is_Upper_T() << endl;
        cout << "Is Lower Triangular: " << diagonal.is_Lower_T() << endl;
        cout << "Is Diagonal: " << diagonal.is_Diagonal() << endl;
        cout << "Is Vector: " << diagonal.is_Vector() << endl;
        cout << "Is Identity: " << diagonal.is_Identity() << endl;
	cout << "Is Square: " << diagonal.is_Square() << endl;

	cout << endl;
        cout << "---4---" << endl;
        vector.print();
	cout << "Is Upper Triangular: " << vector.is_Upper_T() << endl;
        cout << "Is Lower Triangular: " << vector.is_Lower_T() << endl;
        cout << "Is Diagonal: " << vector.is_Diagonal() << endl;
        cout << "Is Vector: " << vector.is_Vector() << endl;
        cout << "Is Identity: " << vector.is_Identity() << endl;
	cout << "Is Square: " << vector.is_Square() << endl;

	cout << endl;
        cout << "---5---" << endl;
        sum.print();
	cout << "Is Upper Triangular: " << sum.is_Upper_T() << endl;
        cout << "Is Lower Triangular: " << sum.is_Lower_T() << endl;
        cout << "Is Diagonal: " << sum.is_Diagonal() << endl;
        cout << "Is Vector: " << sum.is_Vector() << endl;
        cout << "Is Identity: " << sum.is_Identity() << endl;
	cout << "Is Square: " << sum.is_Square() << endl;

	cout << endl;
        cout << "---6---" << endl;
        product.print();
	cout << "Is Upper Triangular: " << product.is_Upper_T() << endl;
        cout << "Is Lower Triangular: " << product.is_Lower_T() << endl;
        cout << "Is Diagonal: " << product.is_Diagonal() << endl;
        cout << "Is Vector: " << product.is_Vector() << endl;
        cout << "Is Identity: " << product.is_Identity() << endl;
	cout << "Is Square: " << product.is_Square() << endl;

	cout << endl;
        cout << "---7---" << endl;
        identity.print();
	cout << "Is Upper Triangular: " << identity.is_Upper_T() << endl;
        cout << "Is Lower Triangular: " << identity.is_Lower_T() << endl;
        cout << "Is Diagonal: " << identity.is_Diagonal() << endl;
        cout << "Is Vector: " << identity.is_Vector() << endl;
        cout << "Is Identity: " << identity.is_Identity() << endl;
	cout << "Is Square: " << identity.is_Square() << endl;
	
	//operations
	// 1.upper has 4x4 , 2.lower has 2x2, 3.diagonal has 6x3, 4.vector has 7x1, 5.sum
	// has 2x2, 6.product has 2x2, 7.identity has 3x3
	
	cout << "Adding matrices: " << endl;
	cout << endl;

	Matrix sum1(2,2);
	sum1 = lower + sum;
	lower.print();
	cout << " + " << endl;
	sum.print();
	cout << " = " << endl;
	sum1.print();
	cout << endl;

	Matrix sum2(2,2);
	lower.print();
	cout << " + " << endl;
	vector.print();
	cout << " = " << endl;
	sum2 = lower + vector;
	cout << endl;
	
	cout << "Subtracting matrices: " << endl;
	cout << endl;

	Matrix diff(2,2);
	diff = lower - sum;
	lower.print();
	cout << " - " << endl;
	sum.print();
	cout << " = " << endl;
	diff.print();
	cout << endl;

	Matrix diff2(3,3);
	lower.print();
	cout << " - " << endl;
	diagonal.print();
	cout << " = " << endl;
	lower - diagonal;
	cout << endl;

	cout << "Scalar multiplication: " << endl;
	cout << endl;

	cout << "5 * " << endl;
	sum1.print();
	cout << " = " << endl;
	sum1 = sum1 * 5;
	sum1.print();
	cout << endl;

	cout << "12 * " << endl;
	diagonal.print();
	cout << " = " << endl;
	diagonal = diagonal * 12;
	diagonal.print();
	cout << endl;

	cout << "Multiplying matrices: " << endl;
	cout << endl;

	// 1.upper has 4x4 , 2.lower has 2x2, 3.diagonal has 6x3, 4.vector has 7x1, 5.sum
        // has 2x2, 6.product has 2x2, 7.identity has 3x3
	
	//same dimentions
	Matrix pro1(2,2);	
	auto start = chrono::system_clock::now();
	pro1 = lower * sum;
	auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end-start;
        time_t end_time = chrono::system_clock::to_time_t(end);
	lower.print();
	cout << " * " << endl;
	sum.print();
	cout << " = " << endl;
	pro1.print();
	cout << "Matrix Multiplication time: " << endl;
        cout << "finished at " << ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "\n";
	cout << endl;
	
	//different dimensions, compatible multiplication
	Matrix pro2(6,3);
	start = chrono::system_clock::now();
	pro2 = diagonal * identity;
	end = chrono::system_clock::now();
        elapsed_seconds = end-start;
        end_time = chrono::system_clock::to_time_t(end);
	diagonal.print();
	cout << " * " << endl;
	identity.print();
	cout << " = " << endl;
	pro2.print();
	cout << "Matrix Multiplication time: " << endl;
        cout << "finished at " << ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "\n";
        cout << endl;

	//incompatible
	vector.print();
	cout << " * " << endl;
	sum.print();
	cout << " = " << endl;
	pro2 = vector * sum;
	cout << endl;

	//big matrix
	cout << "Big matrix multiplication: " << endl;
	cout << endl;

	srand(time(0));

	Matrix big(10,20);
	Matrix big2(20, 40);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 20; j++)
			big.arr[i][j] = rand() % 50;

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 40; j++)
			big2.arr[i][j] = rand() % 50;
	
	Matrix big3(10, 40);
	start = chrono::system_clock::now();
	big3 = big * big2;
	end = chrono::system_clock::now();
        elapsed_seconds = end-start;
        end_time = chrono::system_clock::to_time_t(end);
	big.print();
	cout << " * " << endl;
	big2.print();
	cout << " = " << endl;
	big3.print();
	cout << "Matrix Multiplication time: " << endl;
        cout << "finished at " << ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "\n";
        cout << endl;
	
	return 0;
}


