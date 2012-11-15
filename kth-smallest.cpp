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


int findMedian(int A[],int startA,int endA,int B[],int startB,int endB)
{
	int medianA=(startA+endA)/2;
	int medianB=(startB+endB)/2;
	if((endA-startA<=1 && endB-startB<=1) || A[medianA]==B[medianB])
	{
		printf("startA= %d endA= %d \nstartB= %d endB= %d\nmedianA= %d ,medianB= %d \nA[medianA]= %d, B[medianB]= %d \n",startA,endA,startB,endB,medianA,medianB,A[medianA],B[medianB]);
//		return B[medianB];
//		return A[medianA];
//		return B[medianB];
		if(B[medianB]<A[medianA])
			return B[medianB];
		else
			return A[medianA];
	}
	else if(A[medianA]<B[medianB])
		findMedian(A,medianA+1,endA,B,startB,medianB-1);
	else if(B[medianB]<A[medianA])
		findMedian(A,startA,medianA-1,B,medianB+1,endB);
}

int main()
{
	int N;
	scanf("%d",&N);
	int A[N];
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	int M;
	scanf("%d",&M);
	int B[M];
	for(int i=0;i<M;i++)
		scanf("%d",&B[i]);
	int K;
	scanf("%d",&K);
	if(K>N || K>M)
	{
		printf("Enter K smaller then M & N");
		return 0;
	}
	int kthSmallest=findMedian(A,0,K-1,B,0,K-1);
	printf("Kth Smallest = %d\n",kthSmallest);
	return 0;
}
