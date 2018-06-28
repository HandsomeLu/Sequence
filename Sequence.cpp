#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
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

int Sequence::numberOf(char* base){
	string goal(base);
	int num=0;
	for(int i=0;i<200;i++){
	i=data.find(goal,i+1);
	}
	return num;
}

string Sequence::longestConsecutive(){
	clock_t start_time=clock();
	string longest1,longest2;
	string null;
	int count1=1;
	int count2=1;
	for(int i=0;i<dataLength;i++)
	{
		if(data[i]==data[i+1])
		{
			count2+=count1;
			string add(count1,data[i]);
			longest2=longest2+data[i];
		}
		else 
		{
			longest2=data[i];
			if(count2>count1){
			count1=count2;
			longest1=longest2;
			}
			longest2=null;
			count2=1;
		}
	}
clock_t end_time=clock();
	cout<<"time: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
return longest1;
}

/*string Sequence::longestRepeated(){

	char c[500000], *a[500000];

	int n=0;
	int i,temp;
	int maxlen=0,maxi=0;
	for(i=0;i<dataLength;i++){
	c[i]=data[i];
	a[i]=&c[i];
	}
	c[i]='\0';
	i=0;
	qsort(a,n,sizeof(char*),pstrcmp);
	for(i=0;i<n-1;++i){
		temp=comlen(a[i],a[i+1]);
		if(temp>maxlen){
			maxlen=temp;
			maxi=i;
			}
		}	
 return a[maxi];

}

int comlen(char* p,char* q){
	int i=0;
	while(p&&(p++==q++))i++;
	return i;
}

int pstrcmp(const void *p1,const void *p2){
return strcmp(*(char*const *)p1,*(char* const*)p2);
}
*/
