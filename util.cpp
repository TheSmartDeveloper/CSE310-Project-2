#ifndef UTIL_H_INCLUDED__
#define UTIL_H_INCLUDED__

#include "util.h"
#include "heap.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
void parseInput(std::string &command, std::string &valOne, std::string &valTwo)
{
	std::string fullCommand = command + " ";
	std::transform(fullCommand.begin(), fullCommand.end(), fullCommand.begin(), ::toupper);
	std::string outString;
	int spacePoint = 0;
	int prevPoint = 0;
	int b = 1;
	int num1 = 0;
	int num2 = 0;
	int commandLength = fullCommand.length();
	bool letters = false;
	bool dots = false;
	
	for(int a = prevPoint; a <= commandLength; a++)
	{
		if(fullCommand[a] == ' ')
		{
			spacePoint = a;
			outString = fullCommand.substr(prevPoint, (spacePoint-prevPoint));
			switch(b)
			{
				case 1:
					command = outString;
					//std::cout << "performing case 1" << std::endl;
					b++;
					break;
				case 2:
					valOne = outString.substr(1,outString.length());
					//std::cout << "performing case 2" << std::endl;
					
					b++;
					break;
				case 3:
					valTwo = outString.substr(1,outString.length());
					//std::cout << "performing case 3" << std::endl;
					b++;
					break;
				default:
					std::cout << "something broke" << std::endl;
					break;
			}
			prevPoint = spacePoint;
		}
		//checkInt(valOne, valTwo, num1, num2);
	}
}
void checkInt(std::string firstVal, std::string secondVal, int &inputOne, int &inputTwo)
{
	int pointCheck = 0;
	bool isValid = false;
	bool onPoint = false;
	bool valOneValid = false;
	bool valTwoValid = false;
	int num1 = 0;
	int num2 = 0;
	for(int i = 0; i <= firstVal.length(); i++)
	{
		if((firstVal[i] >= 48 && firstVal[i] <= 56))
		{
			isValid = true;
		}
		if(firstVal[i] == '.')
		{
			onPoint = true;
		}
	}
	if(isValid == true && onPoint == false)
	{
		std::stringstream(firstVal) >> inputOne;
		valOneValid = true;
	}
	else
	{
		//std::cout << "the value is invalid" << std::endl;
		valOneValid = false;
	}
	isValid = false;
	onPoint = false;
	//----------------------------------------------------------------------------------------------
	for(int i = 0; i <= secondVal.length(); i++)
	{
		if((secondVal[i] >= 48 && secondVal[i] <= 56))
		{
			isValid = true;
		}
		if(secondVal[i] == '.')
		{
			onPoint = true;
		}
	}
	if(isValid == true && onPoint == false)
	{
		std::stringstream(secondVal) >> inputTwo;
		valTwoValid = true;
	}
	else
	{
		//std::cout << "the value is invalid" << std::endl;
		valTwoValid = false;
	}
	isValid = false;
	onPoint = false;
}
void readFromFileTakeData(int* A, int size)
{
	std::ifstream Heapfile;
	std::string value;
	int valConvert = 0;
	int i = 0;
	Heapfile.open("HEAPinput.txt");
	if(Heapfile.is_open())
	{
		while(std::getline(Heapfile, value))
		{
			std::stringstream(value) >> valConvert;
			A[i] = valConvert;
			i++;
		}
		Heapfile.close();
	}
	else
	{
		std::cout << "the file was not opened" << std::endl;
	}
}
void readFromFileNoLines(int* A, int size)
{
	std::ifstream Heapfile;
	int count = 0;
	std::string value;
	int valConvert = 0;
	Heapfile.open("HEAPinput.txt");
	if(Heapfile.is_open())
	{
		while(!Heapfile.eof())
		{
			std::getline(Heapfile, value);
			//std::stringstream(value) >> valConvert;
			count++;
			//std::cout << count <<": " << valConvert << std::endl;
		}
		count++;
		int* array = NULL;
		array = new int [count];
		Heapfile.close();
		CreateHeap(array, count, count);
		readFromFileTakeData(A, count);
	}
	else
	{
		std::cout << "the file was not opened" << std::endl;
	}
}
#endif