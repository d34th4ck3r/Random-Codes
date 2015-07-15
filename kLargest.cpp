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

void Swap(int *a,int *b){
	*a=(*a+*b)-(*b=*a);
}

int getParentIndex(int index){
	return index/2;
}

int getLeftChildIndex(int index){
	return 2*index+1;
}

int getRightChildIndex(int index){
	return 2*index+2;
}

void heapify(int Heap[], int size,int index){
//	for(int i=getParentIndex(size-1);i>=0;i--){
		int max=i;
		if(getLeftChildIndex(i)<size && Heap[max]<Heap[getLeftChildIndex(i)]){
			max=getLeftChildIndex(i);
		}
		if(getRightChildIndex(i)<size && Heap[max]<Heap[getRightChildIndex(i)]){
			max=getRightChildIndex(i);
		}
		if(max!=i){
			Swap(*Heap[max],*Heap[i]);
			heapify(Heap,size,max);
		}
//	}
}

int main()
{
	int N;
	scanf("%d",&N);
	int A[N];
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	int K;
	scanf("%d",&K);
	int Heap[K];
	return 0;
}

