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

void rotate_matrix_by_90(int **matrix,int X, int Y,int N){
	if((N-Y) < 2)
		return;
	for(int j=0;(Y+j)<N-Y-1;j++){
		int temp = matrix[X][Y+j];
		matrix[X][Y+j] = matrix[N-1-Y-j][X]; 
		matrix[N-1-Y-j][X] = matrix[N-1-X][N-1-Y-j]; 
		matrix[N-1-X][N-1-Y-j] = matrix[Y+j][N-1-X]; 
		matrix[Y+j][N-1-X] = temp; 
	}
	rotate_matrix_by_90(matrix,X+1,Y+1,N);
}

int main()
{
	int N;
	cin >>N;
	int **matrix = new int*[N];
	for(int i=0;i<N;i++)
		matrix[i] = new int[N];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> matrix[i][j];
	rotate_matrix_by_90(matrix,0,0,N);
	cout << endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout << matrix[i][j] <<" ";
		cout << endl;
	}
	return 0;
}

