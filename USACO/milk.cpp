/*
ID: gautam11
PROG: milk
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

int compare(const void *a, const void *b)
{
	return *(int *)a-*(int *)b;
}
void swap(int *a,int *b)
{
	*a=*a+*b-(*b=*a);
}


void QuickSort(int A[][2],int N)
{
	if(N<=1)
		return;
	int pivot=N-1;
	int left=0;
	int right=pivot-1;
	while(left<=right)
	{
		while(A[left][0]<=A[pivot][0] && left<=right)
			left++;
		while(A[right][0]>A[pivot][0] && right>=left)
			right--;
		if(left<right)
		{
			swap(&A[left][0],&A[right][0]);
			swap(&A[left][1],&A[right][1]);
		}
	}
	swap(&A[left][0],&A[pivot][0]);
	swap(&A[left][1],&A[pivot][1]);
	QuickSort(&A[0],left);
	QuickSort(&A[left],N-left);
}


int main()
{
	freopen ("milk.in", "r", stdin);
	freopen ("milk.out", "w", stdout);

	int N=0,M=0;
	scanf("%d %d",&N,&M);
	int milk[M][2];
	for(int i=0;i<M;i++)
		scanf("%d %d",&milk[i][0],&milk[i][1]);

	QuickSort(milk,M);
//	sort(milk,milk+M,compare);

//	for(int i=0;i<M;i++)
//		printf("%d %d\n",milk[i][0],milk[i][1]);
	int i=0;
	int toGet=N;
	int cost=0;
	while(i<M)
	{
		if(toGet-milk[i][1]>0)
		{
			toGet-=milk[i][1];
			cost+=milk[i][0]*milk[i][1];
		}
		else
		{
			cost+=milk[i][0]*toGet;
			break;
		}
		i++;
	}
	printf("%d\n",cost);
	return 0;
}

