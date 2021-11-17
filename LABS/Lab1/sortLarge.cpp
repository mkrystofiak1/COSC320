//Program: sortLarge.cpp
//Author: Mitchell Krystofiak
//Description: Soring test mk. 2, created after the first one refused to process large arrays.
//Date: February 4, 2021


#include<iostream>
#include<ctime>
#include<algorithm>
#include<cstdlib>
#include"sortingAlgorithms.h"

using namespace std;

int main() {

	srand(time(0));

	int n;
	sortingAlgorithms sort;
	cout << "Enter an array size: ";
	cin >> n;
	
	int* arr = new int[n];
	int* copy = new int[n];
	int* copy1 = new int[n];
	int j = n;

	cout << "Reverse order / Worst case \n";

	for (int i = 0; i < n ; i++)
	{
		arr[i] = j;
		copy[i] = j;
		copy1[i] = j;
		j--;
	}

	sort.sort(arr, n, 1);
	sort.sort(copy, n, 2);
	sort.sort(copy1, n, 3);	

	cout << "In order / Best case \n";

	j = 1;
	for (int i = 0; i < n; i++)
	{
		arr[i] = j;
		copy[i] = j;
		copy1[i] = j;
		j++;
	}
	sort.sort(arr, n, 1);
	sort.sort(copy, n, 2);
	sort.sort(copy1, n, 3);

	cout << "Random order / Average case \n";

	for (int i = 0; i < n; i++)
	{
		arr[i] = (rand() % 1000);
		copy[i] = arr[i];
		copy1[i] = arr[i];
	}
	sort.sort(arr, n, 1);
	sort.sort(copy, n, 2);
	sort.sort(copy1, n, 3);

	cout << "Many duplicates \n";

	int random = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 10 == 0)
			random = (rand() % 1000);
		arr[i] = random;
		copy[i] = random;
		copy1[i] = random;
		random++;
	}
	sort.sort(arr, n, 1);
	sort.sort(copy, n, 2);
	sort.sort(copy1, n, 3);	
	delete [] arr;
	delete [] copy;
	delete [] copy1;

	return 0;
}
