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

int DFS(int** conn,int N,int A,int B,int cur,int visited[])
{
	if(curr==B)
		return conn[cur][B];
	int ans=0;
	visited[A]=1;
	for(int i=0;i<N;i++)
		if(visited[i]!=1)
			ans+=DFS(conn,N,A,B,i,visited);
	return DFS(
}

using namespace std;
int main()
{
	int N,Q;
	scanf("%d %d",&N,&Q);
	int** conn=(int **)calloc(N,sizeof(int*));
	for(int i=0;i<=N;i++)
		conn[i]=(int*)calloc(N,sizeof(int));
	for(int i=0;i<Q;i++)
	{
		string s;
		int a,b,time;
		cin>>s>>a>>b>>time;
//		cout<<s<<a<<b<<endl;
		if(s.compare("make")==0)
			conn[a][b]=time;
		else

	}
	return 0;
}

