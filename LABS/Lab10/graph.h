//Program: graph.h
//Author: Mitchell Krystofiak
//Description: Graph class definition.
//Date: April 22, 2021

#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <vector>
#include <queue>
#include <iostream>

//Project 3 thoughts
//For isomorphism class, maybe have an overloaded operator == to compare two graphs.
//If graphs are equal, then we automatically have an automorphism. Implement BFS for
//the isomorphism searching, then we can check for "edge preserving" isomorphisms.
template <class T>
class Graph
{
	private:	
		std::map<T, std::vector<T>> vertices;
	
	public:
		//Constructor - Copy Constructor - Destructor

		Graph();
		Graph(const Graph &);
		~Graph();

		// operator=
		
		void operator=(const Graph &);

		//addVertex - addEdge - print - printBFS

		void addVertex(T);
		void addEdge(T, T);
		void print();
		void printBFS(T);
};

#include "graph.cpp"
#endif
