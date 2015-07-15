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
long long int random(int A,int B,int X,int K,int M,int n,int DP[]){
	if(n==1){
		DP[n]=X;
		return X;
	}
	long long int ans=((A*random(A,B,X,K,M,n-1,DP))%M+B%M)%M;
	DP[n]=ans;
	return ans;
}

int main()
{
	long long int A,B,X1,K,M;
//	scanf("%ld %ld %ld %ld %ld",A,B,X1,K,M);
	cin>>A>>B>>X1>>K>>M;
	int DP[M+1];
	for(int i=0;i<M+1;i++)
		DP[i]=0;
	random(A,B,X1,K,M,K+4,DP);
//	for(int i=1;i<M+1;i++)
//		cout<<DP[i]<<endl;
//	int r=K%M;
//	cout<<"asasd "<<r<<endl;
	for(int i=K;i<=K+4;i++)
	{
		if(i>M)
			cout<<DP[i-M]<<endl;
		else
			cout<<DP[i]<<endl;
	}
	return 0;
}

