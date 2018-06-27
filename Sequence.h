#ifndef SEQUENCE_H
#define SEQUENCE_H

#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

class Sequence{

public:
	Sequence(string);
	int length();
	int numberOf(char);
	string longestConsecutive();
	string longestRepeated();

private:
	string filename;
	string data;
	int datalength=0;
	int baseA, baseT, baseC, baseG;
};

#endif
