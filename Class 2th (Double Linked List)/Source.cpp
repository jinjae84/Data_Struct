#include <iostream>

using namespace std;

template<typename T>
class DoubleLinkedList
{
private:
	struct Node
	{
		T data;
		Node* previous;
		Node* next;
	};

	int size;

	Node* head;
	Node* tail;

public:
	DoubleLinkedList()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	~DoubleLinkedList()
	{
		while (head != nullptr)
		{
			PopFront();
		}
	}
	void PushFront(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;

		if (head != nullptr)
		{
			head->previous = newNode;
			newNode->next = head;

			head = newNode;
		}
		else
		{
			head = newNode;
			tail = newNode;

		}
		size++;
	}

	void PushBack(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;

		if (tail != nullptr)
		{
			tail->next = newNode;
			newNode->previous = tail;

			tail = newNode;
		}
		else
		{
			head = newNode;
			tail = newNode;

		}
		size++;
	}

	void PopFront()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty." << endl;
		}
		else
		{
			Node* deleteNode = head;

			if (head == tail)
			{
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				deleteNode->next->previous = nullptr;

				head = head->next;
			}

			delete deleteNode;

			size--;
		}
	}

	void PopBack()
	{
		if (tail == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node* deleteNode = tail;

			if (tail == head)
			{
				tail = nullptr;
				head = nullptr;
			}
			else
			{
				tail->previous->next = nullptr;

				tail = tail->next;
			}

			delete deleteNode;

			size--;
		}
	}

	int& Size()
	{
		return size;
	}

	void Show()
	{
		Node* currentNode = head;

		while (currentNode != nullptr)
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
		cout << endl;
	}
};

int main()
{
	DoubleLinkedList<int> doubleLinkedList;

	doubleLinkedList.PushFront(10);
	doubleLinkedList.PushFront(20);
	doubleLinkedList.PushBack(30);
	doubleLinkedList.PushBack(40);

	doubleLinkedList.Show();

	cout << "Double Linked List의 크기 : " << doubleLinkedList.Size() << endl;

	doubleLinkedList.PopFront();
	doubleLinkedList.PopFront();
	doubleLinkedList.PopFront();
	doubleLinkedList.PopBack();
	doubleLinkedList.PopBack();

	return 0;
}
