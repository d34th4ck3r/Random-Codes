/*
ID: gautam11
PROG: crypt1
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
#include<ctype.h>
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

/*void precomputation(bool All[][9][9][9][9])
{
	for(int a=1;a<=9;a++)
		for(int b=1;b<=9;b++)
			for(int c=1;c<=9;c++)
				for(int d=1;d<=9;d++)
					for(int e=1;e<=9;e++)
					{
						int upper=100*a+10*b+1*c;
						int lower=10*d+1*e;
						int partial_product1=upper*e;
						int partial_product2=upper*d;
						int result=upper*lower;

					}
}*/


int numberOfCryptarithm(int A[],int Hash[],int N)
{
	int count=0;
	for(int a=0;a<N;a++)
		for(int b=0;b<N;b++)
			for(int c=0;c<N;c++)
				for(int d=0;d<N;d++)
					for(int e=0;e<N;e++)
					{
						int upper=100*A[a]+10*A[b]+1*A[c];
						int lower=10*A[d]+1*A[e];
						int partial_product1=upper*A[e];
						int partial_product2=upper*A[d];
						int result=upper*lower;
						if( (partial_product1/1000==0 && partial_product1/100!=0) && (partial_product2/1000==0 && partial_product2/100!=0) && (result/10000==0 && result/1000!=0) )
						{
							if(Hash[partial_product1/100]==1 && Hash[(partial_product1/10)%10]==1 && Hash[partial_product1%10]==1 && Hash[partial_product2/100]==1 && Hash[(partial_product2/10)%10]==1 && Hash[partial_product2%10]==1 && Hash[result/1000]==1 && Hash[(result/100)%10]==1 && Hash[(result/10)%10]==1 && Hash[result%10]==1 )
							{
								count++;
//								printf("%d %d %d %d %d\n",A[a],A[b],A[c],A[d],A[e]);
							}
						}
					}
	return count;
}

int main()
{
//	bool All[9][9][9][9][9]={0}
//	precomputation(All);
	freopen ("crypt1.in", "r", stdin);
	freopen ("crypt1.out", "w", stdout);
	int N;
	Sint(N);
	int A[N];
	int Hash[10]={0};
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		Hash[A[i]]+=1;
	}
	printf("%d\n",numberOfCryptarithm(A,Hash,N));
	return 0;
}
