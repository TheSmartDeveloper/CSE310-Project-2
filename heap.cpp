#ifndef HEAP_H_INCLUDED__
#define HEAP_H_INCLUDED__

#include "heap.h"
#include "main.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
void CreateHeap(int* array, int size, int capacity)
{
	std::cout << "Creating an empty heap of size " << size << std::endl;
	Heap newHeap;
	newHeap.size = size;
	newHeap.capacity = capacity;
	array = NULL;
	array = new int [capacity];
	for(int i = 0; i < capacity; i++)
	{
		array[i] = 0;
		std::cout << i << ": " << array[i] << std::endl;
	}
}
int Parent(int i)
{
	return i/2;
}
int Left(int i)
{
	return (2*i)+1;
}
int Right(int i)
{
	return (2*i)+2;
}
void DecreaseKey(int *A, int i, int key)
{
	int temp;
	if(key < A[i])
	{
		std::cout << "the new key is smaller than the current key" << std::endl;
	}
	A[i] = key;
	while(i > 1 && A[Parent(i)] < A[i])
	{
		temp = A[i];
		A[i] = A[Parent(i)];
		A[Parent(i)] = temp;
	}
}
void MinHeapify(int *A, int i, int size)
{
	int left = Left(i);
	int smallest = 0;
	int right = Right(i);
	int heapSize = size;
	int temp = 0;
	//cout << i << " " << A[i] << endl;
	if( left < size && A[left] < A[i])
	{
		smallest = left;
	}
	else
	{
		smallest = i;
	}
	if(right < size && A[right] < A[smallest])
	{
		smallest = right;
	}
	if(smallest != i)
	{
		temp = A[i];
		A[i] = A[smallest];
		A[smallest] = temp;
		MinHeapify(A, smallest, size);
	}
}
void BuildHeap(int *A, int size)
{
	for(int i = (size/2); i >= 0; i--)
	{
		MinHeapify(A, i, size);
	}
}
void InsertKey(int *A, int &size, int val)
{
	size++;
	A[size-1] = val;
}
void HeapExtractMin(int *A,int &size)
{
	int min;
	if(size < 1)
	{
		std::cout << "The heap has no elements" << std::endl;
	}
	else
	{
		min = A[0];
		A[0] = A[size-1];
		size--;
		MinHeapify(A,1,size);
	}
}
void PrintHeap(int* array, int size)
{
	BuildHeap(array, size);
	for(int i = 0; i < size; i++)
	{
		
		std::cout << array[i] << ",";
	}
	std::cout << std::endl;
}
int TrashCollection(int *A)
{
	A = new int;
	delete A;
	A = NULL;
	return *A;
}
#endif