#include <iostream>
using namespace std;

struct Node
{
	int data;					// Int-data of node
	Node* left;					// Pointer to right child
	Node* right;				// Pointer to left child
	Node(int dt = 0);			// Sets data to 0 if not specified
};

Node* z = new Node();			// Instead of NULL
Node* root = z;					// Root node points to z node at start

void Insert(int data);			// Adds node to BST

int main()
{
	Insert(15);
	Insert(5);
	Insert(3);

	return 0;
}

// Node constructor
Node::Node(int dt)
{
	data = dt;
	left = z;				// Children points to z node
	right = z;
}

void Insert(int data) {
	if (root == z)				// If tree is empty
		root = new Node(data);
	else
	{
		Node* newNode = root;	// Starts on root
		while(newNode->left != z || newNode->right != z) // As long as current node has a child
		{
			if (data > newNode->data)		// New node has a greater value
				newNode = newNode->right;	// Go right
			else							// New node has a lesser value
				newNode = newNode->left;	// Go left
		}
		// Found place for new node
		if (newNode == z)							// If placement points to z node
			newNode = new Node(data);
		else if (data > newNode->data)				// If placement points to another node
			newNode->right = new Node(data);		// Create new node as right child
		else
			newNode->left = new Node(data);			// Create new node as left child
	}
	cout << "New node " << data << " added to BST." << endl;
}