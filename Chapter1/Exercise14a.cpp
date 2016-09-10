/*
//  Created by: Jacob Cassady
//  Date Created: 9/3/2016
//  Last Updated: 9/4/2016
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
#include <vector>

using namespace std;

template<typename Comparable>
class OrderedCollection {
public:
  //CONSTRUCTORS
  OrderedCollection(){
    collectionSize = 0;
  }

  OrderedCollection(int size){
    collectionSize = size;
    collection.resize(collectionSize);
  }

  //ACCESSOR METHODS
  bool isEmpty() const{
    if(collection.empty()){
      return true;
    } else {
      return false;
    }
  }

  void displayContents() const {
    if(collection.empty()){
      cout << "This collection is empty.  There are no contents to display." << endl;
    } else {
      for (unsigned collection_i=0; collection_i < collection.size(); collection_i++){
        cout << collection.at(collection_i) << endl;
      }
    }
  }

  Comparable findMax() const{
    Comparable max;
    max = 0;

    if(collection.empty()){
      cout << "This collection is empty.  Unable to return max Comparable." << endl;
    } else {
      max = collection.at(0);

      for(unsigned collection_i = 0; collection_i< collection.size(); collection_i++){
        if(max < collection.at(collection_i)){
          max = collection.at(collection_i);
        }
      }
    }
    return max;
  }

  Comparable findMin() const{
    Comparable min;
    min = 0;

    if(collection.empty()){
      cout << "This collection is empty.  Unable to return min Comparable." << endl;
    } else {
      min = collection.at(0);

      for(unsigned collection_i = 0; collection_i<collection.size();collection_i++){
        if(min > collection.at(collection_i)){
          min = collection.at(collection_i);
        }
      }
    }
    return min;
  }

  //MUTATOR METHODS
  void makeEmpty(void){
    collection.clear();
  }

  void insert(Comparable newComparable){
    collection.push_back(newComparable);
  }

  void remove(Comparable oldComparable){
    bool found;
    vector<Comparable> temp;

    found = false;
    for(unsigned collection_i=0; collection_i<collection.size(); collection_i++){
      if(collection.at(collection_i) == oldComparable){
        found = true;
        for(unsigned i=0; i<collection.size(); i++){
          if(i != collection_i){
            temp.push_back(collection.at(i));
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
    } else {
      cout << "Comparable not found within collection." << endl;
    }
  }

private:
  vector<Comparable> collection;
  int collectionSize;
};

//SPECIALIZED CLASS TEMPLATE TO HANDLE STRINGS.  THIS WAS NEEDED FOR FIND MIN/MAX FUNCTIONS
template<>
class OrderedCollection <string>{
public:
  //CONSTRUCTORS
  OrderedCollection(){
    collectionSize = 0;
  }

  OrderedCollection(int size){
    collectionSize = size;
    collection.resize(collectionSize);
  }

  //ACCESSOR METHODS
  bool isEmpty() const{
    if(collection.empty()){
      return true;
    } else {
      return false;
    }
  }

  void displayContents() const {
    if(collection.empty()){
      cout << "This collection is empty.  There are no contents to display." << endl;
    } else {
      for (unsigned collection_i=0; collection_i < collection.size(); collection_i++){
        cout << collection.at(collection_i) << endl;
      }
    }
  }

  string findMax(){
    string max;
    max = "";

    if(collection.empty()){
      cout << "This collection is empty.  Unable to return max Comparable." << endl;
      max = "Error.  findMax function called on empty collection vector.";
    } else {
      max = collection.at(0);

      for(unsigned collection_i = 0; collection_i< collection.size(); collection_i++){
        if(max.length() < collection.at(collection_i).length()){
          max = collection.at(collection_i);
        }
      }
    }
    return max;
  }

  string findMin() const{
    string min;
    min = "";

    if(collection.empty()){
      cout << "This collection is empty.  Unable to return min Comparable." << endl;
      min = "Error.  findMin function called on empty collection vector.";
    } else {
      min = collection.at(0);

      for(unsigned collection_i = 0; collection_i<collection.size();collection_i++){
        if(min.length() > collection.at(collection_i).length()){
          min = collection.at(collection_i);
        }
      }
    }
    return min;
  }

  //MUTATOR METHODS
  void makeEmpty(void){
    collection.clear();
  }

  void insert(string newComparable){
    collection.push_back(newComparable);
  }

  void remove(string oldComparable){
    bool found;
    vector<string> temp;

    found = false;
    for(unsigned collection_i=0; collection_i<collection.size(); collection_i++){
      if(collection.at(collection_i) == oldComparable){
        found = true;
        for(unsigned i=0; i<collection.size(); i++){
          if(i != collection_i){
            temp.push_back(collection.at(i));
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
    } else {
      cout << "Comparable not found within collection." << endl;
    }
  }

private:
  vector<string> collection;
  int collectionSize;
};

int main(){
  OrderedCollection<string> stringCollection;
  OrderedCollection<int> templateCollection;

  stringCollection.insert("why");
  stringCollection.insert("so");
  stringCollection.insert("serious");
  stringCollection.displayContents();
  cout << stringCollection.findMin() << endl;
  cout << stringCollection.findMax() << endl;
  stringCollection.makeEmpty();
  cout << stringCollection.findMin() << endl;

  templateCollection.insert(5);
  templateCollection.insert(500);
  templateCollection.insert(50000);
  cout << templateCollection.findMin() << endl;
  cout << templateCollection.findMax() << endl;
  templateCollection.makeEmpty();
  cout << templateCollection.findMin() << endl;

  return 0;
}
