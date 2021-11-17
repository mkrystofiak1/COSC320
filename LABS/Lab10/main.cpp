//Program: main.cpp
//Author: Mitchell Krystofiak
//Description: A program to test the functionality of the graph class.
//Date: April 22, 2021

#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
	Graph<int> G;
	
	cout << "Testing addVertex" << endl;
	cout << "-----------------" << endl;
	cout << endl;
	cout << "Adding 1" << endl;	
	G.addVertex(1);
	cout << "Adding 2" << endl;
	G.addVertex(2);
	cout << "Adding 3" << endl;
	G.addVertex(3);
	cout << "Adding 10" << endl;
	G.addVertex(10);
	cout << "Adding 5" << endl;
	G.addVertex(5);
	cout << endl;
	
	cout << "Graph print: " << endl;
	G.print();
	cout << endl;
	
	cout << "Testing addEdge" << endl;
	cout << "---------------" << endl;
	cout << endl;
	cout << "Adding edge between 1 and 1" << endl;
	G.addEdge(1,1);
	cout << "Adding edge between 1 and 2" << endl;
	G.addEdge(1,2);
	cout << "Adding edge between 1 and 3" << endl;
	G.addEdge(1,3);
	cout << "Adding edge between 2 and 3" << endl;
	G.addEdge(2,3);
	cout << "Adding edge between 3 and 1" << endl;
	G.addEdge(3,1);
	cout << "Adding edge between 10 and 3" << endl;
	G.addEdge(10,3);
	cout << "Adding edge between 5 and 2" << endl;
	G.addEdge(5,2);
	cout << "Adding edge between 3 and 10" << endl;
	G.addEdge(3,10);
	cout << "Adding edge between 3 and 5" << endl;
	G.addEdge(3,5);
	cout << endl;
	
	cout << "Graph print: " << endl;
	G.print();
	cout << endl;

	cout << "Testing extreme adding cases" << endl;
	cout << "----------------------------" << endl;
	cout << endl;
	cout << "Adding 1 (repeat)" << endl;
	G.addVertex(1);
	cout << "Adding 10 (repeat)" << endl;
	G.addVertex(10);
	cout << "Adding edge between 1 and 1 (repeat)" << endl;
	G.addEdge(1,1);
	cout << "Adding edge between 2 and 3 (repeat)" << endl;
	G.addEdge(2,3);
	cout << endl;
	
	cout << "Graph print: " << endl;
	G.print();
	cout << endl;
	
	cout << "Testing BFS algorithm" << endl;
	cout << "---------------------" << endl;
	cout << endl;
	G.printBFS(1);

	cout << "Creating new graph for the in class example" << endl;
	cout << "and the functionality of the templating    " << endl;
	cout << "-------------------------------------------" << endl;
	cout << endl;
	Graph<char> X;
	X.addVertex('A');
	X.addVertex('B');
	X.addVertex('C');
	X.addVertex('D');
	X.addVertex('E');
	X.addVertex('F');
	X.addVertex('G');
	X.addVertex('H');
	cout << endl;

	cout << "Graph print: " << endl;
	X.print();
	cout << endl;
	
	X.addEdge('A','B');
	X.addEdge('B','A');
	X.addEdge('B','C');
	X.addEdge('C','B');
	X.addEdge('A','E');
	X.addEdge('E','A');
	X.addEdge('E','F');
	X.addEdge('F','E');
	X.addEdge('E','B');
	X.addEdge('B','E');
	X.addEdge('F','D');
	X.addEdge('D','F');
	X.addEdge('C','G');
	X.addEdge('G','C');
	X.addEdge('G','D');
	X.addEdge('D','G');
	X.addEdge('G','H');
	X.addEdge('H','G');

	cout << "Graph print: " << endl;
	X.print();
	cout << endl;
	
	cout << "Testing BFS algorithm" << endl;
	cout << "---------------------" << endl;
	cout << endl;
	X.printBFS('A');
	return 0;
}
