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

double sortingAlgorithms::sort(int* arr, int n, int sel)
{
	long swaps = 0;
	chrono::duration<double> elapsed_seconds;
	//cout << "Unsorted array: ";
	//print(arr,n);
	if (sel == 1) //bubble
	{
		auto start = chrono::system_clock::now();
		swaps = bubble(arr,n);
		auto end = chrono::system_clock::now();
		elapsed_seconds = end-start;
		time_t end_time = chrono::system_clock::to_time_t(end);
		cout << "Using bubble sort: " << endl;
		cout << "finished at " << ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "\n";
	}
	else if (sel == 2) //selection
	{
		auto start = chrono::system_clock::now();
		swaps = selection(arr,n);
		auto end = chrono::system_clock::now();
		elapsed_seconds = end-start;
                time_t end_time = chrono::system_clock::to_time_t(end);
                cout << "Using selection sort: " << endl;
                cout << "finished at " << ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "\n";
	}
	else if (sel == 3) //insertion
	{
		auto start = chrono::system_clock::now();
		swaps = insertion(arr,n);
		auto end = chrono::system_clock::now();
		elapsed_seconds = end-start;
                time_t end_time = chrono::system_clock::to_time_t(end);
		cout << "Insertion sort: " << endl;
                cout << "finished at " << ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "\n";
	}
	else if (sel == 4) //quick 
	{
		auto start = chrono::system_clock::now();
		quick(arr, 0, n-1);
                auto end = chrono::system_clock::now();
                elapsed_seconds = end-start;
                time_t end_time = chrono::system_clock::to_time_t(end);
                //cout << "Quick sort: " << endl;
                //cout << "finished at " << ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "\n";
	}
	else if (sel == 5) //merge
	{
		auto start = chrono::system_clock::now();
                mergeSort(arr, 0, n-1);
                auto end = chrono::system_clock::now();
                elapsed_seconds = end-start;
                time_t end_time = chrono::system_clock::to_time_t(end);
                //cout << "Merge sort: " << endl;
                //cout << "finished at " << ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "\n";
	}
	else if (sel == 6) //r_quick
	{
		auto start = chrono::system_clock::now();
                r_quick(arr, 0, n-1);
                auto end = chrono::system_clock::now();
                elapsed_seconds = end-start;
                time_t end_time = chrono::system_clock::to_time_t(end);
                //cout << "Random quick sort: " << endl;
                //cout << "finished at " << ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "\n";
	}
	//if (is_sorted(arr,arr+n))                 //ALL COUTS CENSORED OUT FOR LAB6 DATA AGGREGATION
	//	cout << "Sorted == TRUE" << endl;
	if (sel == 1 || sel == 2 || sel == 3)
		cout << "Number of swaps used: " << swaps << endl;
	//cout << endl;
	return elapsed_seconds.count();
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
	bool swapped = true;
	while (swapped)
	{
		swapped = false;
		print(arr,n);
		for (int j = 1; j < n-1; j++)
			if (arr[j] > arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				swapped = true;
				counter++;
			}
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
	for (int i = 2; i < n; i++)
	{
		int j = i;
		while (j > 1 && arr[j] < arr[j-1])
		{
			swap(&arr[j], &arr[j-1]);
			j--;
			counter++;
		}
	}
        return counter;
}

void sortingAlgorithms::quick(int* arr, int start, int end)
{
	int j;
	if (start < end)
	{
		j = partition(arr, start, end);
		quick(arr, start, j-1);
		quick(arr, j+1, end);
	}
}

void sortingAlgorithms::r_quick(int * arr, int start, int end)
{
	int pivot, p;
	if (start < end)
	{
		p = start + (rand() % (end - start + 1));
		swap(&arr[start], &arr[p]);
		pivot = partition(arr, start, end);
		r_quick(arr, start, pivot-1);
		r_quick(arr, pivot+1, end);
	}
	
}

int sortingAlgorithms::partition(int* arr, int start, int end)
{
	int pivot = arr[end];
	int i = (start - 1);

	for (int j = start; j <= end-1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[end]);
	return (i+1);
}

void sortingAlgorithms::mergeSort(int * arr, int start, int end)
{
	int mid;
	if (start < end)
	{
		mid = (start+end)/2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

void sortingAlgorithms::merge(int * arr, int start, int mid, int end)
{
	int i, j, k, a, b;
	a = mid-start+1;
	b = end - mid;
	int * L1 = new int[a];
	int * L2 = new int[b];

	for (i = 0; i<a; i++)
		L1[i] = arr[start+i];
	for (j = 0; j<b; j++)
		L2[j] = arr[mid+1+j];
	i = 0;
	j = 0;
	k = start; //**********
	while(i < a && j < b)
	{
		if (L1[i] <= L2[j])
		{
			arr[k] = L1[i];
			i++;
		}
		else
		{
			arr[k] = L2[j];
			j++;
		}
		k++;
	}
	while(i<a)
	{
		arr[k] = L1[i];
		i++;
		k++;
	}
	while(j<b)
	{
		arr[k] = L2[j];
		j++;
		k++;
	}

	delete [] L1;
	delete [] L2;
}
