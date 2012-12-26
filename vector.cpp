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

int main()
{
	vector<int> myvec;
	myvec.push_back(12123);
	myvec.push_back(1123);
	cout<<myvec[1]<<endl;
	sort(myvec.begin(),myvec.end());
	cout<<myvec[1]<<endl;
	for(int i=0;i<myvec.size();i++)
		cout<<myvec[i]<<" "<<endl;
	vector<int> v(2,100);
	for(int i=0;i<30;i++)
		cout<<"--"<<v[i]<<" "<<endl;
	return 0;
}

