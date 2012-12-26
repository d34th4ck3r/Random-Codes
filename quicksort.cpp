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
	*a=*a+*b-(*b=*a);
}
	

void QuickSort(int A[],int N)
{
	if(N<=1)
		return;
	int pivot=N-1;
	int left=0;
	int right=pivot-1;
	while(left<=right)
	{
		while(A[left]<A[pivot] && left<=right)
			left++;
		while(A[right]>A[pivot] && right>=left)
			right--;
		if(left<right)
			swap(&A[left],&A[right]);
	}
	swap(&A[left],&A[pivot]);
	QuickSort(&A[0],left);
	QuickSort(&A[left],N-left);
}

int main()
{
	int N;
	Sint(N);
	int A[N];
	for(int i=0;i<N;i++)
		Sint(A[i]);
	QuickSort(A,N);
	for(int i=0;i<N;i++)
		printf("%d ",A[i]);
	NL;
	return 0;
}

