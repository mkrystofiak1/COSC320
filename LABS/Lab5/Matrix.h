//Program: Matrix.h
//Author: Mitchell Krystofiak
//Description: Definition of the Matrix class.
//Date: March 4, 2020



#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
	//private:
	public:
		double ** arr;
		long unsigned rows;
		long unsigned columns;
		
	//public:
		Matrix();
		Matrix(long unsigned, long unsigned);
		Matrix(const Matrix &);
		~Matrix();
		
		Matrix operator+(const Matrix) const;
		Matrix operator-(const Matrix) const;
		Matrix operator*(const int) const;
		Matrix operator*(const Matrix) const;
		void operator=(const Matrix );
		
		bool is_Diagonal();
		bool is_Square();
		bool is_Upper_T();
		bool is_Lower_T();
		bool is_Vector();
		bool is_Identity();
		bool is_Singular();
		bool is_Symmetric();
		double determinate();
		double cofactor();
		Matrix inverse();
		Matrix transpose();		
		void print();
};

#endif
