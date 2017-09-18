#ifndef HEAP_H_INCLUDED__
#define HEAP_H_INCLUDED__

void CreateHeap(int* array, int size, int capacity);
void PrintHeap(int* array, int size);
int Parent(int i);
int Left(int i);
int Right(int i);
void MinHeapify(int *A, int i, int size);
void BuildHeap (int *A, int size);
void InsertKey(int *A, int &size, int val);
void HeapExtractMin(int *A, int &size);
void DecreaseKey(int *A, int i, int key);
int TrashCollection(int *A);
#endif