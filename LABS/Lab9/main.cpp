//Program: main.cpp
//Author: Mitchell Krystofiak
//Description: RBT class testing.
//Date: April 15, 2021

#include <iostream>
#include "RBT.h"
#include "BST.h"
#include "timer.h"
#include <ctime>

using namespace std;

int main()
{
	RBT test;

	cout << "-------------------------------------------------------------" << endl;
	cout << "***NOTE*** : The insertion, searching and deleting algorithms" << endl;
	cout << "all check for duplicate entries and invalid searches/deletes." << endl;
	cout << "The print statements have been commented out for testing purp" << endl;
	cout << "oses, i.e. inserting, searching and deleting large numbers of" << endl;
	cout << "elements fills up the screen with error messages.            " << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << endl;
	cout << "Testing insertion by inserting in order: 4, 2, 3, 6, 9, 8, 10" << endl;
	cout << "-------------------------------------------------------------" << endl;
	test.insert(4);
	test.insert(2);
	test.insert(3);
	test.insert(6);
	test.insert(9);
	test.insert(8);
	test.insert(10);
	cout << endl;
	cout << "Displaying InOrder: ";
	test.displayInOrder();
	cout << "Displaying PreOrder: ";
	test.displayPreOrder();
	cout << "Displaying PostOrder: ";
	test.displayPostOrder();
	cout << endl;
	
	cout << "Testing insertion of same value: 4, 2" << endl;
	cout << "-------------------------------------" << endl;
	cout << endl;
	test.insert(4);
	test.insert(2);
	cout << endl;

	cout << "Testing min / max / succesor functions." << endl;
	cout << "---------------------------------------" << endl;
	cout << endl;
	cout << "Minimum: " << test.minimum() << endl;
	cout << "Maximum: " << test.maximum() << endl;
	cout << "Successor of 4: " << test.successor(4) << endl;
	cout << "Successor of 9: " << test.successor(9) << endl;
	cout << endl;


	cout << "Testing update of min / max by inserting 1 and 20." << endl;
	cout << "--------------------------------------------------" << endl;
	cout << endl;
	test.insert(1);
	test.insert(20);
	cout << "Minimum: " << test.minimum() << endl;
	cout << "Maximum: " << test.maximum() << endl;
	cout << endl;

	cout << "Testing deletion: 4, 9, 3, 6" << endl;
	cout << "----------------------------" << endl;
	cout << endl;
	test.Delete(4);
	test.Delete(9);
	test.Delete(3);
	test.Delete(6);
	cout << endl;
	cout << "Displaying InOrder: ";
        test.displayInOrder();
        cout << "Displaying PreOrder: ";
        test.displayPreOrder();
        cout << "Displaying PostOrder: ";
        test.displayPostOrder();
        cout << endl;

	cout << "Testing deletion of invalid number: 200, 45" << endl;
	cout << "-------------------------------------------" << endl;
	cout << endl;
	test.Delete(200);
	test.Delete(45);
	cout << endl;

	cout << "Deleting rest of tree for time complexity analysis." << endl;
	cout << "---------------------------------------------------" << endl;
	cout << endl;
	test.Delete(1);	
	test.Delete(8);
	test.Delete(20);
	test.Delete(2);
	test.Delete(10);
	cout << endl;
	cout << "Displaying InOrder: ";
        test.displayInOrder();
        cout << "Displaying PreOrder: ";
        test.displayPreOrder();
        cout << "Displaying PostOrder: ";
        test.displayPostOrder();
        cout << endl;

	cout << "We will be comparing the BST structure to the RBT structure." << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << endl;
	
	BST testBST;
	Timer t;
	srand(time(0));

	cout << "Inserting 1000(ish) random elements." << endl;
	cout << "------------------------------------" << endl;
	
	//BST 
	t.start_timer();
	for (int i = 0; i < 1000; i++)
	{
		int random = rand() % 1000000 + 1;
		testBST.insert(random);
	}
	t.end_timer();
	cout << "BST: ";
	t.print_time();
	t.reset_timer();

	//RBT
	t.start_timer();
	for (int i = 0; i < 1000; i++)
	{
		int random = rand() % 1000000 + 1;
		test.insert(random);
	}
	t.end_timer();
	cout << "RBT: ";
	t.print_time();
	t.reset_timer();
	cout << endl;

	cout << "Inserting 2000(ish) random elements." << endl;
        cout << "------------------------------------" << endl;

        //BST
        t.start_timer();
        for (int i = 0; i < 2000; i++)
        {
                int random = rand() % 1000000 + 1;
                testBST.insert(random);
        }
        t.end_timer();
        cout << "BST: ";
        t.print_time();
        t.reset_timer();

        //RBT
        t.start_timer();
        for (int i = 0; i < 2000; i++)
        {
                int random = rand() % 1000000 + 1;
                test.insert(random);
        }
        t.end_timer();
        cout << "RBT: ";
        t.print_time();
        t.reset_timer();
        cout << endl;
	
	cout << "Inserting 3000(ish) random elements." << endl;
        cout << "------------------------------------" << endl;

        //BST 
        t.start_timer();
        for (int i = 0; i < 3000; i++)
        {
                int random = rand() % 1000000 + 1;
                testBST.insert(random);
        }
        t.end_timer();
        cout << "BST: ";
        t.print_time();
        t.reset_timer();

        //RBT
        t.start_timer();
        for (int i = 0; i < 3000; i++)
        {
                int random = rand() % 1000000 + 1;
                test.insert(random);
        }
        t.end_timer();
        cout << "RBT: ";
        t.print_time();
        t.reset_timer();
        cout << endl;

	cout << "Inserting 4000(ish) random elements." << endl;
        cout << "------------------------------------" << endl;

        //BST
        t.start_timer();
        for (int i = 0; i < 4000; i++)
        {
                int random = rand() % 1000000 + 1;
                testBST.insert(random);
        }
        t.end_timer();
        cout << "BST: ";
        t.print_time();
        t.reset_timer();

        //RBT
        t.start_timer();
        for (int i = 0; i < 4000; i++)
        {
                int random = rand() % 1000000 + 1;
                test.insert(random);
        }
        t.end_timer();
        cout << "RBT: ";
        t.print_time();
        t.reset_timer();
        cout << endl;

	cout << "Inserting 10000(ish) random elements." << endl;
        cout << "------------------------------------" << endl;

        //BST
        t.start_timer();
        for (int i = 0; i < 10000; i++)
        {
                int random = rand() % 1000000 + 1;
                testBST.insert(random);
        }
        t.end_timer();
        cout << "BST: ";
        t.print_time();
        t.reset_timer();

        //RBT
        t.start_timer();
        for (int i = 0; i < 10000; i++)
        {
                int random = rand() % 1000000 + 1;
                test.insert(random);
        }
        t.end_timer();
        cout << "RBT: ";
        t.print_time();
        t.reset_timer();
        cout << endl;
	
	cout << "Now to seach for a few elements in each tree." << endl;
	cout << "---------------------------------------------" << endl;
	cout << endl;
	
	cout << "Searching for 1000 elements." << endl;
	cout << "----------------------------" << endl;
	
	//BST
	t.start_timer();
	for (int i = 0; i < 1000; i++)
	{
		int random = rand()  % 1000000 + 1;
		testBST.search(random);
	}
	t.end_timer();
	cout << "BST: ";
	t.print_time();
	t.reset_timer();

	//RBT
	t.start_timer();
	for (int i = 0; i < 1000; i++)
	{
		int random = rand() % 1000000 + 1;
		test.search(random);
	}
	t.end_timer();
	cout << "RBT: ";
	t.print_time();
	t.reset_timer();
	cout << endl;

	cout << "Searching for 2000 elements." << endl;
        cout << "----------------------------" << endl;

        //BST
        t.start_timer();
        for (int i = 0; i < 2000; i++)
        {
                int random = rand()  % 1000000 + 1;
                testBST.search(random);
        }
        t.end_timer();
        cout << "BST: ";
        t.print_time();
        t.reset_timer();

        //RBT
        t.start_timer();
        for (int i = 0; i < 2000; i++)
        {
                int random = rand() % 1000000 + 1;
                test.search(random);
        }
        t.end_timer();
        cout << "RBT: ";
        t.print_time();
        t.reset_timer();
        cout << endl;

	cout << "Searching for 3000 elements." << endl;
        cout << "----------------------------" << endl;

        //BST
        t.start_timer();
        for (int i = 0; i < 3000; i++)
        {
                int random = rand()  % 1000000 + 1;
                testBST.search(random);
        }
        t.end_timer();
        cout << "BST: ";
        t.print_time();
        t.reset_timer();

        //RBT
        t.start_timer();
        for (int i = 0; i < 3000; i++)
        {
                int random = rand() % 1000000 + 1;
                test.search(random);
        }
        t.end_timer();
        cout << "RBT: ";
        t.print_time();
        t.reset_timer();
        cout << endl;

	cout << "Searching for 4000 elements." << endl;
        cout << "----------------------------" << endl;

        //BST
        t.start_timer();
        for (int i = 0; i < 4000; i++)
        {
                int random = rand()  % 1000000 + 1;
                testBST.search(random);
        }
        t.end_timer();
        cout << "BST: ";
        t.print_time();
        t.reset_timer();

        //RBT
        t.start_timer();
        for (int i = 0; i < 4000; i++)
        {
                int random = rand() % 1000000 + 1;
                test.search(random);
        }
        t.end_timer();
        cout << "RBT: ";
        t.print_time();
        t.reset_timer();
        cout << endl;
	
	cout << "Searching for 10000 elements." << endl;
        cout << "----------------------------" << endl;

        //BST
        t.start_timer();
        for (int i = 0; i < 10000; i++)
        {
                int random = rand()  % 1000000 + 1;
                testBST.search(random);
        }
        t.end_timer();
        cout << "BST: ";
        t.print_time();
        t.reset_timer();

        //RBT
        t.start_timer();
        for (int i = 0; i < 10000; i++)
        {
                int random = rand() % 1000000 + 1;
                test.search(random);
        }
        t.end_timer();
        cout << "RBT: ";
        t.print_time();
        t.reset_timer();
        cout << endl;
	
	cout << "Now we will be deleting large numbers of elements (20,000 ish in each tree after inserts)." << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	cout << "Deleting 1000 elements." << endl;
	cout << "-----------------------" << endl;
	
	//BST
	t.start_timer();
	for (int i = 0; i < 1000; i++)
	{
		int random = rand() % 1000000 + 1;
		testBST.Delete(random);
	}
	t.end_timer();
	cout << "BST: ";
	t.print_time();
	t.reset_timer();
	
	//RBT
	t.start_timer();
	for (int i = 0; i < 1000; i++)
	{
		int random = rand() % 1000000 + 1;
		test.Delete(random);
	}
	t.end_timer();
	cout << "BST: ";
	t.print_time();
	t.reset_timer();
	cout << endl;

	cout << "Deleting 2000 elements." << endl;
        cout << "-----------------------" << endl;

        //BST
        t.start_timer();
        for (int i = 0; i < 2000; i++)
        {
                int random = rand() % 1000000 + 1;
                testBST.Delete(random);
        }
        t.end_timer();
        cout << "BST: ";
        t.print_time();
        t.reset_timer();

        //RBT
        t.start_timer();
        for (int i = 0; i < 2000; i++)
        {
                int random = rand() % 1000000 + 1;
                test.Delete(random);
        }
        t.end_timer();
        cout << "BST: ";
        t.print_time();
        t.reset_timer();
        cout << endl;
	
	cout << "Deleting 3000 elements." << endl;
        cout << "-----------------------" << endl;

        //BST
        t.start_timer();
        for (int i = 0; i < 3000; i++)
        {
                int random = rand() % 1000000 + 1;
                testBST.Delete(random);
        }
        t.end_timer();
        cout << "BST: ";
        t.print_time();
        t.reset_timer();

        //RBT
        t.start_timer();
        for (int i = 0; i < 3000; i++)
        {
                int random = rand() % 1000000 + 1;
                test.Delete(random);
        }
        t.end_timer();
        cout << "BST: ";
        t.print_time();
        t.reset_timer();
        cout << endl;

	cout << "Deleting 4000 elements." << endl;
        cout << "-----------------------" << endl;

        //BST
        t.start_timer();
        for (int i = 0; i < 4000; i++)
        {
                int random = rand() % 1000000 + 1;
                testBST.Delete(random);
        }
        t.end_timer();
        cout << "BST: ";
        t.print_time();
        t.reset_timer();

        //RBT
        t.start_timer();
        for (int i = 0; i < 4000; i++)
        {
                int random = rand() % 1000000 + 1;
                test.Delete(random);
        }
        t.end_timer();
        cout << "BST: ";
        t.print_time();
        t.reset_timer();
        cout << endl;

	cout << "Deleting 10000 elements." << endl;
        cout << "-----------------------" << endl;

        //BST
        t.start_timer();
        for (int i = 0; i < 10000; i++)
        {
                int random = rand() % 1000000 + 1;
                testBST.Delete(random);
        }
        t.end_timer();
        cout << "BST: ";
        t.print_time();
        t.reset_timer();

        //RBT
        t.start_timer();
        for (int i = 0; i < 10000; i++)
        {
                int random = rand() % 1000000 + 1;
                test.Delete(random);
        }
        t.end_timer();
        cout << "BST: ";
        t.print_time();
        t.reset_timer();
        cout << endl;

	cout << "Displaying what we have left." << endl;
	cout << "-----------------------------" << endl;
	cout << endl;

	cout << "RBT InOrder: ";
       	test.displayInOrder();
	cout << endl;
	cout << "BST InOrder: ";
	testBST.displayInOrder();
	cout << endl;
	return 0;
}
