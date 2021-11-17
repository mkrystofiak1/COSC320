//Program: LinkedList.h
//Author: Mitchell Krystofiak
//Description: Linked list class definition for the dictionary class.
//Date: April 11, 2021

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class LinkedList
{
	public:

		struct Node
		{
			Node *next;
		        Node *prev;
			std::string word;
			
			Node()
			{
				next = nullptr;
				prev = nullptr;
			}
			Node(std::string s)
			{
				word = s;
				next = nullptr;
				prev = nullptr;
			}
		};

		Node * head;

		//constructor
		LinkedList();
		
		//copy constructor
		LinkedList(const LinkedList &);

		//deconstructor
		~LinkedList();

		//utility functions
		void put_front(const std::string);
		
		void put_back(const std::string);

		void deleteNode(Node *);

		bool searchNode(const std::string);
		
		void print();

		int getLength();

		std::string * getWords();

};		

#endif



