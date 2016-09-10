/*
//  Created by: Jacob Cassady
//  Date created: 9/2/2016
//  Last updated: 9/4/2016
*/

/* Design a class template, Collection, that stores a collection of Objects (in an array),
  along with the current size of the collection.  Provide public functions isEmpty, makeEmpty,
  insert, remove, and contains.  contains(x) returns true if and only if an object that is
  equal to x is present in the collection.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename Object>
class Collection {
public:
  //CONSTRUCTORS
  Collection(){

  }

  Collection (int size){
    collection.resize(size);
  }

  //ACCESSOR METHODS
  bool contains(Object waldo) const{
    for(unsigned collection_i=0; collection_i<collection.size(); collection_i++){
      if (collection.at(collection_i) == waldo){
        cout << "Collection contains " << waldo << endl;
        return true;
      }
    }
    cout << "Unable to find " << waldo << " in collection." << endl;
    return false;
  }

  void displayContents(void) const{
    if (collection.empty()){
      cout << "There are no contents in this collection to display." << endl;
    } else {
      for(unsigned collection_i=0; collection_i<collection.size(); collection_i++){
        cout << collection.at(collection_i) << endl;
      }
    }
  }

  bool isEmpty(void) const{
      if(collection.empty()){
        return true;
      } else {
        return false;
      }
  }

  //MUTATOR METHODS
  void makeEmpty(void){
    collection.clear();
  }

  void insert(Object newObject){
    collection.push_back(newObject);
  }

  void remove(Object oldObject){ //Removes the first object found in vector that matches the given object.
    bool found;
    vector<Object> temp;

    found = false;

    for(unsigned collection_i=0; collection_i<collection.size(); collection_i++){
      if(collection.at(collection_i) == oldObject){
        for(unsigned i=0; i<collection.size(); i++){
          if(i!=collection_i){
            temp.push_back(collection.at(i));
          }
        }
        collection.swap(temp);
        found = true;
        break;
      }
      if(found){ //If found once, stop looking.
        break;
      }
    }
    if(found){
      cout << "We were able to delete the desired object." << endl;
    } else {
      cout << "Object not found." << endl;
    }
  }

private:
  vector<Object> collection;
};

int main(){
  Collection<int> testCollection;

  testCollection.insert(1);
  testCollection.insert(2);
  testCollection.insert(3);
  testCollection.insert(4);
  testCollection.insert(3);
  testCollection.displayContents();
  testCollection.remove(3);
  testCollection.remove(5);
  testCollection.displayContents();
  testCollection.makeEmpty();
  testCollection.displayContents();
  testCollection.insert(5);
  testCollection.insert(6);
  testCollection.insert(7);
  testCollection.displayContents();
  testCollection.contains(6);
  testCollection.contains(7);
  testCollection.contains(8);

  return 0;
}
