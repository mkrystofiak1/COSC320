//Program: Dictionary.h
//Author: Mitchell Krystofiak
//Description: COSC 320 Project 2 Dictionary class definition.
//Date: April 11, 2021

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include "LinkedList.h"
#include <string>
/* 
 * Linked List functions: 
 * 	put_front(string) , put_back(string), deleteNode(Node*)
 * 	searchNode(string), print()
 *
 * 	Node: Node* prev, Node* next, string word;
 */

class Dictionary
{
	private: 
		LinkedList * hash_table;
		size_t length;
		size_t * used;

		//Private functions that use different methods to find errors.
		void rep(LinkedList&, std::string);
		void add(LinkedList&, std::string);
		void del(LinkedList&, std::string);
		void swp(LinkedList&, std::string);

	public:
		//Constructor/Copy Constructor/Deconstructor
		Dictionary();
		Dictionary(const Dictionary&);
		~Dictionary();
		
		//String hash function
		size_t hash(std::string);
		
		//Search for valid word.
		bool searchWord(std::string);

		//Insert word into the table.
		void insertWord(std::string);

		//Prints the table.
		void printTable();

		//Total Number of Words in table
                size_t totalWords();

                //Smallest Bucket in the table
                size_t smallestBucket();
                        
                //Biggest Bucket in the table
                size_t biggestBucket();

                //Number of used Buckets in the table
                size_t usedBuckets();
                        
                //Total number of buckets in the table
                size_t totalBuckets();
                                
                //Average number of nodes in each bucket
                double avgBucket();
			
		//Prints the statistics.
		void printStatistics();

		//Suggestion finders for mispelled words.
		LinkedList suggest1(std::string); //one edit
		LinkedList suggest2(LinkedList);  //two edits

};

#endif
