//Program: RBT.h
//Author: Mitchell Krystofiak
//Description: Class definition of the Red Black Tree (RBT).
//Date: April 15, 2021

#ifndef RBT_H
#define RBT_H

enum color_t
{
	RED, BLACK
};

class RBT
{
	private:
		struct TNode
		{
			int key;
			color_t color;
			TNode* left;
			TNode* right;
			TNode* parent;
			
			TNode(int num)
			{
				key = num;
				left = nullptr;
				right = nullptr;
				parent = nullptr;
			}
			TNode(int num, color_t c, TNode* l, TNode* r, TNode* p)
			{
				key = num;
				color = c;
				left = l;
				right = r;
				parent = p;
			}
		};

		static TNode* const nil;
		TNode* root;
		
		//private ordering methods
		void inOrder(TNode*) const;
		void postOrder(TNode*) const;
		void preOrder(TNode*)  const;

		//private search
		TNode* _search(int);

		//RBT deletion assist
		void destroySubTree(TNode*);

		//private delete routine
		void transplant(TNode*, TNode*);
		
		//RBT private methods
		void rightRotate(TNode*);
		void leftRotate(TNode*);
		void insertFix(TNode*);
		void deleteFix(TNode*);

	public:
		//constructors/destructor
		RBT();
		~RBT();
		
		//public insert
		void insert(int);

		//public search
		bool search(int);
		
		//public min/max
		int minimum();
		int maximum();
		
		//public ordering methods
		void displayInOrder() const;
		void displayPreOrder() const;
		void displayPostOrder() const;

		//public delete methods
		void Delete(int);
		int successor(int);
};

#endif

