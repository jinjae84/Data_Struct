#include <iostream>

using namespace std;

template<typename T>
class SingleLinkedList
{	
private:
	struct  Node
	{
		T data;
		Node* next;
	};
	
	int size;
	
	Node* head;

public:
	SingleLinkedList()
	{
		size = 0;
		head = nullptr;
	}
	
	void push_front(T data)
	{


		if (head == nullptr)
		{
			head = new Node;

			head->data = data;
			head->next = nullptr;
		}
		else
		{
			Node * newNode = new Node;

			newNode->data = data;
			newNode->next = head;

			head = newNode;
		}

		size++;
	}
};



int main()
{
	SingleLinkedList<int> singleLinkedList;

	singleLinkedList.push_front(10);
	singleLinkedList.push_front(20);  //  [20] <------ [10]
    
}
