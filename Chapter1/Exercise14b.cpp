/*
//  Created by: Jacob Cassady
//  Date Created: 9/3/2016
//  Last Updated: 9/9/2016
*/

/*  Problem statement:
Design a class template, OrderedCollection, that stores a collection of Comparables (in an array),
along with the current size of the collection.  Provide public functions isEmpty, makeEmpty, insert,
remove, findMin, and findMax.  findMin and findMax return references to the smallest and largest,
respectively, Comparable in the collection.  explain what can be done if these operations are
performed on an empty collection.
*/

#include <iostream>
#include <string>

using namespace std;

template<typename Comparable>
class OrderedCollection{
	public:
		/***************CONSTRUCTORS***************/
		OrderedCollection(void) {
			collectionSize = 0;
			collection[1000] = 0;
		}
		
		OrderedCollection(unsigned size, Comparable intialValue){
			collectionSize = size;
			collection[1000] = 0;
			for(unsigned collection_i=0; collection_i<collectionSize; collection_i++){
				collection[collection_i] = intialValue;
			}
		}
		/***************END CONSTRUCTORS***************/
		
		
		
		/***************ACCESSOR METHODS***************/
		bool isEmpty(void) const{
			if(collectionSize == 0){
				return 0;
			} else {
				return 1;
			}
		}
		
		Comparable findMin(void) const{
			Comparable min;
			min = 0;
			
			if(collectionSize == 0){
				cout << "This collection is empty.  Unable to return min Comparable." << endl;
			} else {
				min = collection[0];
				for(unsigned collection_i = 0; collection_i < collectionSize; collection_i++){
					if(collection[collection_i] < min){
						min = collection[collection_i];
					}
				}
			}
			return min;
		}
		
		Comparable findMax(void) const{
			Comparable max;
			max = 0;
			
			if(collectionSize == 0){
				cout << "This collection is empty.  Unable to return max Comparable." << endl;
			} else {
				max = collection[0];
				for(unsigned collection_i = 0; collection_i<collectionSize; collection_i++){
					if(collection[collection_i] > max){
						max = collection[collection_i];
					}
				}
			}
			return max;
		}
		
		void displayContents(void) const {
			if(collectionSize == 0) {
				cout << "This collection is empty.  There are no contents to display" << endl;
			} else {
				for(unsigned collection_i=0; collection_i<collectionSize; collection_i++){
					cout << collection[collection_i] << endl;
				}
			}
		}
		/***************END ACCESSOR METHODS***************/
		
		
		
		/***************MUTATOR METHODS***************/
		void makeEmpty(void){
			if (collectionSize == 0){
				cout << "This collection is already empty" << endl;
			} else {
				for(unsigned collection_i = 0; collection_i < collectionSize; collection_i++){
					collection[collection_i] = 0;
				}
				collectionSize = 0;
			}
		}
		
		void insert(Comparable newComparable){
			collectionSize++;
			collection[(collectionSize-1)] = newComparable;
		}
		
		void remove(Comparable oldComparable){
		    bool found;
		    unsigned tempCount=0;
		    Comparable tempArray[1000];

		    found = false;
		    for(unsigned collection_i=0; collection_i<collectionSize; collection_i++){
		      if(collection[collection_i] == oldComparable){
		        found = true;
		        for(unsigned i=0; i<collectionSize; i++){
		          if(i != collection_i){
		            tempArray[tempCount] = collection[i];
		            tempCount++;
		          }
		        }
		        break;
		      }
		      if(found){
		        break;
		      }
		    }
		
		    if(found){
		      cout << "We were able to find and delete the first instance of " << oldComparable << "." << endl;
		      
		      
		      for(unsigned collection_i=0; collection_i<collectionSize; collection_i++){
		      	collection[collection_i] = tempArray[collection_i];
		      }
		      
		      collectionSize--;
		    } else {
		      cout << "Comparable not found within collection." << endl;
		    }
			   	
		}
		/***************END MUTATOR METHODS***************/
	private:
		Comparable collection[1000];
		unsigned collectionSize;
};

int main() {
	OrderedCollection<int> templateCollection;	

	templateCollection.insert(5);
	templateCollection.insert(500);
	templateCollection.insert(5000);
	templateCollection.displayContents();
	cout << templateCollection.findMin() << endl;
	cout << templateCollection.findMax() << endl;
	templateCollection.remove(500);
	templateCollection.displayContents();
	templateCollection.makeEmpty();
	cout << templateCollection.findMin() << endl;
	
	return 0;
}
