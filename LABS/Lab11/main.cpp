//Program: main.cpp
//Author: Mitchell Krystofiak
//Description: Testing algorithm for:
//	       - Depth First Search (DFS)
//	       - Topological Sort
//	       - Adding Vertices/Edges
//	       - Adjacency List Printing (if time permits)
//	       - Directed Acyclic Graphs (DAG)
//Date: April 28, 2021

#include <iostream>
#include "graph.h"
#include <fstream>

using namespace std;

Graph<int> buildGraph(char * filename)
{
	ifstream infile(filename);
	if (!infile)
		cout << "Error reading file!" << endl;
	else
	{
		int direction;
		infile >> direction; //first line is enumerated value of direction, 0 = undirected, 1 = directed
		Graph<int> K(direction);
		std::vector<int> vect;
		int read = 0;
		while (infile >> read)
		{
			K.addVertex(read);
			vect.push_back(read);
		}
		infile.clear();
		int i = 0;
		while (infile >> read)
		{
			if (read == -1)
			{
				i++;
				continue;
			}
			K.addEdge(vect[i], read);
		}
		return K;
	}
}				

int main(int argc, char * argv[])
{
	if (argc > 2)
	{
		cout << "Argument Error: Too many arguments!" << endl;
		return 1;
	}
	else if (argc == 1) //demo version
	{
		Graph<int> G(UNDIRECTED);
		Graph<int> H(DIRECTED);
		cout << "--------------------------------------------------" << endl;
		cout << "We will test the capabilities of the program using" << endl;
		cout << "an undirected graph (G) and a directed graph (H). " << endl;
		cout << "--------------------------------------------------" << endl;
		cout << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Testing getGraphType(), which returns 0 for" << endl;
		cout << "undirected and 1 for directed.             " << endl;
		cout << "-------------------------- ----------------" << endl;
		cout << endl;

		cout << "Graph G is ";
		if (G.getGraphType() == 0)
			cout << "Undirected." << endl;
		cout << "Graph H is ";
		if (H.getGraphType() == 1)
			cout << "Directed." << endl;
		cout << endl;

		cout << "--------------------" << endl;
		cout << "Testing addVertex()." << endl;
		cout << "--------------------" << endl;
		cout << endl;
		cout << "Adding 8 vertices, 1 - 8. " << endl;	
		for (int i = 1; i <= 8; i++)
		{
			G.addVertex(i);
			H.addVertex(i);
		}
		cout << "Graph G: " << endl;
		G.print();
		cout << endl;
		cout << "Graph H: " << endl;
		H.print();
		cout << endl;

		cout << "----------------------------------" << endl;
		cout << "Testing adding duplicate vertices." << endl;
		cout << "----------------------------------" << endl;
		cout << endl;
		cout << "Graph G: " << endl;
		G.addVertex(7);
		G.addVertex(2);
		G.addVertex(8);
		cout << endl;
		cout << "Graph H: " << endl;
		H.addVertex(7);
		H.addVertex(2);
		H.addVertex(8);
		cout << endl;

		cout << "------------------" << endl;
		cout << "Testing addEdge()." << endl;
		cout << "------------------" << endl;
		cout << endl;
		G.addEdge(1,2);
		G.addEdge(1,1);
		G.addEdge(1,5);
		G.addEdge(1,6);
		G.addEdge(6,3);
		G.addEdge(3,4);
		G.addEdge(4,8);
		G.addEdge(3,7);
		G.addEdge(7,4);
		cout << "Graph G: " << endl;
		G.print();
		cout << endl;
		H.addEdge(1,2);
		H.addEdge(1,5);
		H.addEdge(5,6);
		H.addEdge(6,3);
		H.addEdge(3,4);
		H.addEdge(3,7);
		H.addEdge(7,8);
		cout << "Graph H: " << endl;
		H.print();
		cout << endl;
		cout << "Notice how H is directed, and acyclic, or a DAG, for the sake of topological sort!" << endl;
		cout << "Also notice how the edges in G reciprocate because they are undirected and how the" << endl;
		cout << "edges in H don't." << endl;
		cout << endl;

		cout << "-------------------------------" << endl;
		cout << "Testing adding duplicate edges." << endl;
		cout << "-------------------------------" << endl;
		cout << endl;
		cout << "Graph G: " << endl;
		G.addEdge(1,2);
		G.addEdge(1,5);
		cout << endl;
		cout << "Graph H: " << endl;
		H.addEdge(1,2);
		H.addEdge(1,5);
		cout << endl;

		cout << "---------------------------" << endl;
		cout << "Testing Depth First Search." << endl;
		cout << "---------------------------" << endl;	
		cout << endl;
		cout << "Graph G: " << endl;
		G.printDFS(1);
		cout << endl;
		cout << "Graph H: " << endl;
		H.printDFS(1);
		cout << endl;

		cout << "-------------------------" << endl;
		cout << "Testing Topological Sort." << endl;
		cout << "-------------------------" << endl;
		cout << endl;
		cout << "Graph G: " << endl;
		G.topSortPrint();
		cout << endl;
		cout << "Graph H: " << endl;
		H.topSortPrint();
		cout << endl;

		cout << "--------------------------------------" << endl;
		cout << "Testing Strongly Connected Components." << endl;
		cout << "--------------------------------------" << endl;
		cout << endl;
		cout << "Graph G: " << endl;
		G.SCCprint();
		cout <<	endl;
		cout << "Graph H: " << endl;
		H.SCCprint();
		cout << endl;
	}
	else //input file
	{
		cout << "---------------------------" << endl;
		cout << "Using file generated graph." << endl;
		cout << "---------------------------" << endl;
		cout << endl;
		Graph<int> K = buildGraph(argv[1]);
		cout << "Graph K vertices and edges: " << endl;
		K.print();
		cout << endl;
		cout << "---------------" << endl;
		cout << "Performing DFS." << endl;
		cout << "---------------" << endl;
		cout << endl;
		K.printDFS(1);
		cout << endl;
		cout << "----------------------------" << endl;
		cout << "Performing Topological Sort." << endl;
		cout << "----------------------------" << endl;
		cout << endl;
		K.topSortPrint();
		cout << endl;
		cout << "-----------------" << endl;
		cout << "Performing SCC's." << endl;
		cout << "-----------------" << endl;
		cout << endl;
		K.SCCprint();
		cout << endl;
	}	
	return 0;
}
