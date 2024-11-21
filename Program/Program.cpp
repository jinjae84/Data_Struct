#include <iostream>

using namespace std;

#define SIZE 6

template <typename T>
class CircleQueue
{
private:
	int front;
	int rear;
	int size;
	T container[SIZE];
public:
	CircleQueue()
	{
		front = SIZE - 1;
		rear = SIZE - 1;
		size = 0;
		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}

	void Push(T data)
	{
		if (front == (rear +1) % SIZE)	
		{
			cout << "Circle Queue Overflow" << endl;
		}
		else
		{
			rear = (rear + 1) % SIZE;
		 	container[rear] = data;
			size++;
		}
	}

	void Pop()
	{
		if (Empty())
		{
			cout << "Circle Queue is Empty" << endl;
		}
		else
		{			
			front = (front + 1) % SIZE;
			container[front] = NULL;
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
		return container[(front + 1) % SIZE];
	}
};

int main()
{
	CircleQueue<char> circleQueue;
	
	circleQueue.Push('A');
	circleQueue.Push('B');
	circleQueue.Push('C');
	circleQueue.Push('D');
	
	while (circleQueue.Empty() == false)
	{
		cout << circleQueue.Front() << endl;

		circleQueue.Pop();
	}
	
	circleQueue.Push('E');
	circleQueue.Push('F');
	circleQueue.Push('G');
	circleQueue.Push('H');

	
	return 0;
}
