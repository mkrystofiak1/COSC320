//Program: SortingAlgorithms.h
//Author: Mitchell Krystofiak
//Description: Header file for the 3 sorting algorithms.
//Date: February 4, 2021

#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include<iostream>

using namespace std;

class sortingAlgorithms
{
	public:
		sortingAlgorithms();
		void swap(int *x, int *y);
		void sort(int* arr, int n, int sel);
		void print(int* arr, int n);
		long bubble(int* arr, int n);
		long selection(int* arr, int n);
		long insertion(int* arr, int n);


};

#endif
