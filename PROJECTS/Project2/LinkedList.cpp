//Program: LinkedList.cpp
//Author: Mitchell Krystofiak
//Description: Linked List implementation.
//Date: April 11, 2021

#include "LinkedList.h"
#include <iostream>
//#include<thread>
//#include<chrono>

LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::LinkedList(const LinkedList& oldList)
{
	head = nullptr;
	Node * temp = oldList.head;
	while (temp)
	{
		put_front(temp->word);
		temp = temp->next;
	}
}

LinkedList::~LinkedList()
{
	Node * nodePtr = this->head;
	Node * nextNode;
	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

void LinkedList::put_front(const std::string word)
{
	Node * newNode = new Node(word);
	if (head == nullptr)
	{
		head = newNode;
		return;
	}
	newNode->next = head;
	head = newNode;
	head->next->prev = head;

}

void LinkedList::put_back(const std::string word)
{
	Node * newNode = new Node(word);
	if (!head)
		head = newNode;
	else
	{
		Node * temp = head;
		while (temp->next)
			temp = temp->next;
		temp->next = newNode;
	}
}

void LinkedList::deleteNode(LinkedList::Node * nodePtr)
{
	if (!head)
		return;
	if (head == nodePtr)
		head = nodePtr->next;
	if (!nodePtr->next)
		nodePtr->next->prev = nodePtr->prev;
	
	delete nodePtr;
}

bool LinkedList::searchNode(const std::string word)
{
	if (!head)
		return false;
	
	Node * temp = head;
	while(temp)
	{
		if (temp->word == word)
			return true;

		temp = temp->next;
	}
	return false;
}

void LinkedList::print()
{
	if (head == nullptr)
		return;

	Node * temp = head;
	while (temp)
	{
		std::cout << "{" << temp->word << "} ";
		temp = temp->next;
	}
}

int LinkedList::getLength()
{
	int total = 0;
	if (head == nullptr)
		return 0;

	Node * temp = head;
	while (temp)
	{
		total++;
		temp = temp->next;
	}
	return total;
}

std::string * LinkedList::getWords()
{
	if (head == nullptr)
		return nullptr;

	Node * temp = head;
	std::string * elements = new std::string[this->getLength()];

	for (int i = 0; temp; i++)
	{
		elements[i] = temp->word;
		temp = temp->next;
	}
	return elements;
}

