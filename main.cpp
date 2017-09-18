/*
	Kevin George
	Prof. Xue
	CSE310 - Data Structures & Algorithms
	March 30th, 2017 @ 11:59 PM
	Brief Description: This project will display my understandhing of heaps. A continuously running prompt will request certain input from the user who will enter certain commands in order to manipulate a heap data structure.
*/

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>
#include "main.h"
#include "heap.h"
#include "util.h"


int main()
{
	std::cout << "\e[1muser@totally-not-a-real-shell\e[0m:~$ ";
	std::string userInput;
	std::getline (std::cin, userInput);
	std::string value1 = "0";
	std::string value2 = "0";
	int* newArray = NULL;
	parseInput(userInput, value1, value2);
	int num1 = 0;
	int num2 = 0;
	int size = 0;
	Heap newHeap;
	checkInt(value1, value2, num1, num2);
	//std::cout << num1 << " " << num2 << std::endl;
	
	while(userInput != "S")
	{
		if(userInput == "C" && num1 != 0) //DONE
		{
			newArray = new int [num1];
			newHeap.size = num1;
			newHeap.capacity = num1;
			CreateHeap(newArray, newHeap.size, newHeap.size);
		}
		else if(userInput == "R") //DONE
		{
			std::cout << "reading from file..." << std::endl;
			readFromFileNoLines(newArray, newHeap.size);
		}
		else if(userInput == "W") //DONE
		{
			std::cout << "displaying current heap information" << std::endl;
			PrintHeap(newArray, newHeap.size);
		}
		else if(userInput == "I") //DONE
		{
			std::cout << "Inserting a new element with a key of " << num1 << std::endl;
			InsertKey(newArray, newHeap.size, num1);
		}
		else if(userInput == "D") //DONE
		{
			std::cout << "Deleting the minimum element" << std::endl;
			HeapExtractMin(newArray, newHeap.size);
		}
		else if(userInput == "K" && num1 != 0 && num2 != 0)
		{
			std::cout << "decreasing the key of the element with index " << num1 << " to the new value of " << num2 << std::endl;
			DecreaseKey(newArray, num2, num1);
		}
		else if(num1 == 0 || num2 == 0) //DONE
		{
			std::cout << "a number you have entered is not valid, please try again, and please use an integer value greater than 0" << std::endl;
		}
		else
		{
			std::cout << "That is not valid input, please try again" << std::endl;
		}
		std::cout << "\e[1muser@totally-not-a-real-shell\e[0m:~$ ";
		std::getline (std::cin, userInput);
		parseInput(userInput, value1, value2);
		checkInt(value1, value2, num1, num2);
		//std::cout << num1 << std::endl;
	}
	return 0;
}