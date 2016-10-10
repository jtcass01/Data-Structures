/*
//  Created by: Jacob Cassady
//  Date Created: 10/8/2016
//  Last Updated: 10/9/2016
*/

/* Problem Statement

Swap two adjacent elements by adjusting only the links (and not the data) using
a.  singly linked lists
b.  doubly linked lists

*/

#include <assert.h>
#include <iostream>
#include <iterator>

using namespace std;


/*====================BEGIN SINGLE LINKED LIST====================*/
typedef int Type;

enum Boolean
{
	False = 0, True
};

class Item
{
		friend class SLList;

	public:
		Type getVal()
		{
			return val;
		}

	private:
		Item(Type value, Item *item = 0)
		{
			val = value;
			next = item;
		}

		Type val;
		Item *next;
};

class SLList
{
	public:

		class Const_Iterator
		{
				friend class SLList;
			public:
				Item *current;
				Const_Iterator() :
					current(NULL)
				{
				}

				const Item & operator*() const
				{
					return *this->current;
				}

				Const_Iterator operator++()
				{
					current = current->next;
					return *this;
				}

				Const_Iterator operator++(int)
				{
					Const_Iterator old = *this;
					++(*this);
					return old;
				}

				bool operator==(const Const_Iterator & rhs)
				{
					return current == rhs.current;
				}
				bool operator!=(const Const_Iterator & rhs)
				{
					return !(*this == rhs);
				}

				Item retrieve() const
				{
					return current->val;
				}

				Const_Iterator(Item *p) :
					current(p)
				{
				}

		};

		class Iterator
		{
				friend class SLList;
			public:
				Item *current;
				Iterator() :
					current(NULL)
				{
				}

				const Item & operator*() const
				{
					return *this->current;
				}

				Iterator operator++()
				{
					current = current->next;
					return *this;
				}

				Iterator operator++(int)
				{
					Iterator old = *this;
					++(*this);
					return old;
				}

				bool operator==(const Iterator & rhs) const
				{
					return current == rhs.current;
				}
				bool operator!=(const Iterator & rhs)
				{
					return !(*this == rhs);
				}

				Item retrieve() const
				{
					return current->val;
				}

				Iterator(Item *p) :
					current(p)
				{
				}
		};

		SLList()
		{
			list = 0;
		}
		~SLList()
		{
			remove();
		}

		void insert(Type someItem);
		void append(Type someItem);
		int remove(Type someItem);
		void remove();
		void swapRight(Iterator itr);

		Item *atEnd();
		Item *head();
		Item *tail();

		Boolean isPresent(Type someItem);
		Boolean isEmpty();
		void display();

	private:
		Iterator iterator;
		Item *list;
		Item *atEndItem;
};

Boolean SLList::isEmpty()
{
	return list == 0 ? True : False;
}

void SLList::insert(Type val)
{
	Item *pt = new Item(val, list); // create new item put it in front of list
	assert(pt != 0);
	if (list == 0)
	{
		atEndItem = pt;
	}
	list = pt; // and point next top the list
}

Item *SLList::atEnd()
{
	if (list == 0)
	{
		return 0;
	}

	Item *prev, *curr;
	prev = curr = list;

	while (curr)
	{
		prev = curr;
		curr = curr->next;
	}
	return prev;
}

Item *SLList::tail()
{
	if (list == 0)
	{
		return 0;
	}

	Item *prev, *curr;
	prev = curr = list;

	while (curr)
	{
		prev = curr;
		curr = curr->next;
	}
	return prev;
}

Item *SLList::head()
{
	if (list == 0)
	{
		cout << "List is empty" << endl;
		return 0;
	}
	else
	{
		return list;
	} // end if
	return list;
}

void SLList::append(Type val)
{
	Item *pt = new Item(val);
	assert(pt != 0);
	if (list == 0)
	{
		list = pt;
	}
	else
	{
		atEndItem->next = pt;
	}
	atEndItem = pt;
}

void SLList::display()
{
	cout << "(";
	for (Item *pt = list; pt; pt = pt->next)
	{
		cout << pt->val << " ";
	} // end for
	cout << ")" << endl;
}

void SLList::remove()
{
	Item *pt = list;
	while (pt)
	{
		Item *temp = pt;
		pt = pt->next;
		delete temp;
	} // end while
	list = atEndItem = 0;
}

Boolean SLList::isPresent(Type item)
{
	Boolean rc = False;
	if (list != 0)
	{
		if (list->val == item || atEndItem->val == item)
		{
			rc = True;
		}
		else
		{
			Item *pt = list->next;
			for (; pt != atEndItem; pt = pt->next)
			{
				if (pt->val == item)
				{
					rc = True;
				} // end if
			} // end for
		} // end if
	} // end if
	return rc;
}

