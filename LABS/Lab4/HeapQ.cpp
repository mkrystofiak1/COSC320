//Program: HeapQ.cpp
//Author: Mitchell Krystofiak
//Description: Implementation of the HeapQ class.
//Date: February 25, 2021

#include<iostream>
#include<chrono>
using namespace std;

template<class T>
Heap<T>::Heap()
{
	int n = 101;
	length = n;
	heap_size = 0;
	arr = new HeapObj<T>[n];
}

template<class T>
Heap<T>::~Heap()
{
	delete [] arr;
}

template<class T>
HeapObj<T>& Heap<T>::operator[](int i)
{
	if (i < 0)
		i = length + i + 1;
	return arr[i-1]; 	
}

template<class T>
void Heap<T>::increase_key(T value, int i, int k) //fix to data structure
{
	if (k < arr[i].key)
	{
		cout << "New key is smaller than old key!" << endl;
		return;
	}
	arr[i].key = k;
	arr[i].data = value;
	while (i > 1 && arr[Parent(i)].key < arr[i].key)
	{
		swap(arr[i], arr[Parent(i)]);
		i = Parent(i);
	};
}

template<class T>
T Heap<T>::extract_max()
{
	T result = arr[1].data;
	arr[1] = arr[heap_size];
	heap_size = heap_size -1;
	Max_Heapify(1);
	return result;
}

template<class T>
T Heap<T>::peek()
{
	return arr[1].data;
}

template<class T>
void Heap<T>::insert(T value, int x)
{
	if (heap_size >= length)
		cout << "Error: Max heap size already." << endl;
	heap_size = heap_size + 1;
	arr[heap_size].key = -20000000;
	increase_key(value,heap_size, x);
}

template<class T>
void Heap<T>::print()
{ 
	for (int i = 1; i < length; i++)
	{
		cout << arr[i].key << " " << arr[i].data << endl;
	}
}

template<class T>
void Heap<T>::swap(HeapObj<T> &x, HeapObj<T> &y)
{
	HeapObj<T> temp = x;
	x = y;
	y = temp;
}

template<class T>
int Heap<T>::Left(int i)
{
	return 2*i;
}

template<class T>
int Heap<T>::Right(int i)
{
	return 2*i + 1;
}

template<class T>
int Heap<T>::Parent(int i)
{
	return i/2;
}

template<class T>
void Heap<T>::Build_Max_Heap()
{
	heap_size = length;
	for (int i = length/2; i >= 1; i--)
		Max_Heapify(i);
}

template<class T>
void Heap<T>::Max_Heapify(int i)
{
	int largest;
	int l = Left(i);
	int r = Right(i);
	if (l <= heap_size && arr[l].key > arr[i].key)
                largest = l;
        else
                largest = i;
        if (r <= heap_size && arr[r].key > arr[largest].key)
                largest = r;
        if (largest != i)
        {
                swap(arr[i], arr[largest]);//need to double check algorithm for swapping elements of arr
                Max_Heapify(largest);
        }	
}
template<class T>
void Heap<T>::Heap_Sort()
{
	auto start = chrono::system_clock::now();
        Build_Max_Heap();
        for (int i = length; i >= 2; i--)
        {
		cout <<"Here1" << endl;
                swap(arr[1],arr[i]); 
		cout <<"Here2" << endl;
                heap_size = heap_size -1;
		cout <<"Here3" << endl;
                Max_Heapify(1);
		cout <<"Here4" << endl;
        }
	cout << "Hereyess" << endl;
        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end-start;
        time_t end_time = chrono::system_clock::to_time_t(end);
        cout << "Heap Sort Time: " << endl;
        cout << "finished at " << ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "\n";
}

