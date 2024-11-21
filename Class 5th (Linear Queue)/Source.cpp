#include <iostream>

using namespace std;

#define SIZE 5

template<typename T>
class LinearQueue
{
private:
	int front;
	int rear;
	int size;
	T container[SIZE];
public:
	LinearQueue()
	{
		front = 0;
		rear = 0;
		size = 0;
		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}
	void Push(T data)
	{
		if (rear >= SIZE)
		{
			cout << "Linear Queue Overflow" << endl;
		}
		else
		{
			container[rear++] = data;

			size++;
		}
	}

	void Pop()
	{
		if (Empty())
		{
			cout << "Linear Queue is Empty" << endl;
		}
		else
		{
			container[front++] = NULL;

			size--;
		}

	}

	bool Empty()
	{
		if (front == rear)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int& Size()
	{
		return size;
	}

	T& Front()
	{
		if (Empty())
		{
			cout << "No Data Exists" << endl;

			exit(1);
		}
		return container[front];
	}
	T& Back()
	{
		if (Empty())
		{
			cout << "Linear Queue is Empty" << endl;
			exit(1);
		}
		return container[rear-1];
	}
};

int main()
{
	LinearQueue<int> linearQueue;

	linearQueue.Push(10);
	linearQueue.Push(20);
	linearQueue.Push(30);
	linearQueue.Push(40);
	linearQueue.Push(50);

	while (linearQueue.Empty() == false)
	{
		cout << linearQueue.Front() << endl;

		linearQueue.Pop();
	}

	linearQueue.Push(10);
	// cout << "Queue 의 크기 : " << linearQueue.Size() << endl;
	// 
	// cout << "Front Queue : " << linearQueue.Front() << endl;
	// cout << "Back Queue : " << linearQueue.Back() << endl;



	return 0;
}
