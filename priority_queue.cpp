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
class Compare{
	public:
		bool operator()(int a,int b){
			return a>b;
		}
};



int main()
{
	priority_queue<int,vector<int>,Compare > first;
	first.push(12);
	first.push(13);
//	first.pop();
	cout<<first.top()<<endl;
	first.pop();
	cout<<first.top()<<endl;

	return 0;
}

