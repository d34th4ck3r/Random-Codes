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
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int getParent(int N)
{
	if(N)
		return N/2;
	return -1;
}

int getLeftChild(int N,int size)
{
	int r=2*N+1;
	if(r<size)
		return r;
	return -1;
}

int getRightChild(int N,int size)
{
	int r=2*N+2;
	if(r<size)
		return r;
	return -1;
}

void heapify(int A[],int N,int i)
{
	int l=getLeftChild(i,N);
	int r=getRightChild(i,N);
	int max=i;
	if(A[l]>A[max])
		max=l;
	if(A[r]>A[max])
		max=r;
	if(max!=i)
	{
		swap(&A[max],&A[i]);
		heapify(A,N,max);
	}

}

void heapifyArray(int A[],int N)
{
	int c;
	c=getParent(N-1);
	for(int i=getParent(N-1);i>=0;i--)
	{
		heapify(A,N,i);
	}
}

int main()
{
	int N;
	Sint(N);
	int A[N];
	for(int i=0;i<N;i++)
		Sint(A[i]);
	heapify(A,N);
	for(int i=0;i<N;i++)
		printf("%d ",A[i]);
	NL;
	return 0;
}

