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
using namespace std;

#define P(s) printf("%s\n",s)
#define Pint(n) printf("%d",n)
#define Sint(n) scanf("%d",&n)
#define TEST printf("Test Called!")
#define NL printf("\n")

class Node{
	int value;
	Node *next;
	Node(){} //handling implicit Copy Constructor
	Node(int val): value(val){}
	Node(int val,Node *next): value(val),next(next){}
};

class BinaryTree{
	int value;
	BinaryTree *left;
	BinaryTree *right;
	BinaryTree(){} //handling implicit Copy Constructor
	BinaryTree(int val): value(val){}
	BinaryTree(int val, BinaryTree *left, BinaryTree *right): value(val),left(left), right(right){}
};

void set_to_zero(int **matrix,int M,int N){
	int *row = new int[M];
	int *col = new int[N];
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			if(matrix[i][j] == 0){
				row[i] = 1;
				col[j] = 1;
			}
	for(int i=0;i<M;i++)
		if(row[i] == 1)
			for(int j=0;j<N;j++)
				matrix[i][j] = 0;
	for(int i=0;i<N;i++)
		if(col[i] == 1)
			for(int j=0;j<M;j++)
				matrix[j][i] = 0;
	return;
}

int main()
{
	int M,N;
	cin >> M >>N;
	int **matrix = new int*[M];
	for(int i=0;i<M;i++)
		matrix[i]=new int[N];
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			cin >> matrix[i][j];
	set_to_zero(matrix,M,N);
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	return 0;
}

