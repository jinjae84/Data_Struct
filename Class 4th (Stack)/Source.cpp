﻿#include <iostream>

using namespace std;

#define SIZE 10

template<typename T>
class Stack
{
private:

	int top;
	int size;
	T container[SIZE];

public:
	Stack()
	{
		top = -1;
		size = 0;
		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}

	void Push(T data)
	{
		if (top >= SIZE - 1)
		{
			cout << "Stack Overflow" << endl;
		}
		else
		{
			container[++top] = data;
		}
	}

	void Pop()
	{
		if (Empty())
		{
			cout << "Stack is Empty" << endl;
		}
		else
		{
			top--;
		}
	}

	bool Empty()
	{
		if (top <= -1)
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
		size = top + 1;

		return size;
	}

	T& TOP()
	{
		return container[top];
	}
};

int main()
{
	Stack<int> stack;
	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	stack.Push(40);
	stack.Push(50);

	cout << "stack의 크기 : " << stack.Size() << endl;
	// cout << stack.TOP() << endl;

	while (stack.Empty() == false)
	{
		cout << stack.TOP() << endl;

		stack.Pop();
	}



	return 0;
}
