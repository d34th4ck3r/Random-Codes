/*
ID: gautam11
PROG: milk2
LANG: C++
*/
#include<iostream>
#include<stdio.h>
#include<vector>
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

int compare(const void *a, const void *b)
{
	return ( *(int **)a - *(int **)b);
}

int main()
{
//	freopen ("milk2.in", "r", stdin);
//	freopen ("milk2.out", "w", stdout);
	ofstream fout ("milk2.out");
	ifstream fin ("milk2.in");
	int N;
//	Sint(N);
	fin >> N;
	int Time[N][2];
	for(int i=0;i<N;i++)
	{
		fin>>Time[i][0];
		fin>>Time[i][1];
	}
	qsort(Time,N,sizeof(int *),compare);
	P("Sorted:\n");
	for(int i=0;i<N;i++)
		printf("%d %d \n",Time[i][0],Time[i][1]);
	int maxEnd=Time[0][1],minStart=Time[0][0];
	int tempMaxEnd=maxEnd,tempMinStart=minStart;
	int noMilkingStart=0,noMilkingEnd=0;
	int tempNoMilkingStart=0,tempNoMilkingEnd=0;
	for(int j=0;j<N;j++)
	{
		tempMaxEnd=Time[j][1];
		tempMinStart=Time[j][0];
		tempNoMilkingStart=0,tempNoMilkingEnd=0;
		for(int i=j;i<N;i++)
		{
			if( (tempMinStart <= Time[i][0] && Time[i][0] <= tempMaxEnd) || (tempMinStart <= Time[i][1] && Time[i][1] <= tempMaxEnd ) )
			{
				if( tempMaxEnd <= Time[i][1])
					tempMaxEnd = Time[i][1];
				if( tempMinStart >= Time[i][0])
					tempMinStart = Time[i][0];
			}
			else if( (tempMinStart >= Time[i][0] && Time[i][1] >= tempMaxEnd))
			{
				tempMinStart = Time[i][0];
				tempMaxEnd = Time[i][1];
			}
			else if( (Time[i][0] <= tempMinStart && Time[i][1] <= tempMinStart) )
			{
				if( (tempNoMilkingEnd-tempNoMilkingStart) <= (tempMinStart-Time[i][1]) )
				{
					tempNoMilkingStart = Time[i][1];
					tempNoMilkingEnd = tempMinStart;
					printf("Assigning tempNoMilkingStart = %d , tempNoMilkingEnd = %d ,i = %d ,j = %d\n",tempNoMilkingStart,tempNoMilkingEnd,i,j);
				}
				if(tempMaxEnd-tempMinStart < Time[i][1]-Time[i][0])
				{
					tempMaxEnd = Time[i][1];
					tempMinStart = Time[i][0];
				}
			}
			else if((Time[i][0] >= tempMaxEnd && Time[i][1] >= tempMaxEnd))
			{
/*				if(noMilking > (Time[i][0] - tempMaxEnd) )
					noMilking = Time[i][0] - tempMaxEnd;*/
				if( (tempNoMilkingEnd-tempNoMilkingStart) <= (Time[i][0]-tempMaxEnd) )
				{
					tempNoMilkingStart = tempMaxEnd;
					tempNoMilkingEnd = Time[i][0];
					printf("--Assigning tempNoMilkingStart = %d , tempNoMilkingEnd = %d ,i = %d ,j = %d\n",tempNoMilkingStart,tempNoMilkingEnd,i,j);
				}
				if(tempMaxEnd-tempMinStart <= Time[i][1]-Time[i][0])
				{
					tempMaxEnd = Time[i][1];
					tempMinStart = Time[i][0];
				}

			}
			if( (Time[i][0] <= tempNoMilkingStart && tempNoMilkingStart <= Time[i][1]) && (Time[i][0] <= tempNoMilkingEnd && tempNoMilkingEnd <= Time[i][1]) )
			{
				tempNoMilkingStart=0;
				tempNoMilkingEnd=0;

			}
		}
		if( (tempMaxEnd-tempMinStart) > (maxEnd-minStart) )
		{
			maxEnd=tempMaxEnd;
			minStart=tempMinStart;
		}
		if( (tempNoMilkingEnd-tempNoMilkingStart) >= (noMilkingEnd-noMilkingStart) )
		{
			printf("NoMilkingStart = %d , noMilkingEnd = %d \n", tempNoMilkingStart,tempNoMilkingEnd);
			noMilkingStart=tempNoMilkingStart;
			noMilkingEnd=tempNoMilkingEnd;
		}
	}
/*	if(noMilking == INT_MAX)
		noMilking=0;*/
//	printf("%d %d\n",maxEnd-minStart,noMilkingEnd-noMilkingStart);
	fout<<maxEnd-minStart<<" "<<noMilkingEnd-noMilkingStart<<endl;
	return 0;
}
