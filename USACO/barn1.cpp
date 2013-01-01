/*
ID: gautam11
PROG: barn1
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
int Compare(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

/*int function(int Cows[],int C)
{
	int start=Cows[0];
	int end=Cows[C-1];
	min=INT_MAX;
	int last=
	int pre=1;
	while(pre<C)
	{
		if
	}
}*/

int main()
{
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);
	int M,S,C;
	scanf("%d %d %d",&M,&S,&C);
	int Cows[C];
	for(int i=0;i<C;i++)
		Sint(Cows[i]); 
	qsort(Cows,C,sizeof(Cows[0]),Compare);
	int start=Cows[0];
	int end=Cows[C-1];
	int count=end-start+1;
//	printf("Initial count=%d\n",count);
	int diff[C-1];
	for(int i=0;i<C-1;i++)
	{
		diff[i]=Cows[i+1]-Cows[i];
//		printf("%d ",diff[i]);
	}
//	NL;
	qsort(diff,C-1,sizeof(diff[0]),Compare);
	for(int i=0;i<M-1 && i<=C-2;i++)
	{
//		printf("Removing %d\n",diff[C-2-i]);
		count-=diff[C-2-i];
		count++;
	}
	printf("%d\n",count);
	return 0;
}

