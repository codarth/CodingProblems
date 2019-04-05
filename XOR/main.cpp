#include <iostream>

class Node
{
public:
	int data;
	Node* both;
};

Node* XOR(Node* a, Node* b)
{
	return (Node*)((unsigned)a ^ (unsigned)b);
}

class XORLL
{
public:
	void add(int element)
	{
		Node* node = new Node;
		node->data = element;
		node->both = XOR(nullptr, nullptr);

		if (head == nullptr)
		{
			head = node;
		}

		curr = head;
		prev = nullptr;
		next = XOR(curr->both, prev);

		while (curr != nullptr)
		{
			prev = curr;
			curr = next;
			next = XOR(curr->both, prev);
		}

		//curr->both = XOR(prev, next);
		node->both = XOR(prev, nullptr);
	}

	Node* get(int index)
	{
		curr = head;
		prev = nullptr;
		next = XOR(curr->both, prev);

		while (index > 0)
		{
			prev = curr;
			curr = next;
			if (curr != nullptr)
				next = XOR(curr->both, prev);

			index--;
		}

		return curr;
	}

	void printList()
	{
		curr = head;
		prev = nullptr;
		next = XOR(curr->both, prev);

		std::cout << "Items in the list: ";

		while (curr != nullptr)
		{
			std::cout << curr->data << " ";

			prev = curr;
			curr = next;
			if (curr != nullptr)
				next = XOR(curr->both, prev);
		}
	}
private:

	Node* head = nullptr;
	Node* curr = nullptr;
	Node* prev = nullptr;
	Node* next = nullptr;

};

int main()
{
	XORLL* list = new XORLL;

	list->add(10);
	list->add(20);

	Node* atIndex = list->get(0);
	std::cout <<"atIndex: " << atIndex->data << std::endl;

	list->printList();

	return 0;
}