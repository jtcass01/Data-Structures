/*
//  Created by: Jacob Cassady
//  Date Created: 10/27/2016
//  Last Updated: 10/27/2016
*/

/* Problem Statement:
b. Show the result of deleting the root
*/

#include <iostream>
#include <list>
using namespace std;

template<typename Comparable>
class BinarySearchTree
{
	public:
		BinarySearchTree()
		{
			root = NULL;
		}
		BinarySearchTree(const BinarySearchTree & rhs);
		/**
		 * Destructor for the tree
		 */
		~BinarySearchTree()
		{
			makeEmpty();
		}

		const Comparable & findMin() const
		{
			return findMin(root);
		}

		const Comparable & findMax() const
		{
			return findMax(root);
		}

		/**
		 * Returns true if x is found in the tree.
		 */
		bool contains(const Comparable & x) const
		{
			return contains(x, root);
		}

		bool isEmpty() const
		{
			return ((root == NULL) ? true : false);
		}
		/**
		 * Print the tree contents in sorted order.
		 */
		void printTree(ostream & out = cout) const
		{
			out << "Start Traversing" << endl;
			if (isEmpty())
				out << "Empty tree" << endl;
			else
				printTree(root, out);
			out << "End Traversing" << endl;
		}

		void makeEmpty()
		{
			makeEmpty(root);
		}
		/**
		 * Insert x into the tree; duplicates are ignored.
		 */
		void insert(const Comparable & x)
		{
			insert(x, root);
		}

		/**
		 * Remove x from the tree. Nothing is done if x is not found.
		 */
		void remove(const Comparable & x)
		{
			remove(x, root);
		}

		/**
		 * Deep copy.
		 */
		const BinarySearchTree & operator=(const BinarySearchTree & rhs)
		{
			if (this != &rhs)
			{
				makeEmpty();
				root = clone(rhs.root);
			}
			return *this;
		}

	private:
		struct BinaryNode
		{
				Comparable element;
				BinaryNode *left;
				BinaryNode *right;

				BinaryNode(const Comparable & theElement, BinaryNode *lt, BinaryNode *rt) :
					element(theElement), left(lt), right(rt)
				{
				}
		};

		BinaryNode *root;

		/**
		 * Internal method to insert into a subtree.
		 * x is the item to insert.
		 * t is the node that roots the subtree.
		 * Set the new root of the subtree.
		 */
		void insert(const Comparable & x, BinaryNode * & t)
		{
			if (t == NULL)
				t = new BinaryNode(x, NULL, NULL);
			else if (x < t->element)
				insert(x, t->left);
			else if (t->element < x)
				insert(x, t->right);
			else
				; // Duplicate; do nothing
		}
		/**
		 * Internal method to remove from a subtree.
		 * x is the item to remove.
		 * t is the node that roots the subtree.
		 * Set the new root of the subtree.
		 */
		void remove(const Comparable & x, BinaryNode * & t)
		{
			if (t == NULL)
				return; // Item not found; do nothing
			if (x < t->element)
				remove(x, t->left);
			else if (t->element < x)
				remove(x, t->right);
			else if (t->left != NULL && t->right != NULL) // Two children
			{
				t->element = findMin(t->right)->element;
				remove(t->element, t->right);
			}
			else
			{
				BinaryNode *oldNode = t;
				t = (t->left != NULL) ? t->left : t->right;
				delete oldNode;
			}
		}
		/**
		 * Internal method to find the smallest item in a subtree t.
		 * Return node containing the smallest item.
		 */
		BinaryNode * findMin(BinaryNode *t) const
		{
			if (t == NULL)
				return NULL;
			if (t->left == NULL)
				return t;
			return findMin(t->left);
		}
		/**
		 * Internal method to find the largest item in a subtree t.
		 * Return node containing the largest item.
		 */
		BinaryNode * findMax(BinaryNode *t) const
		{
			if (t != NULL)
				while (t->right != NULL)
					t = t->right;
			return t;
		}

		/**
		 * Internal method to test if an item is in a subtree.
		 * x is item to search for.
		 * t is the node that roots the subtree.
		 */
		bool contains(const Comparable & x, BinaryNode *t) const
		{
			if (t == NULL)
				return false;
			else if (x < t->element)
				return contains(x, t->left);
			else if (t->element < x)
				return contains(x, t->right);
			else
				return true; // Match
		}
		/**
		 * Internal method to make subtree empty.
		 */
		void makeEmpty(BinaryNode * & t)
		{
			if (t != NULL)
			{
				makeEmpty(t->left);
				makeEmpty(t->right);
				delete t;
			}
			t = NULL;
		}
		/**
		 * Internal method to compute the height of a subtree rooted at t.
		 */
		int height(BinaryNode *t)
		{
			if (t == NULL)
				return -1;
			else
				return 1 + max(height(t->left), height(t->right));
		}
		/**
		 * Internal method to print a subtree rooted at t in sorted order.
		 */
		void printTree(BinaryNode *t, ostream & out) const
		{
			if (t != NULL)
			{
				printTree(t->left, out);
				out << t->element << endl;
				printTree(t->right, out);
			}
		}
		/**
		 * Internal method to clone subtree.
		 */
		BinaryNode * clone(BinaryNode *t) const
		{
			if (t == NULL)
				return NULL;

			return new BinaryNode(t->element, clone(t->left), clone(t->right));
		}
};

int main()
{
	cout << "Starting!" << endl;

	list<int> insertList;
	insertList.push_back(3);
	insertList.push_back(1);
	insertList.push_back(4);
	insertList.push_back(6);
	insertList.push_back(9);
	insertList.push_back(2);
	insertList.push_back(5);
	insertList.push_back(7);

	BinarySearchTree<int> myTree;

	for(list<int>::iterator it = insertList.begin(); it != insertList.end(); it++){
		myTree.insert(*it);
		cout << "Inserted " << *it << endl;

	}
	
	myTree.printTree(cout);
	myTree.remove(3);
	cout << "Removed  3" << endl;
	myTree.printTree(cout);
	cout << "Ending!" << endl;
	
	return 0;
}
