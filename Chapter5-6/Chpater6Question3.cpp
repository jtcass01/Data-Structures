/*
**
**@Author        Jacob Taylor Cassady
**@Class         CECS302 - Data Structures
**@Instructor    Dr. Ibrahim Imam
**@Assignment    5
**@Question      3
**@Date Created  11/22/2016
**@Last Updated  11/22/2016
**
*/


/* Problem Statement
3.1. Write a c++ program that uses my code of Priority Queue to implement finding the kth
smallest element in a sequence of integers.
3.2. Use your program to find the 5th smallest element in the sequence used in problem 1 above. 
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class UnderflowException
{
};

template<typename Comparable>
class BinaryHeap
{
	public:
		explicit BinaryHeap(int capacity = 100) :
			array(capacity + 1), currentSize(0)
		{
		}

		explicit BinaryHeap(const vector<Comparable> & items) :
			array(items.size() + 10), currentSize(items.size())
		{
			for (int i = 0; i < items.size(); i++)
				array[i + 1] = items[i];
			buildHeap();
		}

		bool isEmpty() const
		{
			return currentSize == 0;
		}

		/**
		 * Find the smallest item in the priority queue.
		 * Return the smallest item, or throw Underflow if empty.
		 */
		const Comparable & findMin() const
		{
			if (isEmpty())
				throw UnderflowException();
			return array[1];
		}
		/**
		 * Insert item x, allowing duplicates.
		 */
		void insert(const Comparable & x)
		{
			if (currentSize == array.size() - 1)
				array.resize(array.size() * 2);

			// Percolate up
			int hole = ++currentSize;
			for (; hole > 1 && x < array[hole / 2]; hole /= 2)
			{
					array[hole] = array[hole / 2];
			}
				
			array[hole] = x;
		}

		/**
		 * Remove the minimum item.
		 * Throws UnderflowException if empty.
		 */
		void deleteMin()
		{
			if (isEmpty())
				throw UnderflowException();

			array[1] = array[currentSize--];
			percolateDown(1);
		}

		/**
		 * Remove the minimum item and place it in minItem.
		 * Throws Underflow if empty.
		 */
		void deleteMin(Comparable & minItem)
		{
			if (isEmpty())
				throw UnderflowException();

			minItem = array[1];
			array[1] = array[currentSize--];
			percolateDown(1);
		}

		void makeEmpty()
		{
			currentSize = 0;
		}

		void printHeap()
		{
			cout << "[";
			for (unsigned i = 0; i <= currentSize; i++)
				cout << array[i] << ",";
			cout << "]" << endl;
		}

	private:
		vector<Comparable> array; // The heap array
		unsigned currentSize; // Number of elements in heap


		/**
		 * Establish heap order property from an arbitrary
		 * arrangement of items. Runs in linear time.
		 */
		void buildHeap()
		{
			for (int i = currentSize / 2; i > 0; i--)
				percolateDown(i);
		}

		/**
		 * Internal method to percolate down in the heap.
		 * hole is the index at which the percolate begins.
		 */
		void percolateDown(unsigned hole)
		{
			unsigned child;
			Comparable tmp = array[hole];

			for (; hole * 2 <= currentSize; hole = child)
			{
				child = hole * 2;
				if (child != currentSize && array[child + 1] < array[child])
					child++;
				if (array[child] < tmp)
					array[hole] = array[child];
				else
					break;
			}
			array[hole] = tmp;
		}
};

int main(void)
{

/* 3.1. Write a c++ program that uses my code of Priority Queue to implement finding the kth
smallest element in a sequence of integers.*/
	BinaryHeap<int> threeOne(15);
	int k=0, min=0;

	for(unsigned threeOne_i = 1; threeOne_i <= 15; threeOne_i++){
		if(threeOne_i % 2 == 0){
			threeOne.insert(pow(threeOne_i,2));
		} else {
			threeOne.insert(threeOne_i*2);
		}
	}
	
	threeOne.printHeap();
	
	cout << "Enter k: ";
	cin >> k;

	for(unsigned k_i = 1; k_i < k; k_i++){
		threeOne.deleteMin();	
	}
	
	min = threeOne.findMin();
	cout << "min: " << min << endl;
	

/*1.2. Write your own main to insert the sequence of integers { 121, 81, 16, 100, 25, 0, 1, 9, 4, 36,
64, 49,) using a table of size 17. */
/*3.2. Use your program to find the 5th smallest element in the sequence used in problem 1 above. */
	BinaryHeap<int> threeTwo(12);
	
	for(unsigned threeTwo_i = 0; threeTwo_i < 12; threeTwo_i++){
		threeTwo.insert(pow(threeTwo_i,2));
	}
	
	threeTwo.printHeap();

	for(unsigned k_i = 1; k_i < 5; k_i++){
		threeTwo.deleteMin();	
	}

	min = threeTwo.findMin();
	cout << "Fifth Smallest Element = " << min << endl;

	return 0;
}
