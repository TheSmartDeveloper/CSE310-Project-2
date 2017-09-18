#ifndef MAIN_H_INCLUDED__
#define MAIN_H_INCLUDED__
struct Element
{
	int key;
	
	Element()
	{
		key = 0;
	}
};
struct Heap
{
	int size;
	int capacity;
	Element H;
	
	Heap()
	{
		size = 0;
		capacity = 0;
		H.key = 0;
	}
};

#endif
