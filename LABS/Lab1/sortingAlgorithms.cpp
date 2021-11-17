//Program: sortingAlgorithms.cpp
//Author: Mitchell Krystofiak
//Description: Implementation of the bubble, insertion and selection sorting algorithms.
//Date: February 4, 2020

#include<iostream>
#include "sortingAlgorithms.h"
#include<chrono>
#include<algorithm>
using namespace std;

sortingAlgorithms::sortingAlgorithms() { }

void sortingAlgorithms::swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void sortingAlgorithms::sort(int* arr, int n, int sel)
{
	long swaps = 0;
	//cout << "Unsorted array: ";
	//print(arr,n);
	if (sel == 1) //bubble
	{
		auto start = chrono::system_clock::now();
		swaps = bubble(arr,n);
		auto end = chrono::system_clock::now();
		chrono::duration<double> elapsed_seconds = end-start;
		time_t end_time = chrono::system_clock::to_time_t(end);
		cout << "Using bubble sort: " << endl;
                //print(arr,n);
		cout << "finished at " << ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "\n";
	}
	else if (sel == 2) //selection
	{
		auto start = chrono::system_clock::now();
		swaps = selection(arr,n);
		auto end = chrono::system_clock::now();
		chrono::duration<double> elapsed_seconds = end-start;
                time_t end_time = chrono::system_clock::to_time_t(end);
                cout << "Using selection sort: " << endl;
		//print (arr,n);
                cout << "finished at " << ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "\n";
	}
	else if (sel == 3) //insertion
	{
		auto start = chrono::system_clock::now();
		swaps = insertion(arr,n);
		auto end = chrono::system_clock::now();
		chrono::duration<double> elapsed_seconds = end-start;
                time_t end_time = chrono::system_clock::to_time_t(end);
		cout << "Insertion sort: " << endl;
                //print (arr,n);
                cout << "finished at " << ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "\n";
	}
	if (is_sorted(arr,arr+n))
		cout << "Sorted == TRUE" << endl;
	cout << "Number of swaps used: " << swaps << endl;
	cout << endl;
}

void sortingAlgorithms::print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

long sortingAlgorithms::bubble(int* arr, int n)
{
	long counter = 0;
        for (int i = 0; i < n-1; i++)
                for (int j = 0; j < n-i-1; j++)
                        if (arr[j] > arr[j+1])
                        {
                                swap(&arr[j], &arr[j+1]);
                                counter++;
                        }
        return counter;
}

long sortingAlgorithms::selection(int* arr, int n)
{
	long counter = 0;
        for (int i = 0; i < n-1; i++)
        {
                int min = i;
                for (int j = i+1; j < n; j++)
                        if (arr[j] < arr[min])
                                min = j;
                swap(&arr[i], &arr[min]);
                counter++;
        }
        return counter;
}

long sortingAlgorithms::insertion(int* arr, int n)
{
	long counter = 0;
        for (int i = 1; i < n; i++)
        {
                int key = arr[i];
                int j = i-1;
                while (j >= 0 && arr[j] > key)
                {
                        arr[j+1] = arr[j];
                        j--;
                }
                arr[j+1] = key;
                counter++;
        }
        return counter;
}

