//Program: RBT.cpp
//Author: Mitchell Krystofiak
//Description: Implementation of the RBT class.
//Date: April 15, 2021

#include "RBT.h"
#include <iostream>

RBT::TNode* const RBT::nil = new TNode({0, BLACK, nullptr, nullptr, nullptr});

RBT::RBT()
{
	root = nil;
}

RBT::~RBT()
{
	destroySubTree(root);
}

void RBT::destroySubTree(TNode* nodePtr)
{
	if (nodePtr != nil)
	{
		if (nodePtr->left != nil)
			destroySubTree(nodePtr->left);
		if (nodePtr->right != nil)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

void RBT::inOrder(TNode* nodePtr) const
{
	if (nodePtr != nil)
        {
                inOrder(nodePtr->left);
                std::cout << nodePtr->key << " ";
                inOrder(nodePtr->right);
        }
}

void RBT::preOrder(TNode* nodePtr) const
{
	if (nodePtr != nil)
        {
                std::cout << nodePtr->key << " ";
                preOrder(nodePtr->left);
                preOrder(nodePtr->right);
        }
}

void RBT::postOrder(TNode* nodePtr) const
{
	if (nodePtr != nil)
        {
                postOrder(nodePtr->left);
                postOrder(nodePtr->right);
                std::cout << nodePtr->key << " ";
        }
}

void RBT::displayInOrder() const
{
	if (root == nil)
		std::cout << "Tree is empty!";
	else
		inOrder(root);

	std::cout << std::endl;
}

void RBT::displayPreOrder() const
{
	if (root == nil)
		std::cout << "Tree is empty!";
	else
		preOrder(root);

	std::cout << std::endl;
}

void RBT::displayPostOrder() const
{
	if (root == nil)
		std::cout << "Tree is empty!";
	else
		postOrder(root);

	std::cout << std::endl;
}

RBT::TNode* RBT::_search(int val)
{
	TNode* nodePtr = root;

	while (nodePtr != nil)
	{
		if (nodePtr->key == val)
			return nodePtr;
		else if (nodePtr->key > val)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return nil;
}

bool RBT::search(int val)
{
	TNode* nodePtr = root;

	while (nodePtr != nil)
	{
		if (nodePtr->key == val)
			return true;
		else if (val < nodePtr->key)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

int RBT::minimum()
{
	TNode* nodePtr = root;

	if (nodePtr == nil)
	{
		std::cout << "Tree is empty!" << std::endl;
		return -1;
	}
	while (nodePtr->left != nil)
		nodePtr = nodePtr->left;

	return nodePtr->key;
}

int RBT::maximum()
{
	TNode* nodePtr = root;

	if (nodePtr == nil)
	{
		std::cout << "Tree is empty!" << std::endl;
		return -1;
	}
	while (nodePtr->right != nil)
		nodePtr = nodePtr->right;

	return nodePtr->key;
}

int RBT::successor(int key)
{
        TNode * nodePtr = _search(key);
        TNode * temp = nodePtr;
        TNode * constant = nodePtr;

        if (nodePtr == nil)
        {
                std::cout << "No node exists with given key!" << std::endl;
                return 0;
        }
        else if (nodePtr->right == nil)
        {
                while (temp->parent != nil)
                {
                        if (temp->parent->left == temp)
                                return temp->parent->key;
                        temp = temp->parent;
                }

                return constant->key;
        }
        temp = nodePtr->right;
        while (temp->left != nil)
                temp = temp->left;
        return temp->key;
}
void RBT::insert(int val)
{
	if (search(val))
	{
		//COMMENTED OUT FOR TESTING
		//std::cout << "Node with key " << val << " already exists in tree!" << std::endl;
		return;
	}
	TNode* z = new TNode(val);
	TNode* y = nil;
	TNode* u = root;

	while (u != nil)
	{
		y = u;
		if (z->key < u->key)
			u = u->left;
		else
			u = u->right;
	}
	z->parent = y;
	if (y == nil)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
	z->left = nil;
	z->right = nil;
	z->color = RED;
	insertFix(z);
}

void RBT::transplant(TNode* u, TNode* v)
{
	if (u->parent == nil)
		root = v;
	else if (u->parent->right == u)
		u->parent->right = v;
	else
		u->parent->left = v;
	v->parent = u->parent;
}

void RBT::Delete(int val)
{
	TNode* del = _search(val);
	if (del == nil)
	{
		//COMMENTED OUT FOR TESTING
		//std::cout << "Node with key " << val << " not found in the tree!" << std::endl;
		return;
	}
	else
	{
		TNode* temp1 = del;
		TNode* temp2;
		color_t temp1Color = temp1->color;
		if (del->left == nil)
		{
			temp2 = del->right;
			transplant(del, del->right);
		}
		else if (del->right == nil)
		{
			temp2 = del->left;
			transplant(del, del->left);
		}
		else
		{
			TNode* x = del->right;
			while (x->left != nil)
				x = x->left;
			temp1 = x;
			temp1Color = temp1->color;
			temp2 = temp1->right;
			if (temp1->parent == del)
				temp2->parent = temp1;
			else
			{
				transplant(temp1, temp1->right);
				temp1->right = del->right;
				temp1->right->parent = temp1;
			}
			transplant(del, temp1);
			temp1->left = del->left;
			temp1->left->parent = temp1;
			temp1->color = del->color;
		}
		delete del;
		if (temp1Color == BLACK)
		{
			deleteFix(temp2);
		}
	}
}

void RBT::deleteFix(TNode* x)
{
	while (x != root && x->color == BLACK)
	{
		if (x == x->parent->left)
		{
			TNode* temp = x->parent->right;
			if (temp->color == RED)
			{
				temp->color = BLACK;
				x->parent->color = RED;
				leftRotate(x->parent);
				temp = x->parent->right;
			}
			if (temp->left->color == BLACK && temp->right->color == BLACK)
			{
				temp->color = RED;
				x = x->parent;
			}
			else
			{
				if (temp->right->color == BLACK)
				{
					temp->left->color = BLACK;
					temp->color = RED;
					rightRotate(temp);
					temp = x->parent->right;
				}
				temp->color = x->parent->color;
				x->parent->color = BLACK;
				temp->right->color = BLACK;
				leftRotate(x->parent);
				x = root;
			}
		}
		else
		{
			TNode* temp = x->parent->left;
			if (temp->color == RED)
			{
				temp->color = BLACK;
				x->parent->color = RED;
				rightRotate(x->parent);
				temp = x->parent->left;
			}
			if (temp->right->color == BLACK && temp->left->color == BLACK)
			{
				temp->color = RED;
				x = x->parent;
			}
			else
			{
				if (temp->left->color == BLACK)
				{
					temp->right->color = BLACK;
					temp->color = RED;
					leftRotate(temp);
					temp = x->parent->left;
				}
				temp->color = x->parent->color;
				x->parent->color = BLACK;
				temp->left->color = BLACK;
				rightRotate(x->parent);
				x = root;
			}
		}
	}
	x->color = BLACK;
}

void RBT::rightRotate(TNode* x) 
{
	TNode* y = x->left;
	x->left = y->right;
	if (y->right != nil)
		y->right->parent = x;
	y->parent = x->parent;
	if (x->parent == nil)
		root = y;
	else if (x == x->parent->right)
		x->parent->right = y;
	else
		x->parent->left = y;
	y->right = x;
	x->parent = y;
}

void RBT::leftRotate(TNode* x)
{
	TNode* y = x->right;
	x->right = y->left;
	if (y->left != nil)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == nil)
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
}

void RBT::insertFix(TNode* z)
{
	while (z->parent->color == RED)
	{
		if (z->parent == z->parent->parent->left)
		{
			TNode* y = z->parent->parent->right;
			if (y->color == RED)
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->right)
				{
					z = z->parent;
					leftRotate(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				rightRotate(z->parent->parent);
			}
		}
		else
		{
			TNode* y = z->parent->parent->left;
			if (y->color == RED)
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->left)
				{
					z = z->parent;
					rightRotate(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				leftRotate(z->parent->parent);
			}
		}
	}
	root->color = BLACK;
}