int SLList::remove(Type val)
{
	Item *pt = list;
	int cnt = 0;

	while (pt && pt->val == val)
	{
		Item *tmp = pt->next;
		delete pt;
		cnt++;
		pt = tmp;
	} // end while

	if ((list = pt) == 0)
	{
		atEndItem = 0;
		return cnt;
	} // end if

	Item *prv = pt;
	pt = pt->next;

	while (pt)
	{
		if (pt->val == val)
		{
			prv->next = pt->next;
			if (atEndItem == pt)
			{
				atEndItem = prv;
			} // end if
			delete pt;
			++cnt;
			pt = prv->next;
		}
		else
		{
			prv = pt;
			pt = pt->next;
		} // end if else
	} // end while
	return cnt;
}

void SLList::swapRight(Iterator itr){
	Item *beforeCurrent;
	Iterator tempItr = this->head();

	for(tempItr = this->head(); tempItr != this->tail(); tempItr++){
		if((tempItr.current->next) == itr.current){
			beforeCurrent = tempItr.current;
		}
	}

	Item *current = itr.current;
	Item *afterCurrent = itr.current->next;

	beforeCurrent->next = afterCurrent;
	current->next = afterCurrent->next;
	afterCurrent->next = current;
	current= afterCurrent;
	afterCurrent = current;
}

/*=====================END SINGLE LINKED LIST=====================*/



/*====================BEGIN DOUBLE LINKED LIST====================*/

template<typename Container>
void printCollection(const Container & c, ostream & out = cout)
{
	if (c.empty())
		out << "(empty)";
	else
	{
		typename Container::const_iterator itr = c.begin();
		out << "[ " << *itr++; // Print first item

		while (itr != c.end())
			out << ", " << *itr++;
		out << " ]" << endl;
	}
}


template <typename Object>
class List
{
private:

    struct Node
    {
        Object  data;
        Node   *prev;
        Node   *next;

        Node( const Object & d = Object( ), Node * p = NULL, Node * n = NULL )  : data( d ), prev( p ), next( n ) { }
    };


    public:
        class const_iterator
        {
        public:

            // Public constructor for const_iterator.
            const_iterator( ) : current( NULL )
            { }

            // Return the object stored at the current position.
            // For const_iterator, this is an accessor with a
            // const reference return type.
            const Object & operator* ( ) const
            { return retrieve( ); }

            const_iterator & operator++ ( )
            {
                current = current->next;
                return *this;
            }

            const_iterator operator++ ( int )
            {
                const_iterator old = *this;
                ++( *this );
                return old;
            }

            const_iterator & operator-- ( )
            {
                current = current->prev;
                return *this;
            }

            const_iterator operator-- ( int )
            {
                const_iterator old = *this;
                --( *this );
                return old;
            }

            bool operator== ( const const_iterator & rhs ) const
            { return current == rhs.current; }

            bool operator!= ( const const_iterator & rhs ) const
            { return !( *this == rhs ); }

        protected:
            Node *current;

            // Protected helper in const_iterator that returns the object
            // stored at the current position. Can be called by all
            // three versions of operator* without any type conversions.
            Object & retrieve( ) const
            { return current->data; }

            // Protected constructor for const_iterator.
            // Expects a pointer that represents the current position.
            const_iterator( Node *p ) :  current( p )
            { }

            friend class List<Object>;
        };

        class iterator : public const_iterator
        {
        public:

            // Public constructor for iterator.
            // Calls the base-class constructor.
            // Must be provided because the private constructor
            // is written; otherwise zero-parameter constructor
            // would be disabled.
            iterator( )
            { }

            Object & operator* ( )
            { return current->data; }

            // Return the object stored at the current position.
            // For iterator, there is an accessor with a
            // const reference return type and a mutator with
            // a reference return type. The accessor is shown first.
            const Object & operator* ( ) const
            { return const_iterator::operator*( ); }

            iterator & operator++ ( )
            {
                current = current->next;
                return *this;
            }

            iterator operator++ ( int )
            {
                iterator old = *this;
                ++( *this );
                return old;
            }

            iterator & operator-- ( )
            {
                current = current->prev;
                return *this;
            }

            iterator operator-- ( int )
            {
                iterator old = *this;
                --( *this );
                return old;
            }

        protected:

