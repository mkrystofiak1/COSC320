/*
 * Program: hiring.cpp
 * Author: Mitchell Krystofiak
 * Description: This lab will test the fucntionality of the random
 *              quicksort function with the hiring problem.
 * Date: 03/18/2021
 */

#include<iostream>
#include"Heap.h"
#include"sortingAlgorithms.h"
#include<ctime>
using namespace std;

int * shuffle(int * arr,int n)
{
	srand(time(0));

	for (int i = 0; i < n; i++)//in order array  1->n
		arr[i] = i + 1;	
	
	int k = rand() % n; //random index of array
	for (int i = 0; i < n; i++)
	{
		swap(arr[i], arr[k]);
		k = rand() % n;
	}
	return arr;
}	

int hiring_algorithm(int * arr, int n, int &count)
{
	int best = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] > arr[best])
		{
			best = i;
			count++;
		}
	return best;
}


int main()
{
	srand(time(0));
	
	sortingAlgorithms sort; //for quick sort, random quick sort, merge sort
	Heap heap; //for heap sort

	int n; //size of n
	int count = 0; //number of times hired
	double sum = 0; //sum of counts
	int * arr; //array for hiring algorithm
	int * quick_copy;
	int * r_quick_copy;

	//Task 3, 10 n's
	for (int i = 0; i < 10; i++)
	{
		count = 0;
		n = rand() % 1000000 + 10; //between 10 and 1,000,000 candidates 
		cout << "Sample " << i << " = " << n << endl;
		arr = new int[n];
		arr = shuffle(arr, n);
		hiring_algorithm(arr,n,count);
		cout << "Number of hires: " << count << endl;
		sum = sum + count;
		delete [] arr;
	}
	double average = sum/10;
	cout << "Average number of hires = " <<  average << endl;	
	cout << endl;

	//Task 6 using quick, r_quick, merge, heap
	
	double sumq = 0;  //quick sort sum
	double sumrq = 0; //random quick sort sum
	double summ = 0;  //merge sort sum
	double sumh = 0;  //heap sort sum
	count = 0;
	double tempq, temprq, tempm, temph;
	//**************************************************
	//
	//NOTE: ALL COUT'S HAVE BEEN COMMENTED OUT FOR LAB6 PURPOSES
	//      IN ALL OF THE SORTING ALGORITHMS FOR JUST WHAT WE 
	//      WANT. ALSO, THEY HAVE BEEN MADE TO RETURN THE TIME
	//      THAT IS REPORTED FOR SUMMING PURPOSES
	//
	//**************************************************
	for (int i = 10000; i < 1000000; i = i + 50000)
	{
		count++;
		arr = new int[i];          //allocates new dynamic arrays equal to origional shuffle
		quick_copy = new int[i];   // - there may be a more efficient way to do this
		r_quick_copy = new int[i]; // - at least there are no memory leaks with this though
		heap.length = i;
		heap.heap_size = i;
		heap.arr = new int[i];
		arr = shuffle(arr,i);
		for (int j = 0; j < i; j++)
			quick_copy[j] = r_quick_copy[j] = heap.arr[j] = arr[j];
		tempq = sort.sort(quick_copy, i, 4);	
		temprq = sort.sort(r_quick_copy, i, 6);
		tempm = sort.sort(arr, i, 5);
		temph = Heap_Sort(heap);
		sumq = sumq + tempq;             //quick sort sum
		sumrq = sumrq + temprq;         //random quick sort sum
		summ = summ + tempm;           //merge sort sum
		sumh = sumh + temph;	       //heap sort sum
		
		cout << "Sample size: " << i << endl;
		cout << "Quick: " << tempq << endl;
		cout << "R_Quick: " << temprq << endl;
		cout << "Merge: " << tempm << endl;
		cout << "Heap: " << temph << endl;
		cout << endl;
		delete [] arr;
		delete [] quick_copy;
		delete [] r_quick_copy;
		delete [] heap.arr;	
	}
	
	double averageq = sumq/count;
	double averagerq = sumrq/count;
	double averagem = summ/count;
	double averageh = sumh/count;
	
	cout << "Number of times n changed: " << count << endl;
	cout << "The average time it takes for quick sort is " << averageq << " seconds." << endl;
	cout << "The average time it takes for random quick sort is " << averagerq << " seconds." << endl;
	cout << "The average time it takes for merge sort is " << averagem << " seconds." << endl;
	cout << "The average time it takes for heap sort is " << averageh << " seconds." << endl;

	return 0;
}
