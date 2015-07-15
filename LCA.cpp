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

int LCA(int node1,int node2,BinaryTree* tree){
//	TEST;
	if(tree==NULL)
		return -1;
	else if(tree->value==node1)
		return node1;
	else if(tree->value==node2)
		return node2;
	int val1=LCA(node1,node2,tree->left);
	int val2=LCA(node1,node2,tree->right);
	if(val1==-1 && val2==-1){
		return -1;
	}
	else if(val1!=-1 && val2==-1)
		return val1;
	else if(val2!=-1 && val1==-1)
		return val2;
	else
		return tree->value;
}

int main()
{
//	int N;
//	scanf("%d",&N);
	BinaryTree *root;
	root=(BinaryTree*)calloc(1,sizeof(BinaryTree));
	root->value=2;
	root->left=(BinaryTree*)calloc(1,sizeof(BinaryTree));
	root->left->value=3;
	root->left->left=NULL;
	root->left->right=NULL;
	root->right=(BinaryTree*)calloc(1,sizeof(BinaryTree));
	root->right->value=4;
	root->right->right=(BinaryTree*)calloc(1,sizeof(BinaryTree));
	root->right->right->value=6;
	root->right->left=(BinaryTree*)calloc(1,sizeof(BinaryTree));
	root->right->left->value=5;
	root->right->left->right=NULL;
	root->right->left->left=NULL;
	root->right->right->right=NULL;
	root->right->right->left=NULL;
	printf("%d\n",LCA(5,6,root));
	return 0;
}

