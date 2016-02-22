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

bool is_unique(string s){
	bool Hash[128] = {false};
	for(int i=0;i<s.length();i++){
		if(Hash[s[i]] != false)
			return false;
		Hash[s[i]] = true;
	}
	return true;
}

bool is_unique_without_ds(string s){
	sort(s.begin(),s.end());
	for(int i=0;i<s.size()-1;i++){
		if(s[i]==s[i+1])
			return false;
	}
	return true;
}

int main()
{
	string s;
	cin >> s;
	cout << is_unique(s) << endl;
	cout << is_unique_without_ds(s) << endl;
	return 0;
}

