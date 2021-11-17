//Program: BST.h
//Author: Mitchell Krystofiak
//Description: BST class definition.
//Date: April 1, 2021

#include<iostream>
#ifndef BST_H
#define BST_H

class BST
{
	private:
		//TNode declaration
		struct TNode
		{
			int key;
			TNode* left;
			TNode* right;
			TNode* parent;
			TNode(int);
		};
		TNode* root;
		
		//deletion assister
                void destroySubTree(TNode *);

		//ordering methods
		void inOrder(TNode *) const;
		void postOrder(TNode *) const;
		void preOrder(TNode *) const;
		
		//search
		TNode* _search(int);
			
		//delete routines
		void transplant(TNode *, TNode *);
	public:
		//constructor/deconstructor
		BST();
		~BST();

		//call insert
		void insert(int);

		//search
		bool search(int);

		//ordering callers
		void displayInOrder() const;
		void displayPostOrder() const;
		void displayPreOrder() const;

		//delete
		void Delete(int);
		int successor(int);

		//min and max
		int minimum();
                int maximum();

		//print
		void print();


};

#endif
