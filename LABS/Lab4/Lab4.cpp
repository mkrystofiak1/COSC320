//Program: Lab4.cpp
//Author: Mitchell Krystofiak
//Description: This program will test the functionality of the Heap class.
//Date: February 24, 2021

#include<iostream>
#include"HeapQ.h"
#include<ctime>
#include<string>
#include<chrono>
#include<cstdlib>

using namespace std;

int main() 
{
	srand(time(0));
	int random;
	Heap<string> list;
	string names[10] = {"john", "james", "mitch", "joe", "alex", "megan", "sam", "felix", "kate", "george"};
	
	auto start = chrono::system_clock::now();

	for (int i = 1; i <= 100; i++)//random allocation of names
	{
		random = rand() % 100 + 1; //sets a random priority for testing
		int random1 = rand() %10;
		list.insert(names[random1], random);
	}
	
	auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end-start;
        time_t end_time = chrono::system_clock::to_time_t(end);
        cout << "Allocation Time: " << endl;
        cout << "finished at " << ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "\n";

	cout << "-----Max Heap-----" << endl;
	list.print();
	
	cout << "Extract max until the end" << endl;
	cout << endl;

	for (int i = 1; i <= 100; i++)
		cout << list.extract_max() << endl;
	
	
	return 0;
}
