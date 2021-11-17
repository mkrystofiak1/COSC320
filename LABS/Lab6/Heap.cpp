//Program: Heap.cpp
//Author: Mitchell Krystofiak
//Description: Implementation of the Heap class.
//Date: February 18, 2021

#include<iostream>
#include"Heap.h"
#include<ctime>
#include<cmath>
#include<chrono>
#include<algorithm>
using namespace std;
	
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int Left(int i)
{
	return 2*i;
}

int Right(int i)
{
	return 2*i + 1;
}

int Parent(int i)
{
	return i/2;
}

void Fill_Array(Heap A, int sel)
{
	if (sel == 1) //in order
	{
		for (int i = 1; i <= A.length; i++)
			A[i] = i;
	}
	else if (sel == 2) //reverse order
	{
		int rev = A.length;
		for (int i =1; i <= A.length; i++)
		{
			A[i] = rev;
			rev--;
		}
	}
	else if (sel == 3)
	{
		srand(time(0));
		for (int i = 1; i <= A.length; i++)
                	A[i] = rand() % 1000;
	}
}

void Max_Heapify(Heap A, int i)
{
	int largest;
	int l = Left(i);
	int r = Right(i);
	//heap[i] calls
	if (l <= A.heap_size && A[l] > A[i])
		largest = l;
	else
		largest = i;
	if (r <= A.heap_size && A[r] > A[largest])
		largest = r;
	if (largest != i)
	{
		swap(A[i], A[largest]);
		Max_Heapify(A,largest);
	}
}

void Build_Max_Heap(Heap A)
{
	A.heap_size = A.length;
	for (int i = A.length/2; i >= 1; i--)
		Max_Heapify(A,i);
}

double Heap_Sort(Heap A)
{
	auto start = chrono::system_clock::now();
	Build_Max_Heap(A);
	for (int i = A.length; i >= 2; i--)
	{
		swap(A[1],A[i]);
		A.heap_size = A.heap_size -1;
		Max_Heapify(A,1);
	}
	auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end-start;
        time_t end_time = chrono::system_clock::to_time_t(end);
	//cout << "Heap Sort Time: " << endl;
	//cout << "finished at " << ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "\n";
	//if (is_sorted(A.arr,A.arr+A.length))
	//	cout << "Sorted == TRUE" << endl; //CENSORED OUT FOR LAB6 DATA AGGREGATION
	return elapsed_seconds.count();
}

void Print_Heap(Heap A)
{
	for (int i = 1 ; i <= A.length; i++)
		cout << A[i] << " ";
	cout << endl;
}

void Print_Heap_2(Heap A, int height, int node)
{
	for (int i = 0; i < A.length ; i++)
	{
		cout << A[i];
		if (i == pow(2, height))
		{
			cout << endl;
			height++;
		}
	}
}	
