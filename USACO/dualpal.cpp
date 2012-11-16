/*
ID: gautam11
PROG: dualpal
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
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	char Val[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
	int N,S;
	fin>>N>>S;
	int countN=0;
	int i=S+1;
	while(countN<N && i<INT_MAX)
	{
		int countB=0;
		int j=2;
		while(countB<2 && j<=10)
		{
			if(isPalindrome(convertBase(i,j,Val)))
				countB++;
			j++;
		}
		if(countB>=2)
		{
			fout<<i<<endl;
			countN++;
		}
		i++;
	}
	return 0;
}

