#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* CreateNode(int data)
{
	struct Node* Node = new struct Node;
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	return(Node);
}

void Preorder(Node *root)
{
	// Base Case
	if (root == NULL)
	return;

	stack<Node *> NodeStack;
	NodeStack.push(root);
    while (NodeStack.empty() == false)
	{
		struct Node *Node = NodeStack.top();
		printf ("%d ", Node->data);
		NodeStack.pop();
    
    	if (Node->right)
			NodeStack.push(Node->right);
		if (Node->left)
			NodeStack.push(Node->left);
	}
}


int main()
{
/* Constructed binary tree is
		10
	   / \
	  8    2
	 / \  /
	3  5  2
*/
    struct Node *root = CreateNode(20);
    root->left	 = CreateNode(6);
    root->right	 = CreateNode(5);
    root->left->left = CreateNode(4);
    root->left->right = CreateNode(2);
    root->right->left = CreateNode(1);
    Preorder(root);
    return 0;
}