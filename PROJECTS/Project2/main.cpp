//Program: main.cpp
//Author: Mitchell Krystofiak
//Description: Project2 COSC 320 SPELLCHECKER: This program will use the Dictionary Class
//             to take in user input and find all mispelled or unrecognized words. It is 
//             also going to be case sensitive. It will provide a list of words within
//             1 to 2 letter changes that are valid words in the "english.txt" file, which
//             is just a list of all valid english words, or provide that there are no known
//             words within the "edit distance".
//
//Date: April 11, 2021

#include "timer.h"
#include "Dictionary.h"
#include "LinkedList.h"
#include <fstream>
#include <iostream>
#include <sstream> //needed for the string parsing
//for my reference.. http://www.cplusplus.com/reference/sstream/istringstream/istringstream/
#include <algorithm>

#define COLOR_RED "\u001b[31m"
#define COLOR_RESET "\u001b[0m"

using namespace std; //for now

void loadDatabase(Dictionary & dict)
{
	ifstream infile;
	infile.open("english.txt");
	if (!infile)
	{
		cout << "ERROR: Cannot open english.txt file!" << endl;
		exit(1);
	}
	
	string word;
	while (infile >> word)
		dict.insertWord(word);	

	infile.close();
}

void alter(string & word)
{	
	int length = word.length();

	for (int i = 0; i < word.length(); i++)
	{
		if (ispunct(word[i]))
			{
				word.erase(i--, 1);
				length = word.length();
			}
	}
	transform(word.begin(), word.end(), word.begin(), ::tolower);
}



int main()
{

	Timer t; //timer to use throughout program
	Dictionary dictionary; //builds a 10000 bucket hash table.
	
	cout << "------------------------------" << endl; 
	cout << "   Welcome to Spell Check!    " << endl;
	cout << "                              " << endl;
	cout << " Please wait for the DataBase " << endl;
	cout << "         to load..            " << endl;
	cout << "------------------------------" << endl;
	cout << endl;

	//loads the database, prints statistics and records how much time it takes
	t.start_timer();
	loadDatabase(dictionary);
	t.end_timer();
	dictionary.printStatistics();
	t.print_time();
	t.reset_timer();
	
	//calls for a string line to check the spelling on
	string input;
	cout << endl;
	cout << "------------------------------" << endl;
	cout << "    Please enter some text.   " << endl;
	cout << "------------------------------" << endl;
	getline(cin, input);
	
	int mispelled = 0;
	int suggested = 0;

	string temp;
	//istringstream will traverse the getline string and separate by word
	istringstream traverse(input);
	
	//traversing the string
	while (traverse >> temp)
	{
		string original = temp;
		string temp2;
		//alter checks for punctation in the word provided. I.e if there is a period at the end or a contraction..
		alter(temp);
		t.start_timer();

		//if the dictionary does not contain the word...
		if (!dictionary.searchWord(temp))
		{
			//highlighting for the mispelled words
			istringstream highlight(input);

			cout << endl;
			cout << "------------------------------" << endl;
			cout << endl;
			
				
			while (highlight >> temp2)
			{
				if (temp2 == original)
					printf (COLOR_RED "%s " COLOR_RESET, temp2.c_str());
				else
					printf("%s ", temp2.c_str());
			}

			cout << endl;
			cout << endl;
			mispelled++;
			
			printf(COLOR_RED "%s" COLOR_RESET, original.c_str());	
			cout << " is mispelled!" << endl;
			cout << endl;
			cout << "One edit distance suggestions:" << endl;
			cout << "------------------------------" << endl;
			cout << endl;

			LinkedList suggestions = dictionary.suggest1(temp);
			suggested = suggested + suggestions.getLength();

			cout << "Suggestions for ";
			printf(COLOR_RED "%s" COLOR_RESET, original.c_str());
			cout << ": ";
			if (suggestions.getLength() == 0)
				cout << "No corrections available!" << endl;
			else
				suggestions.print();

			cout << endl;
			cout << endl;
			cout << "Two edit distance suggestions:" << endl;
			cout << "------------------------------" << endl;
			cout << endl;
			cout << "Here11" << endl;
			LinkedList suggestions2 = dictionary.suggest2(suggestions);
			cout << "Here22" << endl;
			suggested = suggested + suggestions2.getLength();
			
			cout << "Suggestions for ";
			printf(COLOR_RED "%s" COLOR_RESET, original.c_str());
			cout <<": ";
			if (suggestions2.getLength() == 0)
				cout << "No corrections available!" << endl;
			else
				suggestions2.print();
		}
		t.end_timer();
	}	

	cout << endl;
	cout << "---------------------------------------" << endl;
	cout << "Summary: " << std::endl;
	cout << "---------------------------------------" << endl;
	cout << "Number of mispelled words: " << mispelled << endl;
	cout << "Number of suggestions: " << suggested << endl;
	t.print_time();
	t.reset_timer();

	return 0;
}
