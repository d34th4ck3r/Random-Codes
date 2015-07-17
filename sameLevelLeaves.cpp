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

struct BinaryTree* newBinaryTree(int value){
	BinaryTree *root=(BinaryTree*) calloc(1,sizeof(BinaryTree));
	root->value=value;
	root->left=root->right=NULL;
	return root;
}

using namespace std;


int sameLeavesLevel(BinaryTree *root){
	if(root==NULL)
		return 0;
	int left=-1,right=-1;
	if(root->left!=NULL)
		left=sameLeavesLevel(root->left);
	if(root->right!=NULL)
		right=sameLeavesLevel(root->right);
	if(left==-2 || right==-2)
		return -2;
	if( (left!=-1 && right!=-1) && left!=right)
		return -2;
	else{
		if(left==-1)
			return 1+right;
		return 1+left;
	}
}

int main()
{
	BinaryTree *root = newBinaryTree(12);
	root->left = newBinaryTree(5);
	root->left->left = newBinaryTree(3);
	root->left->right = newBinaryTree(9);
	root->right=newBinaryTree(4);
	root->left->left->left = newBinaryTree(1);
	root->left->right->left = newBinaryTree(1);
	if(sameLeavesLevel(root)!=-2)
		printf("Leaves are at same level");
	else
		printf("Leavs are not at the same level!!");
	return 0;
}
