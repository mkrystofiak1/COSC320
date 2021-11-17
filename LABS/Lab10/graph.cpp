//Program: graph.cpp
//Author: Mitchell Krystofiak
//Description: Implementation of the graph class.
//Date: April 22, 2021

#include "graph.h"

//Useful vertex functions: begin, end, size, empty, push_back, pop_back, insert
//			   erase, swap
//
//Useful map functions: begin, end, empty, size, insert, erase, swap, find, lower_bound
//			higher_bound
//
//Useful queue functions: empty, size, front, back, push, emplace, pop, swap

enum color_t { WHITE, GRAY, BLACK };

template<class T>
Graph<T>::Graph() {}

template<class T>
Graph<T>::Graph(const Graph & old)
{
	this->vertices = old.vertices;
}
template<class T>
Graph<T>::~Graph() {}

template<class T>
void Graph<T>::operator=(const Graph & old)
{
	this->vertices = old.vertices;
}

template<class T>
void Graph<T>::addVertex(T x)
{
	auto search = this->vertices.find(x);

	if (search == this->vertices.end())
	{
		std::vector<T> list;
		this->vertices.insert({x, list});
	}

	else
		 std::cout << "Vertex " << x << " is already in the graph!" << std::endl;
}

template<class T>
void Graph<T>::addEdge(T x, T y)
{
	if (vertices.find(x) != vertices.end())
	{
		if (vertices.find(y) != vertices.end())
		{
			bool exists = false;

			for (auto j = vertices[x].begin(); j != vertices[x].end(); j++)
			{
				if (*j == y)
				{
					exists = true;
					break;
				}
			}
			if (!exists)
				vertices[x].push_back(y);
			else
				std::cout << "The edge pointing from " << x << " to " << y << " already exists!" << std::endl;
		}
		else
			std::cout << "Vertex " << y << " does not exist! Cannot create edge!" << std::endl;
		}
	else
		std::cout << "Vertex " << x << " does not exist! Cannot create edge!" << std::endl;
}

template<class T>
void Graph<T>::print()
{
	int size = vertices.size();

	for (auto i = vertices.begin(); i != vertices.end(); i++)
	{
		std::cout << "Vertex: " << i->first << " Points to: ";
		for (auto j = i->second.begin(); j != i->second.end(); j++)
			std::cout << *j << " ";
		std::cout << std::endl;
	}
}

template<class T>
void Graph<T>::printBFS(T x)
{
	//Tracking the colors, distances and parents.
	std::map<T, color_t> color;
	std::map<T, int> distance;
	std::map<T, T> parent;

	//1. Set each vertex color to white,
	//   set u.distance = inf, and set u.p
	//   = null.
	for (auto i = this->vertices.begin(); i != this->vertices.end(); i++)
	{
		color.insert({i->first, WHITE});
		parent.insert({i->first, -999});
		distance.insert({i->first, 999999999999});
	}
	
	//2. Set x.color = gray, s.d = 0, s.p = nil.
	color[x] = GRAY;
	distance[x] = 0;
	
        //3. Let Q be an empty queue.
        std::queue<T> Q;

	//4. Enqueue x.
	Q.push(x);

	//5. While Q not empty, run algorithm
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();

		for (auto v = this->vertices[u].begin(); v != this->vertices[u].end(); v++)
		{
			if (color[*v] == WHITE)
			{
				color[*v] = GRAY;
				distance[*v] = distance[u] + 1;
				parent[*v] = u;
				Q.push(*v);
			}
			color[u] = BLACK;
		}
	}

	auto c = color.begin();
	auto p = parent.begin();
	auto d = distance.begin();
	
	std::cout << "Breadth First Search Print" << std::endl;
	std::cout << std::endl;
	std::cout << "Root: " << x << std::endl;
	std::cout << "Note: 0 = White, 1 = Gray, 2 = Black" << std::endl;
	std::cout << "--------------------------" << std::endl;

	while (c != color.end())
	{
		std::cout << "Vertex discovered: " << c->first << std::endl;
		std::cout << "Parent: " << p->second << std::endl;
		std::cout << "Color: " << c->second << std::endl;
		std::cout << "Distance from root: " << d->second << std::endl;
		std::cout << std::endl;
		c++;
		p++;
		d++;
	}
}
