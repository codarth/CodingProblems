/*
Given the root to a binary tree, implement serialize(root), 
which serializes the tree into a string, and deserialize(s), 
which deserializes the string back into the tree.

For example, given the following Node class

class Node:
	def __init__(self, val, left=None, right=None):
		self.val = val
		self.left = left
		self.right = right
The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
*/

#include <string>
#include <sstream>
#include <iostream>

struct Node
{
	Node(std::string v)
	{
		val = v;
		left = nullptr;
		right = nullptr;
	}

	std::string val;
	Node* left;
	Node* right;
};


std::string Serialize(Node* root)
{
	if (root == NULL) return "X";

	std::ostringstream str;


	str << root->val << " " << Serialize(root->left) << " " << Serialize(root->right);

	return str.str();
}

void SetChildren(Node* root, std::string& inStr)
{
	if (inStr == "") return;

	std::size_t index = inStr.find_first_of(" ");
	std::string str = inStr.substr(0, index);
	inStr.erase(0, index+1);

	std::cout << "str: " << str << " index: " << index << " left: " << inStr << "\n";

	if (str != "X")
	{
		root->left = new Node(str);
		SetChildren(root->left, inStr);
	}
	else
	{
		root->left = nullptr;
	}

	index = inStr.find_first_of(" ");
	str = inStr.substr(0, index);
	inStr.erase(0, index+1);

	std::cout << "str: " << str << " index: " << index << " right: " << inStr << "\n";
	
	if (str != "X") {
		root->right = new Node(str);
		SetChildren(root->right, inStr);
	}
	else
	{
		root->right = nullptr;
	}
}

Node* Deserialize(std::string& inStr)
{
	std::size_t index = inStr.find_first_of(" ");
	std::string str = inStr.substr(0, index);
	inStr.erase(0, index+1);

	std::cout << "root: " << inStr << "\n";

	Node* root = new Node(str);

	SetChildren(root, inStr);

	return root;
}

int main()
{
	Node* root = new Node("1");
	root->left = new Node("2");
	root->right = new Node("3");
	root->left->left = new Node("4");
	root->left->right = new Node("5");
	root->right->left = new Node("6");
	root->right->right = new Node("7");
	root->left->left->left = new Node("8");
	root->right->left->left = new Node("9");
	root->right->left->right = new Node("10");

	std::string str = Serialize(root);

	std::cout << str << "\n";

	Node* newRoot = Deserialize(str);

	std::string newStr = Serialize(newRoot);

	std::cout << newStr << "\n";

	return 0;

}