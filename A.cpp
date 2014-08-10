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

int findFreq(string S, int hash[]){
	int uni=0;
	for(int i=0;i<S.length();i++)
	{
		if(hash[S[i]-'a']==0)
			uni+=1;
		hash[S[i]-'a']+=1;
	}
	return uni;
}
int findMax(int hash[]){
	int max=INT_MIN;
	int ind=-1;
	for(int i=0;i<26;i++){
		if(max<hash[i]){
			max=hash[i];
			ind=i;
		}
	}
	return ind;
}


int main()
{
	string S;
	cin>>S;
	int Hash[26]={0};
	int uni=findFreq(S,Hash);
//	for(int i=0;i<26;i++)
//	{
//		printf("%d ",Hash[i]);
//	}
//	NL;
//	printf("%d\n", uni);
	for(int i=0;i<uni;i++)
	{
		int c=findMax(Hash);
		printf("%c\n",c+'a');
		Hash[c]=-1;
	}
	return 0;
}
