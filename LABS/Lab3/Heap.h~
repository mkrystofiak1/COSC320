//Program: Heap.h
//Author: Mitchell Krystofiak
//Description: Header file for the heap class.
//Date: February 18, 2021

#ifndef HEAP_H
#define HEAP_H

#include<iostream>

using namespace std;

struct Heap
{
	int * arr; //underlying array
	int length; // size of array
	int heap_size;
	int& operator[](int i)
	{
		if (i < 0)
		{
			i = length + i + 1;
		}

		return arr[i-1];
	}
};

//Prototypes

void swap(int *, int *);
int Left(int i);
int Right(int i);
int Parent(int i);

void Fill_Array(Heap A, int);
void Build_Max_Heap(Heap A);
void Heap_Sort(Heap A);
void Print_Heap(Heap A);
void Print_Heap_2(Heap A, int, int);

#endif
