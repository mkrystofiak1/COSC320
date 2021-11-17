//Program: quick.sort
//Author: Mitchell Krystofiak
//Description: Uses the quicksort and merge sort algorithms to sort arrays.
//Date: February 11, 2021

#include<iostream>
#include"sortingAlgorithms.h"
#include<ctime>
using namespace std;

int main()
{
	srand(time(0));
	sortingAlgorithms sort;
	int n;

	cout << "Enter the size of the array: ";
	cin >> n;

	if (n <= 0)
	{
		cout << "Invalid array size, terminating program." << endl;
		return 1;
	}

	int *arr = new int[n];
	int *copy1 = new int[n];
	
	for (int i = 0; i < n; i++)
		arr[i] = copy1[i] = i;
	cout << "-----Already sorted-----" << endl;
	
	//Quick sort
	sort.sort(arr,n,4);
	//Merge sort
	sort.sort(copy1,n,5);
	int j = 0;
	for (int i = n-1; i >= 0; i--)
	{
		arr[j] = copy1[j] = i;
		j++;
	}
	cout << "-----Reverse order-----" << endl;
	
	//Quick sort
	sort.sort(arr,n,4);
	
	//Merge sort
	sort.sort(copy1,n,5);
	
	for (int i = 0; i < n; i++)
		arr[i] = copy1[i] = rand() % 1000;
	cout << "-----Randomly filled-----" << endl;
	
	//Quick sort
	sort.sort(arr,n,4);
	//Merge sort
	sort.sort(copy1,n,5);

	int rep;
	for (int i = 0; i < n; i++)
	{
		if (i % 10 == 0)
			rep = rand() % 1000;
		arr[i] = copy1[i] = rep;
	}
	cout << "-----Multiple duplicates-----" << endl;
	
	//Quick sort
	sort.sort(arr,n,4);
	//Merge sort
	sort.sort(copy1,n,5);
	
	delete [] arr;
	delete [] copy1;	
	return 0;
}
