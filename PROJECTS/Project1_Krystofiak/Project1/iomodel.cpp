//Program: IOmodel.cpp
//Author: Mitchell Krystofiak
//Description: This program will use the matrix class to read in economy data and report the production
//             needed. It will also report how much of each product is needed to satisfy demands.
//Date: March 14, 2021

#include<iostream>
#include<fstream>
#include"Matrix.h"
#include<iomanip>
#include<cmath>

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

int main(int argc, char * argv[])
{
	int argNum = 1;

	if (argc < 2)
	{
		cout << "ERROR: Expecting 2 arguments!" << endl;
		return 1;
	}

	else
	{
		while (argNum < argc)
		{
			ifstream IOModel(argv[argNum]);

			if (!IOModel)
			{
				cout << "ERROR: Cannot open input file!" << endl;
				return 1;
			}
		

		unsigned long size = 0;

		string *trav = new string[10000];

		while (getline(IOModel, trav[size]))
		{
			if (trav[size] == "---")
				break;
			else if (size >= 10000)
			{
				cout <<"ERROR: Matrix too large!" << endl;
				return  1;
			}
			size++;
		}
		Matrix A(size, size);
		Matrix I(size, size);
		Matrix d(size, 1);

		double data = 0;
		int i = 0;
		int j = 0;
		while (IOModel >> data)
		{
			A.arr[i][j] = data;
			j++;
			if (j == A.columns)
			{
				j = j % A.columns;
				i++;
			}
		}
		IOModel.clear();
		while (IOModel >> trav[size])
		{
			if (trav[size] == "--")
				break;
		}
		i = 0;
		j = 0;
		while (IOModel >> data)
		{
			d.arr[i][j] = data;
			i++;
		}

		init_iden(I);
		Matrix output(size, 1);
		output = ((I-A).inverse()) * d;

		IOModel.close();

		cout << "For demand vector (d): " << endl;
		cout << endl;
		d.print();

		cout << "Amount of each product needed: " << endl;
		cout << endl;
		for (int i = 0; i < output.rows; i++)
		{
			cout << setw(15) << trav[i] << ": " << 
				output.arr[i][0] << " units." << endl;
		}

		delete [] trav;
		argNum++;

		}
	}
	return 0;
}

