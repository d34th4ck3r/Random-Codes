/*
ID: gautam11
PROG: palsquare
LANG: C++
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>
#include<sstream>
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

bool isPalindrome(string N)
{
	int left=0;
	int right=N.size()-1;
	while(left<=right && N[left]==N[right])
	{
		left++;
		right--;
	}
	if(left>=right)
		return 1;
	else
		return 0;
}
string intTostring(int N)
{
	ostringstream out;
	out<<N;
	return out.str();
}
string convertBase(int N,int B,char Val[])
{
	int temp=N;
	string sN="";
	while(temp)
	{
		int remainder=temp%B;
		sN=Val[remainder]+sN;
		temp=temp/B;
	}
	return sN;
}
int main()
{
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	char Val[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
	int B;
	fin>>B;
	for(int i=1;i<=300;i++)
	{
		string CBS=convertBase(i*i,B,Val);
		string CB=convertBase(i,B,Val);
		if(isPalindrome(CBS))
		{
			fout<<CB<<" "<<CBS<<endl;
		}
	}
	return 0;
}

