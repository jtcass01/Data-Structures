/*
**
**@Author        Jacob Taylor Cassady
**@Class         CECS302 - Data Structures
**@Instructor    Dr. Ibrahim Imam
**@Assignment    5
**@Question      1
**@Date Created  11/22/2016
**@Last Updated  11/22/2016
**
*/




/*	Problem Statement
Modify the code so that it will store a sequence of integers (not string) in the hash table
1.2. Write your own main to insert the sequence of integers { 121, 81, 16, 100, 25, 0, 1, 9, 4, 36,
64, 49,) using a table of size 17.
1.3. Run the same sequence using a table of size 7.
1.4. Compare your results and explain the effect of rehashing
1.5. Rewrite main so that it will replace the sequence above with a random number generator to
generate randomly 100 integers between the value of 0 and 99 and insert these in a table of
size 130 and use this data to calculate λ. 
*/



#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <math.h>
#include <ctime> 


using namespace std;

int iniHash(const int & key);
int nextPrime(int);

class HashTable
{
	public:
		explicit HashTable(int size = 21) :
				currentSize(0)
		{
			theLists.resize(size);
			cout << "The Hash Table size is " << theLists.size() << endl;
		}

		bool insert(const int & x)
		{
			list<int> &whichList = theLists[myhash(x)];
			if (find(whichList.begin(), whichList.end(), x) != whichList.end())
			{
				return false;
			} // end if
			whichList.push_back(x);
			cout << "Inserted " << x << endl;
			if ((++currentSize)*(2) > theLists.size())
			{
				printList();
				rehash();
			} // end if
			return true;
		}

		void makeEmpty()
		{
			for (unsigned i = 0; i < theLists.size(); i++)
				theLists[i].clear();
		}

		bool contains(const int & x) const
		{
			const list<int> & whichList = theLists[myhash(x)];
			return find(whichList.begin(), whichList.end(), x) != whichList.end();
		}

		bool remove(const int & x)
		{
			list<int> &whichList = theLists[myhash(x)];
			list<int>::iterator itr = find(whichList.begin(), whichList.end(), x);

			if (itr == whichList.end())
				return false;

			whichList.erase(itr);
			--currentSize;
			return true;
		}
		void rehash()
		{
			cout << "I am rehashing" << endl;
			vector<list<int> > oldLists = theLists;

			// Create new double-sized, empty table
			theLists.resize(nextPrime(2 * theLists.size()));
			for (unsigned j = 0; j < theLists.size(); j++)
				theLists[j].clear();

			// Copy table over
			currentSize = 0;
			for (unsigned i = 0; i < oldLists.size(); i++)
			{
				list<int>::iterator itr = oldLists[i].begin();
				while (itr != oldLists[i].end())
					insert(*itr++);
			}
		}

		void printList()
		{
			for (unsigned i = 0; i < theLists.size(); i++)
			{
				list<int> &whichList = theLists[i];
				if (theLists.size() != 0)
				{
					list<int>::iterator itr = whichList.begin();
					cout << i;
					while (itr != whichList.end())
					{
						cout << ",\t" << *itr << "\t";
						itr++;
					}
					cout << endl;
				}

			} // end for
		}
		
	private:
		vector<list<int> > theLists; // The array of Lists
		unsigned currentSize;

		int myhash(const int & x) const
		{
			int hashVal = iniHash(x);

			hashVal %= theLists.size();
			if (hashVal < 0)
				hashVal += theLists.size();

			return hashVal;
		}
};

int main()
{
	HashTable oneTwo;
	
// 	1.2. Write your own main to insert the sequence of integers { 121, 81, 16, 100, 25, 0, 1, 9, 4, 36,
// 64, 49,) using a table of size 17.

	int itemsCount = 17;
	int myInts[itemsCount];
	
	myInts[0] = 121;
	myInts[1] = 81;
	myInts[2] = 16;
	myInts[3] = 100;
	myInts[4] = 25;
	myInts[5] = 0;
	myInts[6] = 1;
	myInts[7] = 9;
	myInts[8] = 4;
	myInts[9] = 36;
	myInts[10] = 64;
	myInts[11] = 49;
	
	for (int i = 0; i < 12; ++i)
	{
		oneTwo.insert(myInts[i]);
	} // end for


	oneTwo.printList();


/* 1.3. Run the same sequence using a table of size 7.*/
	HashTable oneThree;

	for (int i = 0; i < 7; ++i)
	{
		oneThree.insert(myInts[i]);
	} // end for


	oneThree.printList();
	
	
/* 	1.5. Rewrite main so that it will replace the sequence above with a random number generator to
 generate randomly 100 integers between the value of 0 and 99 and insert these in a table of
 size 130 and use this data to calculate λ.
 	
 	λ = (#OfElementsInHashTable)/(SizeOfHashTable)*/
    srand(time(0));
	int randomVariable = 0, elementsInHashTable = 100, sizeOfHashTable = 130;
	HashTable oneFive(sizeOfHashTable);
	float lamda = 0;
	
	for(unsigned randomVaraible_i = 0; randomVaraible_i < elementsInHashTable; randomVaraible_i++){
		randomVariable = rand()%100;
		oneFive.insert(randomVariable);
	}
	
	oneFive.printList();
	
	lamda = ((float)elementsInHashTable/(float)sizeOfHashTable);
	
	cout << "λ = " << lamda << endl;

	return 0;
}

int iniHash(const int & key)
{
	int hashVal = 0;

	for (unsigned i = 0; i < key; i++)
	{
		hashVal = 41 * hashVal + key;
	} // end for

	return hashVal;
}

/**
 * Internal method to test if a positive number is prime.
 * Not an efficient algorithm.
 */
bool isPrime(int n)
{
	if (n == 2 || n == 3)
		return true;

	if (n == 1 || n % 2 == 0)
		return false;

	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;

	return true;
}

/**
 * Internal method to return a prime number at least as large as n.
 * Assumes n > 0.
 */
int nextPrime(int n)
{
	if (n % 2 == 0)
		n++;

	for (; !isPrime(n); n += 2)
		;

	return n;
}
