#include<stdio.h>
#include<iostream>
#include<string>
#include<fstream>
#include "Sequence.h"

int main(int argc,char *argv[]){
using namespace std;
string filename=("dna.txt");
Sequence obj(filename);
int length=obj.length();
int baseA=obj.numberOf('A');
int baseT=obj.numberOf('T');
int baseC=obj.numberOf('C');
int baseG=obj.numberOf('G');
string repeated=obj.longestRepeated();
string longest=obj.longestConsecutive();
cout<<length<<endl;
cout<<baseA<<endl;
cout<<baseT<<endl<<baseC<<endl<<baseG<<endl;
cout<<longest<<endl;
cout<<repeated<<endl;

return 0;
}
