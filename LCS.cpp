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

int LCS[1024][1024];

int LCS_recurse(string s1,int l1,string s2,int l2)
{
//	cout<<"Called : LCS("<<s1<<","<<l1<<","<<s2<<","<<l2<<")"<<endl;
	if(l1==s1.size() || l2==s2.size())
		return 0;
	if(s1[l1]==s2[l2])
		return 1 + LCS_recurse(s1,l1+1,s2,l2+1);
	else
		return max(LCS_recurse(s1,l1,s2,l2+1),LCS_recurse(s1,l1+1,s2,l2));
}

int LCS_dp(string s1,string s2)
{
	for(int i=s1.size()-1;i>=0;i--)
	{
		for(int j=s2.size()-1;j>=0;j--)
		{
			if(s1[i]==s2[j])
				LCS[i][j]=1+LCS[i+1][j+1];
			else
				LCS[i][j]=max(LCS[i][j+1],LCS[i+1][j]);
		}
	}
	return LCS[0][0];
}


int main()
{
	string s1,s2;
	cin >>s1>>s2;
//	cout<<s1<<s2<<endl;
	cout<<LCS_recurse(s1,0,s2,0)<<endl;
	for(int i=0;i<1024;i++)
		for(int j=0;j<1024;j++)
			LCS[i][j]=0;
	cout<<LCS_dp(s1,s2)<<endl;
	return 0;
}

