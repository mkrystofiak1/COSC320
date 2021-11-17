//Program: Lab3.cpp
//Author: Mitchell Krystofiak
//Description: A program to test the functionality of the heap class.
//Date: February 18, 2021

#include"Heap.h"
#include<iostream>

using namespace std;

int main()
{
	int n;
	cout << "Enter the size of the heap: ";
	cin >> n;
	while (n < 1)
	{
		cout << "Invalid size." << endl;
		cout << "Enter the size of the heap: ";
		cin >> n;
	}
	Heap A;
	A.length = n;
	A.heap_size = n;
	A.arr = new int[A.length];

	cout << "----------In Order----------" << endl;

	Fill_Array(A, 1);
	cout << "Initial Heap: " << endl;
	Print_Heap(A);
	cout << "STILL IN PROGRESS HEAP" << endl;
	Print_Heap_2(A,1,1);	
	cout << endl;
	
	Build_Max_Heap(A);
	cout << "Max Heap: "<< endl;
	Print_Heap(A);
	cout << endl;

	Heap_Sort(A);
	cout << "Sorted Heap: " << endl;
	Print_Heap(A);	
	cout << endl;
	
	delete [] A.arr;
	
	cout << "----------Reverse Order----------" << endl;

	A.arr = new int[A.length];

	Fill_Array(A, 2);
        cout << "Initial Heap: " << endl;
	Print_Heap(A);
        cout << endl;

        Build_Max_Heap(A);
        cout << "Max Heap: " << endl;
        Print_Heap(A);
        cout << endl;

        Heap_Sort(A);
        cout << "Sorted Heap: " << endl;
        Print_Heap(A);
        cout << endl;

        delete [] A.arr;
	
	cout << "----------Random Order----------" << endl;

        A.arr = new int[A.length];

        Fill_Array(A, 3);
        cout << "Initial Heap: " << endl;
        Print_Heap(A);
        cout << endl;

        Build_Max_Heap(A);
        cout << "Max Heap: " << endl;
        Print_Heap(A);
        cout << endl;

        Heap_Sort(A);
        cout << "Sorted Heap: " << endl;
        Print_Heap(A);
        cout << endl;

        delete [] A.arr;	
	return 0;
}

