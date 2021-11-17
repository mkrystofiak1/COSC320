//Program: hash.cpp
//Author: Mitchell Krystofiak
//Description: Hash table test file.
//Date: March 25, 2021

#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>

//for large documents input
#include<fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// String hash 1
size_t string_hash1(string key)
{
	size_t index = 0;
	size_t sum = 0;

	//random 10 digit prime number (stolen from internet)
	size_t a = 9576890767;
	
	//parse through the string and sum up the values of each character
	//to get the value of the whole string.
	while (key[index])
	{
		sum = sum + (key[index] * a) % (index * index + 1);
		index++;
	}
	return (sum * index) % a;
}

// String hash 2
size_t string_hash2(string key)
{
	//similar to first function, difference is multiply by another prime
	//number instead of index

	size_t p1 = 5915587277;
	size_t p2 = 1500450271;
	size_t index = 0;
	size_t sum = 0;
	

	while (key[index])
	{
		sum = sum + (size_t(key[index]) * (index + 1));
		index ++;
	}

	return (sum * p1) % p2;
}	

// Integer hash
size_t hash(size_t key)
{
	//notes on confusing things:
	//	 x << y = x * 2^y
	//	 x >> y = x / 2^y
	//	 & bit wise 
	//	 x^y = x xor y 

	//avoiding any data type conversion errors
	size_t one = 1;
	
	//set w = 32
	const size_t w = 32;

	//set root = 2 ^ 32
	size_t root = one << w;

	//set p = small number less than w
	size_t p = 11;

	//random 10 digit prime number (stolen from internet)
	size_t a = 9576890767;
	
	//End goal: We want to return (a*key mod 2^w)/2^(w-p))
	size_t ax = a * key;
	size_t axmodw = ax & ((root) - one);
	size_t r = w - p;
	
	/* Test cout statements:
	cout << "w = " << w << endl;
	cout << "p = " << p << endl;
	cout << "a = " << a << endl;
	cout << "ax = " << ax << endl;
	cout << "axmodw = " << axmodw << endl;
	cout << "r = " << r << endl;
	*/

	//returns (ax mod 2^w) / 2 ^ (w-p)
	size_t hash = axmodw >> r;
	cout << "hash in fun = " << hash << endl;;
	return hash;
}

// Hash print
void print_hash(size_t hash)
{
	cout << std::hex << hash << endl;
	cout << std::dec;
}

int main()
{
	cout << "Let's try the integer hashing function!" << endl;
	cout << endl;
	cout << "Integer before the hash: 200" << endl;
	cout << "Integer after the hash : ";
       	print_hash(hash(200));
	cout << endl;

	cout << "Integer before the hash: 12345678912" << endl;
	cout << "Integer after the hash : ";
	print_hash(hash(12345678912));
	cout << endl;

	cout << "Integer before the hash: 1" << endl;
	cout << "Integer after the hash : ";
	print_hash(hash(1));
	cout << endl;

	cout << "Integer before the hash: 467" << endl;
	cout << "Integer after the hash : ";
	print_hash(hash(467));
	cout << endl;

	cout << "Integer before the hash: 48572947239" << endl;
	cout << "Integer after the hash : ";
	print_hash(hash(48572947239));
	cout << endl;
	cout << endl;

	cout << "Let's try the string hashing function 1!" << endl;
	cout << endl;
	cout << "String before the hash: Dang do I want to pass this class or what" << endl;
	cout << "String after the hash : ";
	print_hash(string_hash1("Dang do I want to pass this class or what"));
	cout << endl;

	cout << "String before the hash: Cockle doodle doo the cow says moo" << endl;
	cout << "String after the hash : ";
	print_hash(string_hash1("Cockle doodle doo the cow says moo"));
	cout << endl;

	cout << "String before the hash: This is a long string this is a long string this is a long string this is a long string this is a long string" << endl;
	cout << "String after the hash : ";
	print_hash(string_hash1("This is a long string this is a long string this is a long string this is a long string this is a long string"));
	cout << endl; 

	cout << "String before the hash: ABCDEFGHIJKLMNOPQRSTUVWXYZ" << endl;
	cout << "String after the hash : ";
	print_hash(string_hash1("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	cout << endl;

	cout << "String before the hash: ZYXWVUTSRQPONMLKJIHGFEDCBA" << endl;
	cout << "String after the hash : ";
	print_hash(string_hash1("ZYXWVUTSRQPONMLKJIHGFEDCBA"));
	cout << endl;
	
	cout << "Note: The above two examples of the alphabet should be different, even tho they contain the same characters!" << endl;
	cout << endl;

	cout << "Let's try the string hashing function 2!" << endl;
	cout << endl;
	cout << "String before the hash: My name is Mitchell Krystofiak" << endl;
        cout << "String after the hash : ";
        print_hash(string_hash2("My name is Mitchell Krystofiak"));
        cout << endl;

        cout << "String before the hash: Thank you Dr.Anderson for all of your help" << endl;
        cout << "String after the hash : ";
        print_hash(string_hash2("Thank you Dr.Anderson for all of your help"));
        cout << endl;

        cout << "String before the hash: This semester is SO stressful" << endl;
        cout << "String after the hash : ";
        print_hash(string_hash2("This semester is SO stressful"));
        cout << endl;

        cout << "String before the hash: ABCDEFGHIJKLMNOPQRSTUVWXYZ" << endl;
        cout << "String after the hash : ";
        print_hash(string_hash2("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
        cout << endl;

        cout << "String before the hash: ZYXWVUTSRQPONMLKJIHGFEDCBA" << endl;
        cout << "String after the hash : ";
	print_hash(string_hash2("ZYXWVUTSRQPONMLKJIHGFEDCBA"));
        cout << endl;
	
	cout << "Now lets try a slightly larger string! We will use fstream to bring in a text document" << endl;
	cout << "and convert it to a string to process a hash for it!" << endl;
	cout << "Document text : " << endl;
	//after many sources, this appeared the easiest way to do this
	std::ifstream input;
	input.open("testdoc.txt");
	string s;
	for (char c; input.get(c); s += c){}
	input.close();
	cout << s << endl;
	cout << "Document after the hash: ";
	print_hash(string_hash2(s));
	cout << endl;
	cout << endl;
	
	cout << "Should we try a 10 page (condensed sorta) example essay from online? Yes." << endl;
	cout << "Document text : " << endl;
	std::ifstream input2;
	input2.open("testdoc2.txt");
	string x;
	for (char c; input2.get(c); x += c){}
	input2.close();
	cout << x << endl;
	cout << "Document after the hash: ";
	print_hash(string_hash2(x));
	cout << endl;
	cout << endl;

	return 0;	
}

