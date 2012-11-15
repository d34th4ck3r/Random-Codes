#include<iostream>
#include<stdio.h>
#include<stdlib.h>
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
#define P(s) printf("%s",s)
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

void swap(int *a,int *b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}

void merge(int A[],int sizeA,int B[],int sizeB)
{
	int pA=0,pB=0,pC=0;
	int C[sizeA+sizeB];
	while(pC<sizeA+sizeB)
	{
		if(pA<sizeA && pB<sizeB && A[pA]<=B[pB])
		{
			C[pC]=A[pA];
			pA++;
			pC++;
		}
		else if(pA<sizeA && pB<sizeB && A[pA]>B[pB])
		{
			C[pC]=B[pB];
			pC++;
			pB++;
		}
		else if(pA>=sizeA)
		{
			C[pC]=B[pB];
			pB++;
			pC++;
		}
		else if(pB>=sizeB)
		{
			C[pC]=A[pA];
			pC++;
			pA++;
		}
	}
	for(int i=0;i<sizeA;i++)
		A[i]=C[i];
	for(int i=0;i<sizeB;i++)
		B[i]=C[sizeA+i];
}

void mergeSort(int A[],int N)
{
	if(N<2)
		return;
	int mid=N/2;
	mergeSort(A,mid);
	mergeSort(&A[mid],N-mid);
	merge(A,mid,&A[mid],N-mid);
}

int main()
{
	int N;
	Sint(N);
	int A[N];
	for(int i=0;i<N;i++)
		Sint(A[i]);
	mergeSort(A,N);
	for(int i=0;i<N;i++)
	{
		Pint(A[i]);
		P(" ");
	}
	NL;
	return 0;
}

