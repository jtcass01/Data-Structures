/*
//  Created by: Jacob Cassady
//  Date Created: 10/9/2016
//  Last Updated: 10/9/2016
*/

/* Problem Statement
The Josephus problem is the following game:
N people, numbered 1 to N, are sitting in a circle. Starting at person 1, a hot potato is passed. After M passes, the person holding the hot potato is eliminated,
the circle closes ranks, and the game continues with the person who was sitting after the eliminated person picking up the hot potato. The last remaining person wins.
Thus, if M = 0 and N = 5, players are eliminated in order, and player 5 wins. If M = 1and N = 5, the order of elimination is 2, 4, 1, 5.
a.  Write a program to solve the Josephus problem for general values of M and N. Try to make your program as efficient as possible.
Make sure you dispose of cells.
b.  What is the running time of your program?
c.  If M = 1, what is the running time of your program? How is the actual speed affected by the delete routine for large values of
N ( N > 100,000)?
*/

#include <iostream>

using namespace std;

class Person {
public:
  unsigned getPos(void);

private:
  Person(unsigned pos, Person *prevPerson = 0, Person *currentPerson = 0, Person *nextPerson = 0){
    position = pos;
    
  }
  
  unsigned position;
  Person *current;
  Person *next;
  Person *previous;
};

unsigned Person::getPos(void){
  return position;
}


int main(void){
  Person testPerson(2);
  cout << testPerson.getPos() << endl;

  return 0;
}
