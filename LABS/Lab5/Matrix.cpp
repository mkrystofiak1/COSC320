//Program: Matrix.cpp
//Author: Mitchell Krystofiak
//Description: Implementation of the Matrix class.
//Date: March 4, 2021


#include"Matrix.h"
#include<iostream>
 
/*
 * Default Constructor: Initializes the matrix with
 * 1 rows by 1 columns, all positions equal to 0.
 */
Matrix::Matrix()
{
	this->rows = 1;                      
	this->columns = 1;				
	this->arr = new double*[this->rows];
	for (int i = 0; i < this->rows; i++)
		this->arr[i] = new double[this->columns];

	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->columns; j++)
			this->arr[i][j] = 0;
}

/*
 * Main Constuctor: Initializes the matrix with m
 * rows by n columns, all positions equal to 0.
 */

Matrix::Matrix(long unsigned n, long unsigned m)
{
	if (n < 1 || m < 1)
	{
		std::cout << "Dimensions must be greater than or equal to 1. " << std::endl;
		return;
	}
	this->rows = n;
	this->columns = m;
	this->arr = new double*[this->rows];
	for (int i = 0; i < this->rows; i++)
		this->arr[i] = new double[this->columns];

	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->columns; j++)
			this->arr[i][j] = 0;
}

/*
 * Copy Constructor: Makes a copy of the origionally
 * made matrix.
 */

Matrix::Matrix(const Matrix & A)
{
	this->rows = A.rows;
	this->columns = A.columns;
	this->arr = new double*[this->rows];
	for (int i = 0; i < this->rows; i++)
	{
		this->arr[i] = new double[this->columns];
		for (int j = 0; j < this->columns; j++)
			this->arr[i][j] = A.arr[i][j];
	}
}

/*
 * Deconstructor: Deletes the allocated memory
 * spaces.
 */

Matrix::~Matrix()
{
	for (int i = 0 ; i < rows; i++)
		delete[] arr[i];
	delete[] arr;
	
}


/*
 * Overloads the + operator for matrices by adding
 * two elements of the same position.
 */

Matrix Matrix::operator+(const Matrix B) const
{
	if (this->columns != B.columns || this->rows != B.rows)
	{
		std::cout << "Cannot add matrices with different dimensions." << std::endl;
		return *this;
	}
	Matrix sum(this->rows, this->columns);
	for (int i = 0; i < sum.rows; i++)
		for (int j = 0; j < sum.columns; j++)
			sum.arr[i][j] = this->arr[i][j] + B.arr[i][j];
	return sum;
}

/*
 * Overloads the - operator for matrices by subtracting
 * two elements of the same position.
 */

Matrix Matrix::operator-(const Matrix B) const
{
	if (this->columns != B.columns || this->rows != B.rows)
        {
                std::cout << "Cannot subtract matrices with different dimensions." << std::endl;
                return *this;
        }
	Matrix dif(this->rows, this->columns);
        for (int i = 0; i < dif.rows; i++)
                for (int j = 0; j < dif.columns; j++)
                        dif.arr[i][j] = this->arr[i][j] - B.arr[i][j];
        return dif;
}

/*
 * Overloads the * operator for matrices by multiplying
 * each element of a matrix by a scalar.
 */

Matrix Matrix::operator*(const int scalar) const
{
	Matrix product(this->rows, this->columns);
	for (int i = 0; i < product.rows; i++)
		for (int j = 0; j < product.columns; j++)
			product.arr[i][j] = scalar * this->arr[i][j];
	return product;
}

/*
 * Overloads the * operator for matrices by taking the 
 * dot products of corresponding elements.
 */

