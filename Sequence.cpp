#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<algorithm>
#include "Sequence.h"

using namespace std;

Sequence::Sequence(string filename){
	filename=filename;
	ifstream inFile("filename",ios::in);
	if(!inFile)
	{
		cerr<<"file could not be opened"<<endl;
		return -1;
	}
	string add;
	while(inFile>>add)
	{
		data+=add;
	}
}

int Sequence::length(){
	dataLength=data.length();
	return dataLength;
}

int Sequence::numberOf(char* base){
	string goal(base);
	int num=count(data.begin(),data.end(),goal);
	return num;
}

string Sequence::longestConsecutive(){
	string longest1,longest2;
	for(int i=0;i<(length-1);i++)
	{
		int count1=0,count2=0;
		int longest=data[i];
		if(data[i]==data[i+1])
		{
			count2++;
			longset2=longest2+data[i+1];
		}
		else 
		{
			if(count2>count1){
			count1=count2;
			count2=0;
			longest1=longest2;
			longest2="";
			continue;
			}
			else if(count2<=count1){
			count2=0;
			longest2="";
			continue;
			}
		}
	}
return longest;
}

string Sequence::longestRepeated(){}
