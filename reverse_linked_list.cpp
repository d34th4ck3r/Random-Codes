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
node *rev;
node * recurse_reverse(node *tree)
{
	if(tree->next==NULL)
	{
		rev=tree;
		return tree;
	}
	node *temp=recurse_reverse(tree->next);
	temp->next=tree;
	temp->next->next=NULL;
	return tree;
}
node * loop_reverse(node *tree)
{
	node *temp1=tree;
	node *temp2=temp1->next;
	node *temp3=temp2->next;
	temp1->next=NULL;
	while(temp3!=NULL)
	{
		temp2->next=temp1;
		temp1=temp2;
		temp2=temp3;
		temp3=temp3->next;
	}
	temp2->next=temp1;
	return temp2;
}

int main()
{
	node *tree;
	tree=(node *)malloc(sizeof(node));
	tree->value=0;
	tree->next=NULL;
	node *head=tree;
	for(int i=1;i<10;i++)
	{
		node *temp;
		temp=(node *)malloc(sizeof(node));
		temp->value=i;
		temp->next=NULL;
		tree->next=temp;
		tree=tree->next;
	}
	node * te=head;
	while(head!=NULL)
	{
		int p=head->value;
		printf("%d ",p);
		head=head->next;
	}
	NL;
	node *revl=loop_reverse(te);
	while(revl!=NULL)
	{
		int p=revl->value;
		printf("%d ",p);
		revl=revl->next;
	}
	NL;
	return 0;
}
