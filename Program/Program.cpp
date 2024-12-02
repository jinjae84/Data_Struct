#include <iostream>

#define SIZE 8

using namespace std;

template<typename T>
class Heap
{
private:
	int index;
	T container[SIZE];
public:
	Heap()
	{
		for (int i = 0; i < SIZE; i++)
		{
			container[i] = 0;
		}

		index = 0;
	}

	void Insert(T data)
	{
		if (index + 1 >= SIZE)
		{
			cout << " Heap Overflow" << endl;
		}
		else
		{			
			container[++index] = data;
			
			int child = index;

			int parent = child / 2;

			while (child > 1)
			{
				if (container[parent] < container[child])
				{
					std::swap(container[parent], container[child]);
				}

				child = parent;

				parent = child / 2;
			}
		}		
	}

	T Remove()
	{
		if (index == 0)
		{
			cout << "Heap Underflow" << endl;
		}

		container[1] = container[index--];

		int parent = 1;

		int leftchild = 2 * parent;

		int rightchild = 2 * parent + 1;

		while ()
		{

		}
	}

	void Show()
	{
		for (int i = 1; i <= index; i++)
		{
			cout << container[i] << " ";
		}
	}
};

int main()
{
	Heap<int> heap;

	heap.Insert(5);
	heap.Insert(7);
	heap.Insert(9);
	heap.Insert(15);
	
	heap.Show();
	
	return 0;
}
