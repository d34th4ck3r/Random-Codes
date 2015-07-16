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

int LIS(int A[],int N){
	int Q[N];
	for(int i=0;i<N;i++)
		Q[i]=1;
	int max=0;
	int ans=1;
	for(int i=1;i<N;i++){
		max=0;
		for(int j=0;j<i;j++)
			if(Q[j]>max && A[i]>A[j]){
				max=Q[j];
			}
		Q[i]=max+1;
		if(Q[i]>ans)
			ans=Q[i];
	}
	return ans;
}

int main()
{
	int N;
	scanf("%d",&N);
	int A[N];
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	printf("%d\n",LIS(A,N));
	return 0;
}

