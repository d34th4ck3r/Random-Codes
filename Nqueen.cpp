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

void print2DArray(bool **array,int N){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			printf("%d ",array[i][j]);
		printf("\n");
	}
}

bool isSafe(bool **board,int N, int y,int x){
	for(int i=0;i<N;i++){
		if( (i!=x && board[i][y]==true) || (i!=y && board[x][i]==true) )
			return false;
		if( (x+i+1)<N && (y+i+1)<N && board[x+i+1][y+i+1]==true)
			return false;
		if( (x-i-1)>=0 && (y-i-1)>=0 && board[x-i-1][y-i-1]==true)
			return false;
		if( (x-i-1)>=0 && (y+i+1)<N && board[x-i-1][y+i+1]==true)
			return false;
		if( (x+i+1)<N && (y-i-1)>=0 && board[x+i+1][y-i-1]==true)
			return false;
	}
	return true;
}

bool putQueen(bool **board,int N,int col){
	if(col==N)
		return true;
	for(int i=0;i<N;i++){
		if(isSafe(board,N,col,i)){
			board[i][col]=true;
			if(putQueen(board,N,col+1))
				return true;
			else
				board[i][col]=false;
		}
	}
	return false;
}

void putNQueen(bool **board,int N){
	if(!putQueen(board,N,0))
		printf("Not Possible\n");
}

int main()
{
	int N;
	scanf("%d",&N);
	bool **board=(bool **)calloc(N,sizeof(bool*));
	for(int i=0;i<N;i++)
		board[i]=(bool *)calloc(N,sizeof(bool));
	putNQueen(board,N);
	print2DArray(board,N);
	return 0;
}

