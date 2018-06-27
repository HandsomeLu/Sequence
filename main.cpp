#include<stdio.h>
#include<iostream>
#include<string>
#include<fstream>
#include "Sequence.h"

int main(int argc,char *argv[]){
using namespace std;
string filename="dna.txt";
Sequence obj(filename);
int length=obj.length;
int baseA=obj.numberOf("A");
int baseB=obj.numberOf("B");
string longest=obj.longestConsecutive();
cout<<length<<endl;
cout<<baseA<<endl;
cout<<baseB<<endl;
cout<<longest<<endl;

return 0;
}
