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
			front++;
			size--;
		}

	}

	bool Empty
	{
		if (rear <= 0)
		{
			return true;
		}
		else
		{
			return false;
		}		
	}
};

int main()
{
	LinearQueue<int> linearQueue;
	
	linearQueue.Push(10);
	linearQueue.Push(20);
	linearQueue.Pop();
	linearQueue.Pop();
	linearQueue.Pop();
	return 0;
}
