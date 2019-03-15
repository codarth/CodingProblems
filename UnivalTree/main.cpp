/*
A unival tree (which stands for "universal value") is a tree 
where all nodes under it have the same value.

Given the root to a binary tree, count the number of 
unival subtrees.

For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
	/ \
   1   0
  / \
 1   1

*/

#include <iostream>

struct Node {
	Node(int v) { val = v; }
	int val;
	Node* left = nullptr;
	Node* right = nullptr;
};

int FindUnivalTrees(Node* node)
{
	// no child to leaf node
	if (node == nullptr)
	{
		return 1;
	}

	int count = 0;

	//Leaf Node is a UnivalTree
	if (node->left == nullptr && node->right == nullptr)
	{
		count++;
	}
	else if (node->val == node->left->val 
		&& node->val == node->right->val)
	{
		count++;
	}
	
	
	if (node->left != nullptr)
	{
		count += FindUnivalTrees(node->left);
	}
	if (node->right != nullptr)
	{
		count += FindUnivalTrees(node->right);
	}

	return count;
}

int main()
{
	Node* node = new Node(0);
	node->left = new Node(1);
	node->right = new Node(0);
	node->right->left = new Node(1);
	node->right->right = new Node(0);
	node->right->left->left = new Node(1);
	node->right->left->right = new Node(1);
	std::cout << FindUnivalTrees(node) << std::endl; // 5

	Node* nnull = nullptr;
	std::cout << FindUnivalTrees(nnull) << std::endl; // 1

	Node* n2 = new Node(0);
	std::cout << FindUnivalTrees(n2) << std::endl; // 1

	Node* n3 = new Node(0);
	n3->left = new Node(1);
	n3->right = new Node(0);
	std::cout << FindUnivalTrees(n3) << std::endl; // 2


	return 0;
}