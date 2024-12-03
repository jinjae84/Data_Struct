﻿#include <iostream>

#define SIZE 10

using namespace std;

template<typename T>
class AdjacencyMatrix
{
private:	
	int numVertex;             // 정접의 개수
	T vertex[SIZE];            // 정점의 집합
	int matrix[SIZE][SIZE];    // 인접 행렬

public:
	AdjacencyMatrix()
	{
		size = 0;

		for (int i = 0; i < SIZE; i++)
		{
			vertex[i] = NULL;

			for (int j = 0; j < SIZE; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}
};

int main()
{
	AdjacencyMatrix<int> adjacencyMatrix;

	return 0;
}
