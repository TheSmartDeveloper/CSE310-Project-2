#ifndef UTIL_H_INCLUDED__
#define UTIL_H_INCLUDED__

void parseInput(std::string &command, std::string &valOne, std::string &valTwo);
void checkInt(std::string firstVal, std::string secondVal, int &inputOne, int &inputTwo);
void readFromFileTakeData(int* A, int size);
void readFromFileNoLines(int* A, int size);
#endif