#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<cmath>
#include<algorithm>
#include "Sequence.h"
#include<time.h>

using namespace std;

Sequence::Sequence(string file){
	filename=file;
	int len=filename.length();
	char name[len+1];
	int i=0;
	filename.copy(name,len,0);
	*(name+len)='\0';
//	cout<<filename<<" "<<name<<endl;
	fstream inFile(name,ios::in);
	if(!inFile)
	{
		cerr<<"file could not be opened"<<endl;
	}
	string add;
	while(inFile>>add)
	{
		data+=add;
	}
	dataLength=data.length();
}

int Sequence::length(){
	dataLength=data.length();
	return dataLength;
}

int Sequence::numberOf(char base){
	char* a=&base;
	string goal(a);
	int num=0;
//	cout<<base<<" "<<goal<<endl;
	for(int i=0;i<dataLength;i++){
		if(data[i]==goal[0]){
			 num++;
		}
	}
	//cout<<num<<endl;
	return num;
}

string Sequence::longestConsecutive(){
	clock_t start_time=clock();
	string longest1,longest2;
	string null;
	int count1=0;
	int count2=0;
	for(int i=0;i<dataLength;i++)
	{
		if(data[i]==data[i+1])
		{
			count2++;
			longest2=longest2+data[i];
		}
		else 
		{
			longest2+=data[i];
			if(count2>count1){
			count1=count2;
			longest1=longest2;
			}
			longest2=null;
			count2=0;
		}
	}
clock_t end_time=clock();
//	cout<<"time: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
//	cout<<count1<<endl;
return longest1;
}

string Sequence::longestRepeated(){
	char* a=new char[12000000];
//	cout<<"2"<<endl;
	char** ab=new char*[12000000];
	int i=0;
	a=(char*)data.c_str();
	for(i=0;i<dataLength;i++){
		ab[i]=&a[i];
	}
	int n=0;
	int temp;
	int maxlen=0;
	int maxi=0;
//	cout<<c<<endl;
	qsort(ab,i,sizeof(char*),pstrcmp);
//	for(int i=0;i<n-1;i++) cout<<ab[i]<<endl;
	for(int n=0;n<i-1;n++){
		temp=comlen(ab[n],ab[n+1]);
		//cout<<ab[n]<<" ";
		if(temp>maxlen){
			maxlen=temp;
			maxi=n;
		//	cout<<maxlen<<endl<<a[maxi]<<endl;
			}
		}
//	cout<<"4"<<endl;	
	string repeated=ab[maxi];
//	cout<<a[maxi]<<endl;
	return repeated.substr(0,maxlen);
	delete []a;
	delete []ab;
}
int Sequence::comlen(char* p,char* q){
	int i=0;
	while(*p&&(*p++==*q++))i++;
//	cout<<i<<endl;
	return i;
}

int Sequence::pstrcmp(const void *p1,const void *p2){
return strcmp(*(char*const *)p1,*(char* const*)p2);
}

