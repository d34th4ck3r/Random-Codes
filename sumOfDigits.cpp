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

int simpleSumOfDigits(int N)
{
	int s=0;
	while(N)
	{
		s=s+N%10;
		N=N/10;
	}
	return s;
}

int main()
{
	int N;
	Sint(N);
	
	int temp=N;
	while(temp!=temp%10)
	{
		temp=simpleSumOfDigits(temp);
	}
	cout<<temp<<endl;
	return 0;
}

