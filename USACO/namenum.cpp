/*
ID: gautam11
PROG: namenum
LANG: C++
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<sstream>
#include<string>
#include<map>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<limits.h>
#include<set>
#include<stack>
#include<queue>
#define P(s) printf("%s\n",s)
#define Pint(n) printf("%d",n)
#define Sint(n) scanf("%d",&n)
#define TEST printf("Test Called!")
#define NL printf("\n")
typedef struct node{
	int value;
	struct node *next;
}node;

typedef struct BinaryTree{
	int value;
	struct BinaryTree *left;
	struct BinaryTree *right;
}BinaryTree;

using namespace std;

string getChars(char num)
{
	switch(num)
	{
		case '2': return "ABC";
		case '3': return "DEF";
		case '4': return "GHI";
		case '5': return "JKL";
		case '6': return "MNO";
		case '7': return "PRS";
		case '8': return "TUV";
		case '9': return "WXY";
	}
}

/*bool LinearSearch(string S)
{
	ifstream fin ("dict.txt");
	string temp;
	for(int i=0;!fin.eof();i++)
	{
		fin>>temp;
		if(!S.compare(temp))
			return 1;
	}
	return 0;
}*/

bool match(string N,string test)
{
	string chars;
	for(int i=0;i<N.length();i++)
	{
		chars=getChars(N[i]);
		if(test[i]!=chars[0] && test[i]!=chars[1] && test[i]!=chars[2])
			return 0;
	}
	return 1;
}

int main()
{
	ofstream fout("namenum.out");
	ifstream fin("namenum.in"),fdict("dict.txt");
	string N;
	fin>>N;
	string test;
	bool flag=0;
	for(int i=0;!fdict.eof();i++)
	{
		fdict>>test;
		if(test.length()==N.length() && match(N,test))
		{
			flag=1;
			fout<<test<<endl;
		}
	}
	if(!flag)
		fout<<"NONE"<<endl;
	return 0;
}

