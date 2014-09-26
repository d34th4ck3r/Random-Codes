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


int largestSumAtRootFromSide(BinaryTree *tree){
	if(tree->left==NULL && tree->right==NULL)
		return tree->value;
	if(tree->left==NULL)
		return tree->value+largestSumAtRootFromSide(tree->right);
	if(tree->right==NULL)
		return tree->value+largestSumAtRootFromSide(tree->left);
	return tree->value+max(largestSumAtRootFromSide(tree->right),largestSumAtRootFromSide(tree->left));
}
int largestSumAtRoot(BinaryTree *tree){
	if(tree->left==NULL && tree->right==NULL)
		return tree->value;
	if(tree->left==NULL)
		return largestSumAtRootFromSide(tree->right);
	if(tree->right==NULL)
		return largestSumAtRootFromSide(tree->left);
	return largestSumAtRootFromSide(tree->left)+largestSumAtRootFromSide(tree->right)+tree->value;
}
int largestSum(BinaryTree *tree)
{
	if(tree==NULL)
		return INT_MIN;
	return max(largestSumAtRoot(tree),max(largestSum(tree->right),largestSum(tree->left)));
}

int main()
{
	BinaryTree *root;
	root=(BinaryTree *)calloc(1,sizeof(BinaryTree));
	root->value=-10;
	root->left=(BinaryTree *)calloc(1,sizeof(BinaryTree));
	root->right=(BinaryTree *)calloc(1,sizeof(BinaryTree));
	root->left->value=12;
	root->left->left=(BinaryTree *)calloc(1,sizeof(BinaryTree));
	root->left->left->value=8;
	root->left->left->left=NULL;
	root->left->left->right=NULL;
	root->left->right=(BinaryTree *)calloc(1,sizeof(BinaryTree));
	root->left->right->value=4;
	root->left->right->left=NULL;
	root->left->right->right=NULL;
	root->right->value=7;
	root->right->left=NULL;
	root->right->right=NULL;
	cout<<largestSum(root)<<endl;
	return 0;
}
