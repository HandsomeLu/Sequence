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
	int comlen(char*,char*);
	static int pstrcmp(const void *,const void *);

private:
	string filename;
	string data;
	int dataLength;
	int baseA, baseT, baseC, baseG;
};

#endif
