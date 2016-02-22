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

string compress(string s){
	int pointer=0, counter=0;
	string compressed_string = "";
	bool same = true;
	while(pointer < s.size()){
		counter = 0;
		while(s[pointer] == s[pointer+counter])
			counter++;
		if(counter > 1)
			same = false;
		compressed_string += s[pointer] + to_string(counter);
		pointer = pointer + counter;
	}
	if(same || compressed_string.size() > s.size() )
		return s;
	return compressed_string;
}

int main()
{
	string s;
	cin >> s;
	cout << compress(s) << endl;
	return 0;
}

