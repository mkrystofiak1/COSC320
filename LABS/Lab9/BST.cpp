//Program: BST.cpp
//Author: Mitchell Krystofiak
//Description: Implementation of the BST class.
//Date: April 1, 2021

#include<iostream>
#include"BST.h"

//
//constructor and deconstructor
//

BST::BST()
{
	root = NULL;
}

BST::~BST()
{
	destroySubTree(root);
}

//
// TNode constructor
//

BST::TNode::TNode(int val)
{
	key = val;
	left = NULL;
	right = NULL;
	parent = NULL;
}

//
// destroySubTree
//

void BST::destroySubTree(TNode * nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

//
// private ordering methods
//

void BST::inOrder(TNode * nodePtr) const
{
	if (nodePtr)
	{
		inOrder(nodePtr->left);
		std::cout << nodePtr->key << " ";
		inOrder(nodePtr->right);
	}
}

void BST::postOrder(TNode * nodePtr) const
{
	if (nodePtr)
	{
		postOrder(nodePtr->left);
		postOrder(nodePtr->right);
		std::cout << nodePtr->key << " ";
	}
}

void BST::preOrder(TNode * nodePtr) const
{
	if (nodePtr)
	{
		std::cout << nodePtr->key << " ";
		preOrder(nodePtr->left);
		preOrder(nodePtr->right);
	}
}

//
// public ordering methods
//

void BST::displayInOrder() const
{
	if (root == NULL)
		std::cout << "Tree is empty." << std::endl;
	else
		inOrder(root);
}

void BST::displayPostOrder() const
{
	if (root == NULL)
		std::cout << "Tree is empty." << std::endl;
	else
		postOrder(root);
}

void BST::displayPreOrder() const
{
	if (root == NULL)
		std::cout << "Tree is empty." << std::endl;
	else
		preOrder(root);
}

//
// public insert
//
	
void BST::insert(int key)
{
	if (search(key))
	{
		//COMMENTED OUT FOR TESTING
		//std::cout << "Node with key " << key << " already exists!" << std::endl;
		return;
	}
	TNode * z = new TNode(key);
	TNode * x = root;
	TNode * y = NULL;
	while(x)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (!y)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
}

//
// search private
//

BST::TNode* BST::_search(int val)
{
	TNode* nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->key == val)
			return nodePtr;
		else if (nodePtr->key > val)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return NULL;
}

//
// search public
//

bool BST::search(int key)
{
	TNode * nodePtr = root;
	while (nodePtr)
	{
		if (nodePtr->key == key)
			return true;
		else if (key < nodePtr->key)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

//
// min and max
//

int BST::minimum()
{
	TNode * nodePtr = root;
	if (!nodePtr)
	{
		std::cout << "Tree is empty" << std::endl;
		return 0;
	}
	while (nodePtr->left)
		nodePtr = nodePtr->left;

	return nodePtr->key;
}

int BST::maximum()
{
	TNode * nodePtr = root;
	if (!nodePtr)
	{
		std::cout << "Tree is empty" << std::endl;
		return 0;
	}
	while (nodePtr->right)
		nodePtr = nodePtr->right;

	return nodePtr->key;
}

//
// delete functions
//

int BST::successor(int key)
{
	TNode * nodePtr = _search(key);
	TNode * temp = nodePtr;
	TNode * constant = nodePtr;

	if (!nodePtr)
	{
		std::cout << "No node exists with given key!" << std::endl;
		return 0;
	}
	else if (!nodePtr->right)
	{
		while (temp->parent)
		{
			if (temp->parent->left == temp)
				return temp->parent->key;
			temp = temp->parent;
		}
		
		return constant->key;
	}
	temp = nodePtr->right;
	while (temp->left)
		temp = temp->left;
	return temp->key;
}

void BST::transplant(TNode* u, TNode* v)
{
	if (!u->parent)
		root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v)
		v->parent = u->parent;
}

void BST::Delete(int val)
{
	if (!search(val))
	{
		//COMMENTED OUT FOR TESTING
		//std::cout << "Node with that key does not exist!" << std::endl;
		return;
	}
	TNode * z = _search(val);
	if (!z->left)
	{
		transplant(z, z->right);
		delete z;
	}	
	else if (!z->right)
	{
		transplant(z, z->left);
		delete z;
	}
	else
	{
		TNode * y = z->right;
		while (y->left)
			y = y->left;
		if (y->parent != z)
		{
			transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		delete z;
	}
}
