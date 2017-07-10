#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int dt = 0);
};

Node* z = new Node();			// Istedenfor NULL
Node* root = z;					// Rotnode

void Insert(int data);			// Legger til node i tre

int main()
{
	Insert(15);
	Insert(5);
	Insert(3);

	return 0;
}

// Node constructor
Node::Node(int dt)			// Data settes til 0 om ikke param. er spesifisert
{
	data = dt;
	left = z;				// Barna settes til z-node
	right = z;
}

void Insert(int data) {
	if (root == z)				// Hvis tomt tre
		root = new Node(data);
	else
	{
		Node* newNode = root;	// Starter på rotnode
		while(newNode->left != z || newNode->right != z) // Så lenge noden har minst ett barn
		{
			if (data > newNode->data)		// Ny node har større verdi
				newNode = newNode->right;	// Gå til høyre
			else							// Ny node har mindre verdi
				newNode = newNode->left;	// Gå til venstre
		}
		// Funnet plass for ny node
		if (newNode == z)							// Hvis aktuell node er z-node
			newNode = new Node(data);
		else if (data > newNode->data)
			newNode->right = new Node(data);		// Opprett ny node som høyre barn
		else
			newNode->left = new Node(data);			// Opprett ny node som venstre barn
	}
	cout << "New node " << data << " added to BST." << endl;
}