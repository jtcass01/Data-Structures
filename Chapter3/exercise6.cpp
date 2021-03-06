/*
//  Created by: Jacob Cassady
//  Date Created: 10/9/2016
//  Last Updated: 10/11/2016
*/

/* Problem Statement
The Josephus problem is the following game:
N people, numbered 1 to N, are sitting in a circle. Starting at person 1, a hot potato is passed. After M passes, the person holding the hot potato is eliminate, the circle closes ranks, and the game continues with the person who was sitting after the eliminated person picking up the hot potato. The last remaining person wins. Thus, if M = 0 and N = 5, players are eliminated in order, and player 5 wins. If M = 1 and N = 5, the order of elimination is 2, 4, 1, 5.
a.  Write a program to solve the Josephus problem for general values of M and N. Try to make your program as efficient as possible. Make sure you dispose of cells.
b.  What is the running time of your program?
c.  If M = 1, what is the running time of your program? How is the actual speed affected by the delete routine for large values of N ( N > 100,000)?
*/

#include <iostream>
#include <assert.h>
#include <ctime>

using namespace std;

/*====================BEGIN PERSON====================*/
class Person {
	friend class Josephus;

public:
  unsigned getPos(void);

private:
  Person(int pos, Person *nextPerson = 0){
    position = pos;
  }

  unsigned position;
  Person *next;
};

unsigned Person::getPos(void){
  return position;
}
/*=====================END PERSON=====================*/

/*===================BEGIN Josephus===================*/
class Josephus {
public:
	class iterator {
		friend class Josephus;

	public:
		Person *current;

		iterator() : current(NULL){}

		const Person & operator*() const {
			return *this->current;
		}

		iterator operator++() {
			iterator old = *this;
			++(*this);
			return old;
		}

		bool operator==(const iterator & rhs) const {
			return current == rhs.current;
		}

		bool operator!=(const iterator & rhs) {
			return !(*this == rhs);
		}

		Person retrieve() const {
			return current->position;
		}

		iterator(Person *p) : current(p){}
	};

	Josephus(int m, int n) {
		people = 0;
		this->m = m;
		this->n = n;

		for(unsigned i = 1; i<(n+1); i++){
			insert(i);
		}
	}

	~Josephus() {
		remove();
	}

	void remove(void);
	void insert(int pos);
	void display(void);
	void remove(int pos);
	int getM(void) { return m ;}
	int getN(void) { return n ;}
	void findWinner(void);

private:
	iterator itr;
	Person *people;
	Person *atEndItem;
	int m;
	int n;
};

void Josephus::insert(int pos){
	Person *pt = new Person(pos, people);

	assert(pt != 0);

	if(people == 0){
		people = pt;
	} else {
		atEndItem->next = pt;
	}

	atEndItem = pt;
}

void Josephus::remove(void){
	Person *pt = people;

	while(pt) {
		Person *temp = pt;
		pt = pt->next;
		delete temp;
	}

	people = atEndItem = 0;
}

void Josephus::display(void){
	cout << "( ";

	for(Person *pt = people; pt; pt = pt->next){
		cout << pt->position << " ";
	}

	cout << ")" << endl;
}

void Josephus::remove(int pos){
	Person *pt = people;

	while(pt && pt->position == pos){
			Person *temp = pt-> next;
			delete pt;
			pt = temp;
	}

	if ((people = pt) == 0){
		atEndItem = 0;
	} else {
		Person *previous = pt;
		pt = pt->next;

		while(pt){
			if(pt->position == pos){
				previous->next = pt->next;
				if(atEndItem == pt) {
					atEndItem = previous;
				}
				delete pt;
				pt = previous->next;
			} else {
				previous = pt;
				pt = pt->next;
			}
		}
	}
}

void Josephus::findWinner(void){
	int i = 0;
	int Nhold = n;
	Person *pt = people;

	while(Nhold>1){
		pt = people;
		while(pt){
			i++;
			if(i>this->getM() && Nhold>1){
				i=0;
				this->remove(pt->position);
				Nhold--;
			}
			pt = pt->next;
		}
	}
	cout << endl;
	cout << "With a M value of " << this->getM() << " and an N value of " << this->getN() << " has a winning value of ";
	this->display();
	cout << endl;
}
/*====================END Josephus====================*/




int main(void){
  clock_t t;

  t=clock();
  Josephus testGame(1,100000);

  testGame.findWinner();
  t = clock() - t;

  cout << "It took me " << ((float)t) << " clicks (" << ((float)t)/CLOCKS_PER_SEC << " seconds)" << endl;
  return 0;
}