            Node *current;
            // Protected constructor for iterator.
            // Expects the current position.
            iterator( Node *p ) : const_iterator( p )
            { current = p;}

            friend class List<Object>;
        };

public:
    List( )
    { init( ); }

    ~List( )
    {
        clear( );
        delete head;
        delete tail;
    }

    List( const List & rhs )
    {
        init( );
        *this = rhs;
    }

    const List & operator= ( const List & rhs )
    {
        if( this == &rhs )
            return *this;
        clear( );
        for( const_iterator itr = rhs.begin( ); itr != rhs.end( ); ++itr )
            push_back( *itr );
        return *this;
    }

    // Return iterator representing beginning of list.
    // Mutator version is first, then accessor version.
    iterator begin( )
    { return iterator( head->next ); }

    const_iterator begin( ) const
    { return const_iterator( head->next ); }

    // Return iterator representing endmarker of list.
    // Mutator version is first, then accessor version.
    iterator end( )
    { return iterator( tail ); }

    const_iterator end( ) const
    { return const_iterator( tail ); }

    // Return number of elements currently in the list.
    int size( ) const
    { return theSize; }

    // Return true if the list is empty, false otherwise.
    bool empty( ) const
    { return size( ) == 0; }

    void clear( )
    {
        while( !empty( ) )
            pop_front( );
    }

    // front, back, push_front, push_back, pop_front, and pop_back
    // are the basic double-ended queue operations.
    Object & front( )
    { return *begin( ); }

    const Object & front( ) const
    { return *begin( ); }

    Object & back( )
    { return *--end( ); }

    const Object & back( ) const
    { return *--end( ); }

    void push_front( const Object & x )
    { insert( begin( ), x ); }

    void push_back( const Object & x )
    { insert( end( ), x ); }

    void pop_front( )
    { erase( begin( ) ); }

    void pop_back( )
    { erase( --end( ) ); }

    // Insert x before itr.
    iterator insert( iterator itr, const Object & x )
    {
        Node *p = itr.current;
        theSize++;
        return iterator( p->prev = p->prev->next = new Node( x, p->prev, p ) );
    }

    // Erase item at itr.
    iterator erase( iterator itr )
    {
        Node *p = itr.current;
        iterator retVal( p->next );
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        theSize--;

        return retVal;
    }

    iterator erase( iterator start, iterator end )
    {
        for( iterator itr = start; itr != end; )
            itr = erase( itr );

        return end;
    }
    void swapNeighbors(iterator itr)
    {
        Node *p = itr.current;
        Node *beforep = p->prev;
        Node *afterp = p->next;
        Node *swapHead = beforep->prev;
        Node *swapTail = afterp->next;

        p->next = beforep;
        p->prev = afterp;
        beforep->next = swapTail;
        beforep->prev = p;
        afterp->next = p;
        afterp->prev = swapHead;
        swapHead->next = afterp;
        swapTail->prev = beforep;
    }

		void swapRight(iterator itr){
				Node *current = itr.current;
				Node *beforeCurrent = current->prev;
				Node *afterCurrent = current->next;
				Node *twiceAfterCurrent = afterCurrent->next;

				beforeCurrent->next = afterCurrent;
				current->prev = afterCurrent;
				current->next = twiceAfterCurrent;
				afterCurrent->prev = beforeCurrent;
				afterCurrent->next = current;
				current = afterCurrent;
				afterCurrent = afterCurrent->next;
		}

private:
    int   theSize;
    Node *head;
    Node *tail;

    void init( )
    {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }
};

/*=====================END DOUBLE LINKED LIST=====================*/


int main()
{
	SLList testSingleList;
	SLList::Iterator testSIterator;

	for(unsigned i=0; i<10; i++){
		testSingleList.append(i);
	}

	testSingleList.display();

	for(testSIterator = testSingleList.head(); testSIterator != testSingleList.tail(); testSIterator++){
		if(testSIterator.current->getVal() == 5){
			cout << "swapRight() is being applied to: " << testSIterator.current->getVal() << endl;
			testSingleList.swapRight(testSIterator);
		}
	}

	testSingleList.display();

	List<int> testDoubleList;
	List<int>::iterator testDIterator;

	for(unsigned i = 0; i<10; i++){
		testDoubleList.push_back(i);
	}

	printCollection(testDoubleList, cout);

	testDIterator = testDoubleList.begin();

	for(unsigned i=0; i<5; i++){
			testDIterator++;
	}

	cout << "swapRight() is being applied to: " << *testDIterator << endl;
	testDoubleList.swapRight(testDIterator);

	printCollection(testDoubleList, cout);


	return 0;
}
