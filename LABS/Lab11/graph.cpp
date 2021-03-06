//Program: graph.cpp
//Author: Mitchell Krystofiak
//Description: Implementation of the graph class.
//Date: April 22, 2021

#include "graph.h"
#include <algorithm>

//Useful vertex functions: begin, end, size, empty, push_back, pop_back, insert
//			   erase, swap
//
//Useful map functions: begin, end, empty, size, insert, erase, swap, find, lower_bound
//			higher_bound
//
//Useful queue functions: empty, size, front, back, push, emplace, pop, swap

template<class T>
Graph<T>::Graph() 
{
	this->graph_t = UNDIRECTED;
	this->time = 0;
	this->isDAG = false;
}

template<class T>
Graph<T>::Graph(const graph_type & t)
{
	this->graph_t = t;
	this->time = 0;
	if (this->graph_t == DIRECTED)
		this->isDAG = true;
	else
		this->isDAG = false;
}

template<class T>
Graph<T>::Graph(const Graph & old)
{
	this->graph_t = old.graph_t;
	this->vertices = old.vertices;
	this->time = old.time;
	this->isDAG = old.isDAG;
}
template<class T>
Graph<T>::~Graph() {}

template<class T>
void Graph<T>::operator=(const Graph & old)
{
	this->graph_t = old.graph_t;
	this->vertices = old.vertices;
	this->time = old.time;
	this->isDAG = old.isDAG;
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
			{
				//happens regardless of directed/undirected
				vertices[x].push_back(y);
				//if the graph is undirected, we will reverse the relationship
				if (graph_t == UNDIRECTED && vertices[x] != vertices[y])
					vertices[y].push_back(x);
			}
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

template<class T>
void Graph<T>::DFSvisit(int u, int print, std::map<int, color_t> & color, std::map<int, int> & parent)
{
	this->time++;
	this->discovery[u] = this->time;
	color[u] = GRAY;
	for (auto i = this->vertices[u].begin(); i != this->vertices[u].end(); i++)
	{
		if (color[*i] == WHITE)
		{
			parent[*i] == WHITE;
			this->DFSvisit(*i, print, color, parent);
		}
		if (color[*i] == GRAY)
			this->isDAG = false;
	}
	if (print == 1)
	{
		for (int i : vertices[u])
			std::cout << i << " ";
	}
	color[u] = BLACK;
	this->time++;
	this->finish[u] = this->time;
}

template<class T>
void Graph<T>::printDFS(int print)
{
	if (this->is_empty())
		return;
	
	std::map<int, color_t> color;
	std::map<int, int> parent;
	if (print == 1) //if we want to print the words
	{
		std::cout << "Depth First Search Print" << std::endl;
		std::cout << std::endl;
	}

	for (auto i = this->vertices.begin(); i != this->vertices.end(); i++)
	{
		color.insert({i->first, WHITE});
		parent.insert({i->first, -9999999999});
	}
	this->time = 0;

	for (auto i = this->vertices.begin(); i != this->vertices.end(); i++)
	{
		if (color[i->first] == WHITE)
			this->DFSvisit(i->first, print, color, parent);
	}
	std::cout << std::endl;
}

template<class T>
void Graph<T>::topSortPrint()
{
	this->printDFS(0);

	if (!this->isDAG)
	{
		std::cout << "Graph must be a DAG!" << std::endl;
		return;
	}
	
	std::vector<std::pair<int,int>> list;
		
	for (auto i = this->finish.begin(); i != this->finish.end(); i++)
		list.push_back({i->second, i->first});

	std::sort(list.begin(), list.end());
	std::reverse(list.begin(), list.end());

	std::cout << "Topological Sort Print" << std::endl;
	std::cout << std::endl;

	for (std::vector<std::pair<int,int>>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << it->second << "'s time: " << it->first << ", ";
	std::cout << std::endl;
}

template<class T>
bool Graph<T>::is_empty()
{
	return this->vertices.empty();
}

template<class T>
graph_type Graph<T>::getGraphType()
{
	return this->graph_t;
}

template<class T>
void Graph<T>::SCCprint()
{
	//Given G = (V,E)
	//Run DFS(G)
	//Compute G_T
	//DFS(G_T)
	
	if (this->graph_t != DIRECTED)
	{
		std::cout << "Graph must be directed to find SCC's." << std::endl;
		return;
	}
	
	this->printDFS(0);
	Graph<T> old = *this;

	std::vector<std::pair<int,int>> list;

	for (auto i = this->finish.begin(); i != this->finish.end(); i++)
		list.push_back({i->second, i->first});

	std::sort(list.begin(), list.end());
	std::reverse(list.begin(), list.end());

	std::map<int, color_t> color;

	for (auto i = this->vertices.begin(); i != this->vertices.end(); i++)
		color.insert({i->first,WHITE});

	std::cout << "Strongly Connected Componenets" << std::endl;
	std::cout << std::endl;
	
	for (auto i = list.begin(); i != list.end(); i++)
	{
		if (color[i->second] == WHITE)
		{
			this->SCCvisit(i->second, color);
			std::cout << std::endl;
		}
	}
}

template<class T>
void Graph<T>::SCCvisit(int u, std::map<int, color_t> & color)
{
	color[u] = GRAY;
	for (auto v = this->vertices[u].begin(); v != this->vertices[u].end(); v++)
	{
		if (color[*v] == WHITE)
			this->SCCvisit(*v, color);
	}
	color[u] = BLACK;
	for (int i: vertices[u])
		std::cout << i << " -> ";
}










