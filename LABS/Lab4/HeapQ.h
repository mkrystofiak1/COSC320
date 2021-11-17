//Program: HeapQ.h
//Author: Mitchell Krystofiak
//Description: Definition of the HeapQ template class.
//Date: February 25, 2021

#ifndef HEAPQ_H
#define HEAPQ_H

template <class T>
struct HeapObj {
	T data;
	int key;
};

template <class T>
class Heap {

	private:

		HeapObj<T> * arr;
		int length;
		int heap_size;
		HeapObj<T>& operator[](int i);
		void increase_key(T,int, int);

		void swap(HeapObj<T> &, HeapObj<T> &);
		int Left(int);
		int Right(int);
		int Parent(int);
	public:
		//constructor
		Heap();
		//deconstructor
		~Heap();
		//new functions
		
		T extract_max(); //extracts the maximum element, similar to dequeue
		T peek(); //displays the top of the queue
		void insert(T, int); // inserts a new item into the Heap
		void print(); //Displays the current contents of the Heap
		
		//old functions	

		void Build_Max_Heap();
		void Max_Heapify(int);
		void Heap_Sort();

};
#include"HeapQ.cpp"
#endif
