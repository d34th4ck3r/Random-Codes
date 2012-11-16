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

int heightOfBST(BinaryTree *tree)
{
	int heightleft=0,heightright=0;
	if(tree->left==NULL && tree->right==NULL)
		return 1;
	if(tree->left)
		heightleft=1+heightOfBST(tree->left);
	if(tree->right)
		heightright=1+heightOfBST(tree->right);
	if(heightleft>heightright)
		return heightleft;
	else 
		return heightright;
}


int main()
{
	BinaryTree *tree;
	tree=(BinaryTree *)malloc(sizeof(BinaryTree));
	tree->value=3;
	tree->left=(BinaryTree *)malloc(sizeof(BinaryTree));
	tree->left->value=12;
	tree->left->right=NULL;
//	tree->left->left=NULL;
	tree->left->left=(BinaryTree *)malloc(sizeof(BinaryTree));
	tree->left->left->value=12;
	tree->left->left->right=NULL;
	tree->left->left->left=NULL;
	//tree->right=NULL;
	tree->right=(BinaryTree *)malloc(sizeof(BinaryTree));
	tree->right->value=12;
	tree->right->right=NULL;
//	tree->right->left=NULL;
	tree->right->left=(BinaryTree *)malloc(sizeof(BinaryTree));
	tree->right->left->value=12;
	tree->right->left->right=NULL;
	tree->right->left->left=NULL;
	int h=heightOfBST(tree);
	cout<<h<<endl;
	return 0;
}

