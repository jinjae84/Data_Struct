#include <iostream>

using namespace std;

struct Node
{
	int data;	
	
	Node * left;
	
	Node * right;		
};

Node * CreateNode(int data, Node* left, Node* right)
{
	Node * newNode = new Node();

	newNode->data = data;

	newNode->left = left;
	
	newNode->right = right;
	
	return newNode;
}

void PreOrder(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	else
	{		
		cout << root->data << " ";
		
		PreOrder(root->left);
		
		PreOrder(root->right);
	}
}

void InOrder(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	else
	{
		InOrder(root->left);

		cout << root->data << " ";
				
		InOrder(root->right);
	}
}

void PostOrder(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	else
	{
		PostOrder(root->left);

		PostOrder(root->right);

		cout << root->data << " ";	
	}
}

int main()
{
	Node* node5 = CreateNode(5, nullptr, nullptr);
	Node* node4 = CreateNode(4, nullptr, nullptr);
	Node* node3 = CreateNode(3, nullptr, nullptr);
	Node * node2 = CreateNode(2, node4, node5);	
	Node * node1 = CreateNode(1, node2, node3);
	
	// 전위 순회
	// PreOrder(node1); 	

	// 중위 순회
	// InOrder(node1);
	
	// 후위 순회
	// PostOrder(node1);

	delete node5;
	delete node4;
	delete node3;
	delete node2;
	delete node1;

	return 0;
}
