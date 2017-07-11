#include <iostream>
using namespace std;

struct Node
{
	int data;						// Int-data of node
	Node* left;						// Pointer to right child
	Node* right;					// Pointer to left child
	Node(int dt = 0);				// Sets data to 0 if not specified
};

Node* z = new Node();				// Instead of NULL
Node* root = z;						// Root node points to z node at start

Node* Insert(Node* newNode, int data);	// Adds node to BST
void InorderTrav(Node* t);				// <Left><Data><Right>
void PreorderTrav(Node* t);				// <Data><Left><Right>
void PostorderTrav(Node* t);			// <Left><Right><Data>

int main()
{
	root = Insert(root, 4);
	root = Insert(root, 2);
	root = Insert(root, 1);
	root = Insert(root, 3);
	root = Insert(root, 7);
	root = Insert(root, 6);
	PostorderTrav(root);

	return 0;
}

// Node constructor
Node::Node(int dt)
{
	data = dt;
	left = z;						// Children points to z node
	right = z;
}

Node* Insert(Node* newNode, int data)
{
	// Tree/sub tree is not empty
	if (newNode != z)
	{
		if (data > newNode->data)	// Insertion node has greater value
			newNode->right = Insert(newNode->right, data);
		else						// Insertion node has lesser value
			newNode->left = Insert(newNode->left, data);
		return newNode;				// Returns the node (with new connection)
	}
	// Tree/sub tree is empty
	else
		return new Node(data);		// Creates a new node and returns it
}

void InorderTrav(Node* t)
{
	if (t != z)						// Tree is not empty
	{
		InorderTrav(t->left);		// Go left
		cout << t->data << endl;	// Print data
		InorderTrav(t->right);		// Go right
	}
}

void PreorderTrav(Node* t)
{
	if (t != z)						// Tree is not empty
	{
		cout << t->data << endl;	// Print data
		PreorderTrav(t->left);		// Go left
		PreorderTrav(t->right);		// Go right
	}
}

void PostorderTrav(Node* t)
{
	if (t != z)						// Tree is not empty
	{
		PostorderTrav(t->left);		// Go left
		PostorderTrav(t->right);	// Go right
		cout << t->data << endl;	// Print data
	}
}