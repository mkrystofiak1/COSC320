//Program: Dictionary.cpp
//Author: Mitchell Krystofiak
//Description: COSC 320 Project 2 Dictionary Class implementation.
//Date: April 11, 2021

#include<iostream>
#include"Dictionary.h"

Dictionary::Dictionary()
{
	hash_table = new LinkedList[10007];
	length = 10007;
	used = new size_t[length];

	for (size_t i = 0; i < length; i++)
	{
		used[i] = 0;
	}
}

Dictionary::Dictionary(const Dictionary& oldDictionary)
{
	hash_table = new LinkedList[oldDictionary.length];
	length = oldDictionary.length;
	used = new size_t[oldDictionary.length];

	for (size_t i = 0; i < length; i++)
	{
		hash_table[i] = oldDictionary.hash_table[i];
		used[i] = oldDictionary.used[i];
	}
}

Dictionary::~Dictionary()
{
	delete [] hash_table;
	delete [] used;
	hash_table = nullptr;
	used = nullptr;
}

size_t Dictionary::hash(std::string word)
{
        size_t index = 0;
        size_t sum = 0;

        //Gonna use the hashing algorithm from my
        //lab7 for COSC 320.

        //random 10 digit prime number (generated by internet)
        size_t p = 9576890767;
	size_t p1 = 10007; //first prime above 10000

        while (word[index])
        {
                sum = sum + (size_t(word[index]) * (p - (index * sizeof(word) + 1)));
                index++;
        }
        return (sum * p) % p1;//this makes sure we get hashes that are in range
}

bool Dictionary::searchWord(std::string word)
{
	return hash_table[hash(word)].searchNode(word);
}

void Dictionary::insertWord(std::string word)
{
	unsigned value = hash(word);
	hash_table[value].put_front(word);
	used[value]++;
}

size_t Dictionary::totalWords()
{
	size_t total = 0;

	for (size_t i = 0; i < length; i++)
		total = total + used[i];
	
	return total;
}

size_t Dictionary::smallestBucket()
{
	size_t smallest = 0;

	while (used[smallest] == 0)
		smallest++;

	for (size_t i = 0; i < length; i++)
		if (used[i] < used[smallest] && used[i] != 0)
			smallest = i;
	
	return used[smallest];
}

size_t Dictionary::biggestBucket()
{
	size_t biggest = 0;

	for (size_t i = 1; i < length; i++)
		if (used[i] > used[biggest])
			biggest = i;
	
	return used[biggest];
}

size_t Dictionary::usedBuckets()
{
	size_t use = 0;

	for (size_t i = 0; i < length; i++)
		if (used[i] > 0)
			use++;
	
	return use;
}

size_t Dictionary::totalBuckets()
{
	return length;
}

double Dictionary::avgBucket()
{
	double average = 0;

	for (size_t i = 0; i < length; i++)
		average = average + used[i];
	
	average = (average / static_cast<double>(length));
	return average;
}

void Dictionary::printStatistics()
{
	std::cout << "Total words: " << totalWords() << std::endl;
        std::cout << "Smallest bucket size: " << smallestBucket() << std::endl;
        std::cout << "Biggest bucket size: " << biggestBucket() << std::endl;
        std::cout << "Total number of buckets: " << totalBuckets() << std::endl;
        std::cout << "Total number of used buckets: " << usedBuckets() << std::endl;
        std::cout << "Average number of nodes in each bucket: " << avgBucket() << std::endl;
}

LinkedList Dictionary::suggest1(std::string error)
{
	LinkedList suggestions;
	rep(suggestions, error);
	add(suggestions, error);
	del(suggestions, error);
	swp(suggestions, error);

	return suggestions;
}

LinkedList Dictionary::suggest2(LinkedList x)
{
	std::cout << "Here1" << std::endl;
	std::string * words = x.getWords();
	LinkedList suggestions;
	std::cout << "here" << std::endl;	
	for (int i = 0; i < x.getLength(); i++)
	{
		rep(suggestions, words[i]);
		add(suggestions, words[i]);
		del(suggestions, words[i]);
		swp(suggestions, words[i]);
	}
	delete [] words;
	return suggestions;
}

void Dictionary::rep(LinkedList & suggestions, std::string words)
{
	std::string copy = words;
	
	for (int i = 0; i < copy.length(); i++)
	{
		for (char j = 'a'; j <= 'z'; j++)
		{
			words[i] = j;
			if (searchWord(words) && !suggestions.searchNode(words)) //try and remove repeats
				suggestions.put_front(words);
			words = copy;
		}
	}
}

void Dictionary::add(LinkedList & suggestions, std::string words)
{
	std::string copy = words;

	for (int i = 0; i < copy.length(); i++)
	{
		for (char j = 'a'; j <= 'z'; j++)
		{
			words = words.substr(0, i) + j + words.substr(i, copy.length());
			if (searchWord(words) && !suggestions.searchNode(words))
				suggestions.put_front(words);
			words = copy;
		}
	}
}

void Dictionary::del(LinkedList & suggestions, std::string words)
{
	std::string copy = words;

	for (int i = 0; i < copy.length(); i++)
	{
		words.erase(i, 1);
		if (searchWord(words) && !suggestions.searchNode(words))
			suggestions.put_front(words);
		words = copy;
	}
}

void Dictionary::swp(LinkedList & suggestions, std::string words)
{
	std::string copy = words;
	
	for (int i = 0; i < copy.length(); i++)
	{
		for (int j = i + 1; j < copy.length(); j++)
		{
			if (i != j)
			{
				std::swap(words[i], words[j]);
				if (searchWord(words) && !suggestions.searchNode(words))
					suggestions.put_front(words);
				words = copy;
			}
		}
	}
}