Matrix Matrix::operator*(const Matrix B) const
{
	
	if (this->columns != B.rows)
	{
		std::cout << "Cannot multiply matrices with invalid dimensions." << std::endl;
		return *this;
	}
	Matrix mult(this->rows, B.columns);
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < B.columns; j++)
		{
			int sum = 0;
			for (int l = 0; l < this->columns; l++)
			{
				sum += this->arr[i][l] * B.arr[l][j];
			}
			mult.arr[i][j] = sum;
		}
	}
	return mult;
}

/*
 * Overloads the = operator for matrices by setting all
 * values of one matrix equal to the other.
 */

void Matrix::operator=(const Matrix B)
{
	this->columns = B.columns;
	this->rows = B.rows;
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->columns; j++)
			this->arr[i][j] = B.arr[i][j];
}

/*
 * Checks if the matrix is diagonal, where all elements
 * other then the main diagonal are equal to 0.
 */

bool Matrix::is_Diagonal()
{
	if (is_Upper_T() && is_Lower_T())
		return true;
	return false; 
}

/*
 * Checks if the matrix is a square matrix, where the
 * number of rows is equal to the number of columns.
 */

bool Matrix::is_Square()
{
	if (columns == rows)
		return true;
	return false;
}

/*
 * Checks if the matrix is an upper triangular matrix,
 * where entries below the main diagonal are all 0.
 */

bool Matrix::is_Upper_T() 
{
	bool temp;
	for (int i = 0; i < rows; i++)
	{
		for (int j = i+1; j < columns; j++)
		{
			temp = false;
			if (arr[i][j] == 0)
				temp = true;
			if (!temp)
				return false;
		}
	}
	return temp;
}

/*
 * Checks if the matrix is a lower triangular matrix,
 * where entries above the main diagonal are all 0.
 */

bool Matrix::is_Lower_T()
{
	bool temp;
	for (int i = 1; i < rows; i++)
	{
		for (int j = 0; j < i; j++)
		{
			temp = false;
			if (arr[i][j] == 0)
				temp = true;
			if (!temp)
				return false;
		}
	}
	return temp;
}

/* 
 * Checks if the matrix is a vector, where the number
 * of columns is equal to 1.
 */

bool Matrix::is_Vector()
{
	if (columns == 1)
		return true;
	return false;
}

/*
 * Checks if the matrix is an identity matrix, where
 * the main diagonal elements are all equal to 1 and
 * the rest are equal to 0.
 */

bool Matrix::is_Identity()
{
	if (is_Upper_T() && is_Lower_T()) //if both above and below diagonal are all zeroes
	{
		bool temp = false;
		for (int i = 0; i < columns; i++)
			for (int j = 0; j < rows; j++)
			{
				if (arr[i][j] == 1)
				{
					temp = true;
					i++;
				}
				else
					return false;
			}
		return temp;
	}
	return false;
}

/*
 * Determines if the matrix is singular, or the 
 * determinate is equal to 0.
 */

bool Matrix::is_Singular()
{
	if (determinate() == 0)
		return true;
	return false;	
}

/*
 *
 *
 */

/*bool Matrix::is_Symmetrix()
{

}
*/

/*
 * CoFactor
 *
 */

double Matrix::cofactor()
{
	return 0; //TODO
}
/* 
 * Computes the determinate of the matrix. For 2x2
 * matrices, detA = ad-bc. For 3x3 and higher, use
 * Cofactor expansion (Laplace expansion).
 */

double Matrix::determinate()
{
	if (columns == 2 && rows == 2)
		return((arr[0][0] * arr[1][1]) - (arr[0][1] * arr[1][0]));
	 //TODO	
	return 0; //TODO
}

/*
 * Assumes that the inverse is possible, and that 
 * we are dealing with a symmetrix matrix. Formulas
 * to be continued...
 */

/*Matrix Matrix::inverse()
{
	//TODO
}
*/

/*
 * Transpose...
 *
 */

/*Matrix Matrix::transpose()
{
	return A;//TODO
}
*/

void Matrix::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			std::cout << arr[i][j] << " ";
		std::cout << std::endl;
	}
}

