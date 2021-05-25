// CPP program to find Levelorder
// successor of given node in the
// Binary Tree

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
	struct Node *left, *right;
	int value;
};

// Utility function to create a
// new node with given value
struct Node* newNode(int value)
{
	Node* temp = new Node;
	temp->left = temp->right = NULL;
	temp->value = value;

	return temp;
}

// Function to find the Level Order Successor
// of a given Node in Binary Tree
Node* levelOrderSuccessor(Node* root, Node* key)
{
	// Base Case
	if (root == NULL)
		return NULL;

	// If root equals to key
	if (root == key) {

		// If left child exists it will be
		// the Postorder Successor
		if (root->left)
			return root->left;

		// Else if right child exists it will be
		// the Postorder Successor
		else if (root->right)
			return root->right;
		else
			return NULL; // No Successor
	}

	// Create an empty queue for level
	// order traversal
	queue<Node*> q;

	// Enqueue Root
	q.push(root);

	while (!q.empty()) {
		Node* nd = q.front();
		q.pop();

		if (nd->left != NULL) {
			q.push(nd->left);
		}

		if (nd->right != NULL) {
			q.push(nd->right);
		}

		if (nd == key)
			break;
	}

	return q.front();
}

// Driver code
int main()
{
	struct Node* root = newNode(20);
	root->left = newNode(10);
	root->left->left = newNode(4);
	root->left->right = newNode(18);
	root->right = newNode(26);
	root->right->left = newNode(24);
	root->right->right = newNode(27);
	root->left->right->left = newNode(14);
	root->left->right->left->left = newNode(13);
	root->left->right->left->right = newNode(15);
	root->left->right->right = newNode(19);

	struct Node* key = root->right->left; // node 24

	struct Node* res = levelOrderSuccessor(root, key);

	if (res)
		cout << "LevelOrder successor of "
			<< key->value << " is " << res->value;
	else
		cout << "LevelOrder successor of "
			<< key->value << " is " << "NULL";

	return 0;
}
