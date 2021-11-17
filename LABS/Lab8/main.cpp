//Program: main.cpp
//Author: Mitchell Krystofiak
//Description: Main program to test the functionality of the BST.
//Date: April 1, 2021

#include<iostream>
#include"BST.h"
#include<cmath>
#include"timer.h"

int main()
{
	srand(time(0));
	BST test;
	Timer t;

	std::cout << "Testing the insert function by inserting in the order: 5 3 4 8 7 1." << std::endl;
	std::cout << "Also, recording time for an individual insert." << std::endl;
	std::cout << std::endl;
	t.start_timer();
	test.insert(5);
	t.end_timer();
	t.print_time();
	t.reset_timer();
	t.start_timer();
	test.insert(3);
	t.end_timer();
	t.print_time();
	t.reset_timer();
	t.start_timer();
	test.insert(4);
	t.end_timer();
        t.print_time();
        t.reset_timer();
        t.start_timer();
	test.insert(8);
	t.end_timer();
        t.print_time();
        t.reset_timer();
        t.start_timer();
	test.insert(7);
	t.end_timer();
        t.print_time();
        t.reset_timer();
        t.start_timer();
	test.insert(1);
	t.end_timer();
	t.print_time();
	t.reset_timer();
	std::cout << std::endl;	
	std::cout << "InOrder display: ";
	test.displayInOrder();
	std::cout << std::endl;

	std::cout << "PreOrder display: ";
	test.displayPreOrder();
	std::cout << std::endl;

	std::cout << "PostOrder display: ";
	test.displayPostOrder();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Testing search function by checking for 8 (in tree) and 10 (not in tree)." << std::endl;
	std::cout << "Also, recording the time for an individual search." << std::endl;
	std::cout << std::endl;

	t.start_timer();
	if (test.search(8))
	{
		t.end_timer();
		std::cout << "Key 8 is in the tree!" << std::endl;
	}
	else
	{
		t.end_timer();
		std::cout << "Key 8 is not in the tree!" << std::endl;
	}
	t.print_time();
	t.reset_timer();
	std::cout << std::endl;
	
	t.start_timer();
	if (test.search(10))
	{
		t.end_timer();
		std::cout << "Key 10 is in the tree!" << std::endl;
	}
	else
	{
		t.end_timer();
		std::cout << "Key 10 is not in the tree!" << std::endl;
	}
	t.print_time();
	t.reset_timer();
	std::cout << std::endl;

	std::cout << "Minimum of the tree is: " << test.minimum() << std::endl;
	std::cout << "Maximum of the tree is: " << test.maximum() << std::endl;
	std::cout << std::endl;

	std::cout << "Lets do some more inserts... Inserting 10 (not in tree) and 4 (in tree)." << std::endl;
	test.insert(10);
	test.insert(4);
	std::cout << std::endl;
	std::cout << "InOrder display: ";
        test.displayInOrder();
        std::cout << std::endl;

        std::cout << "PreOrder display: ";
        test.displayPreOrder();
        std::cout << std::endl;

        std::cout << "PostOrder display: ";
        test.displayPostOrder();
        std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Searching for 10 again, now that it is in the tree." << std::endl;
	if (test.search(10))
		std::cout << "Key 10 is in the tree!" << std::endl;
	else
		std::cout << "Key 10 is not in the tree!" << std::endl;
	std::cout << std::endl;

	std::cout << "Testing deletion by removing 1. " << std::endl;
	test.Delete(1);

	std::cout << "InOrder display: ";
        test.displayInOrder();
        std::cout << std::endl;

        std::cout << "PreOrder display: ";
        test.displayPreOrder();
        std::cout << std::endl;

        std::cout << "PostOrder display: ";
        test.displayPostOrder();
        std::cout << std::endl;
        std::cout << std::endl;

	std::cout << "Testing deletion by removing 10." << std::endl;
	std::cout << "Also, recording the time of an individual delete." << std::endl;
	t.start_timer();
	test.Delete(10);
	t.end_timer();
	t.print_time();
	t.reset_timer();
	std::cout << std::endl;

	std::cout << "InOrder display: ";
        test.displayInOrder();
        std::cout << std::endl;

        std::cout << "PreOrder display: ";
        test.displayPreOrder();
        std::cout << std::endl;

        std::cout << "PostOrder display: ";
        test.displayPostOrder();
        std::cout << std::endl;
        std::cout << std::endl;
	
	std::cout << "Testing deletion by removing 1 again." << std::endl;
        test.Delete(1);
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "The successor of some nodes..." << std::endl;
	std::cout << "The successor of 3 is " << test.successor(3) << "." << std::endl;
	std::cout << "The successor of 7 is " << test.successor(8) << "." << std::endl;
	std::cout << std::endl;

	std::cout << "Now, for some large inserts, deletions and searches. The time will also be recorded." << std::endl;
	std::cout << std::endl;
	std::cout << "Inserting 1000 elements." << std::endl;
	
	BST test1;

	t.start_timer();
	for (int i = 1; i <= 1000; i++)
	{
		test1.insert(i);
	}
	t.end_timer();
	t.print_time();
	t.reset_timer();
	std::cout << std::endl;
	std::cout << "Searching for a random element 10 times in the BST (1000ish elements)." << std::endl;

	for (int i = 1; i <= 10; i++)
	{
		int j = rand() % 1000 + 1;
		t.start_timer();
		test1.search(j);
		t.end_timer();
		t.print_time();
		t.reset_timer();
	}		
	std::cout << std::endl;
	std::cout << "Now deleting 1000 elements of the tree." << std::endl;

	t.start_timer();
	for (int i = 1; i <= 1000; i++)
	{
		test1.Delete(i);
	}
	t.end_timer();
	t.print_time();
	t.reset_timer();
	
	std::cout << std::endl;
	std::cout << "InOrder display: ";
	test1.displayInOrder();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Inserting 2000 elements." << std::endl;

        t.start_timer();
        for (int i = 1; i <= 2000; i++)
        {
                test1.insert(i);
        }
        t.end_timer();
        t.print_time();
        t.reset_timer();
        std::cout << std::endl;
        std::cout << "Searching for a random element 10 times in the BST (2000ish elements)." << std::endl;

        for (int i = 1; i <= 10; i++)
        {
                int j = rand() % 2000 + 1;
                t.start_timer();
                test1.search(j);
                t.end_timer();
                t.print_time();
                t.reset_timer();
        }
        std::cout << std::endl;
        std::cout << "Now deleting 2000 elements of the tree." << std::endl;

        t.start_timer();
        for (int i = 1; i <= 2000; i++)
        {
                test1.Delete(i);
        }
        t.end_timer();
        t.print_time();
        t.reset_timer();

        std::cout << std::endl;
        std::cout << "InOrder display: ";
        test1.displayInOrder();
        std::cout << std::endl;
        std::cout << std::endl;

	std::cout << "Inserting 3000 elements." << std::endl;

        t.start_timer();
        for (int i = 1; i <= 3000; i++)
        {
                test1.insert(i);
        }
        t.end_timer();
        t.print_time();
        t.reset_timer();
        std::cout << std::endl;
        std::cout << "Searching for a random element 10 times in the BST (3000ish elements)." << std::endl;

        for (int i = 1; i <= 10; i++)
        {
                int j = rand() % 3000 + 1;
                t.start_timer();
                test1.search(j);
                t.end_timer();
                t.print_time();
                t.reset_timer();
        }
        std::cout << std::endl;
        std::cout << "Now deleting 3000 elements of the tree." << std::endl;

        t.start_timer();
        for (int i = 1; i <= 3000; i++)
        {
                test1.Delete(i);
        }
        t.end_timer();
        t.print_time();
        t.reset_timer();

        std::cout << std::endl;
        std::cout << "InOrder display: ";
        test1.displayInOrder();
        std::cout << std::endl;
        std::cout << std::endl;

	std::cout << "Inserting 10000 elements." << std::endl;

        t.start_timer();
        for (int i = 1; i <= 10000; i++)
        {
                test1.insert(i);
        }
        t.end_timer();
        t.print_time();
        t.reset_timer();
        std::cout << std::endl;
        std::cout << "Searching for a random element 10 times in the BST (10000ish elements)." << std::endl;

        for (int i = 1; i <= 10; i++)
        {
                int j = rand() % 10000 + 1;
                t.start_timer();
                test1.search(j);
                t.end_timer();
                t.print_time();
                t.reset_timer();
        }
        std::cout << std::endl;
        std::cout << "Now deleting 10000 elements of the tree." << std::endl;

        t.start_timer();
        for (int i = 1; i <= 10000; i++)
        {
                test1.Delete(i);
        }
        t.end_timer();
        t.print_time();
        t.reset_timer();

        std::cout << std::endl;
        std::cout << "InOrder display: ";
        test1.displayInOrder();
        std::cout << std::endl;
	return 0;
}
