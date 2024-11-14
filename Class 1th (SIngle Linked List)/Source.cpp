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

	~SingleLinkedList()
	{
		while (head != nullptr)
		{
			Popback();
		}
	}

	void Pushfront(T data)
	{


		if (head == nullptr)
		{
			head = new Node;

			head->data = data;
			head->next = nullptr;
		}
		else
		{
			Node* newNode = new Node;

			newNode->data = data;
			newNode->next = head;

			head = newNode;
		}

		size++;
	}

	void Popfront()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node* deleteNode = head;

			head = deleteNode->next;

			delete deleteNode;

			size--;
		}
	}

	void Pushback(T data)
	{
		if (head == nullptr)
		{
			head = new Node;

			head->data = data;
			head->next = nullptr;
		}
		else
		{
			Node* currentNode = head;
			while (currentNode->next != nullptr)
			{
				currentNode = currentNode->next;
			}

			Node* newNode = new Node;

			currentNode->next = newNode;

			newNode->data = data;
			newNode->next = nullptr;
		}
		size++;
	}

	void Popback()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node* deleteNode = head;

			Node* PreviousNode = nullptr;

			if (size == 1)
			{
				head = nullptr;

				delete head;
			}
			else
			{

				while (deleteNode->next != nullptr)
				{
					PreviousNode = deleteNode;

					deleteNode = deleteNode->next;
				}

				PreviousNode->next = deleteNode->next;

				delete deleteNode;
			}

			size--;
		}

	}

	void Show()
	{
		Node* currentNode = head;
		while (currentNode != nullptr)
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}

	}
};



int main()
{
	SingleLinkedList<int> singleLinkedList;

	singleLinkedList.Pushfront(10);
	singleLinkedList.Pushfront(20);

	singleLinkedList.Pushback(5);
	singleLinkedList.Pushback(0);

	singleLinkedList.Show();

	singleLinkedList.Popback();
	cout << endl;
	singleLinkedList.Show();

	singleLinkedList.Popback();
	cout << endl;
	singleLinkedList.Show();

	singleLinkedList.Popfront();
	singleLinkedList.Popfront();

	return 0;
}
