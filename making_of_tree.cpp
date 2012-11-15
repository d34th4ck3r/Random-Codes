#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<map>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<limits>
#include<set>
#define P(s) printf("%s",s)
#define Pint(n) printf("%d ",n)
#define Sint(n) scanf("%d",&n)
#define Test printf("Test Called!")
#define nl printf("\n")
//#define FOR(p,l) for(i=p;i<l;i++)

using namespace std;

typedef struct node{
	int value;
	struct node *next;
}node;

typedef struct BinaryTree{
	int value;
	struct BinaryTree *left;
	struct BinaryTree *right;
}BinaryTree;

void print_inorder(BinaryTree *tree)
{
	if(tree==NULL)
		return;
	print_inorder(tree->left);
	Pint(tree->value);
	print_inorder(tree->right);
}

void print_preorder(BinaryTree *tree)
{
	if(tree==NULL)
		return;
	Pint(tree->value);
	print_preorder(tree->left);
	print_preorder(tree->right);
}
void print_postorder(BinaryTree *tree)
{
	if(tree==NULL)
		return;
	print_postorder(tree->left);
	print_postorder(tree->right);
	Pint(tree->value);
}
int getIndexOf(int array[],int start,int end,int val)
{
	for(int i=start;i<end;i++)
	{
		if(array[i]==val)
			return i;
	}
	return -1;
}
BinaryTree* makeBinaryTree(int inorder[],int istart, int iend,int preorder[],int pstart,int pend,int length)
{
	printf("istart = %d , iend = %d , pstart = %d , pend = %d \n",istart,iend,pstart,pend);
	BinaryTree *root;
	root=(BinaryTree *)malloc(sizeof(BinaryTree));
	int indexInorder=-1;
	int indexPreorder=-1;
	int found=0;
	for(int i=pstart;i<pend;i++)
	{
		indexInorder=getIndexOf(inorder,istart,iend,preorder[i]);
		indexPreorder=i;
		if(indexInorder!=-1)
		{
			root->value= inorder[indexInorder];
			printf("Root found %d (at %d ) \n",root->value,indexInorder);
			found=1;
			break;
		}
	}
	if(iend==istart)
		return NULL;
	if(iend-istart<=1)
	{
		printf("Leaf node %d (at %d) \n",root->value,indexInorder);
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	root->left=makeBinaryTree(inorder,istart,indexInorder,preorder,indexPreorder+1,pend,length);
	root->right=makeBinaryTree(inorder,indexInorder+1,iend,preorder,indexPreorder+1,pend,length);
	
	return root;
}

int main()
{
/*	BinaryTree *tree;
	tree= (BinaryTree *)malloc(sizeof(BinaryTree));
	tree->value=2;
	tree->left=NULL;
	tree->right=NULL;*/
	int N;
	Sint(N);
	int inorder[N];
	int preorder[N];
	for(int i=0;i<N;i++)
		Sint(inorder[i]);
	for(int i=0;i<N;i++)
		Sint(preorder[i]);
	BinaryTree *tree;
	tree= makeBinaryTree(inorder,0,N,preorder,0,N,N);
	P("Inorder: \n");
	print_inorder(tree);
	P("Preorder: \n");
	print_preorder(tree);
	P("postorder: \n");
	print_postorder(tree);
	nl;
	return 0;
}
