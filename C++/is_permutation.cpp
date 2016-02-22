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
using namespace std;

#define P(s) printf("%s\n",s)
#define Pint(n) printf("%d",n)
#define Sint(n) scanf("%d",&n)
#define TEST printf("Test Called!")
#define NL printf("\n")

class Node{
	int value;
	Node *next;
	Node(){} //handling implicit Copy Constructor
	Node(int val): value(val){}
	Node(int val,Node *next): value(val),next(next){}
};

class BinaryTree{
	int value;
	BinaryTree *left;
	BinaryTree *right;
	BinaryTree(){} //handling implicit Copy Constructor
	BinaryTree(int val): value(val){}
	BinaryTree(int val, BinaryTree *left, BinaryTree *right): value(val),left(left), right(right){}
};

bool is_permutation(string s1,string s2){
	int Hash[256] = {0};
	int sum=0;
	for(int i=0;i<s1.size();i++){
		Hash[s1[i]] += 1;
		sum+=1;
	}
	for(int i=0;i<s2.size();i++){
		if(Hash[s2[i]] <= 0)
			return false;
		Hash[s2[i]] -= 1;
		sum-=1;
	}
	if(sum!=0)
		return false;
	return true;
}

int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	cout << is_permutation(s1,s2) <<endl;
	return 0;
}

