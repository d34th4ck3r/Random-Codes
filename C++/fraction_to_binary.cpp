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
	public:
		int value;
		Node *next;
		Node(){} //handling implicit Copy Constructor
		Node(int val): value(val),next(NULL){}
		Node(int val,Node *next): value(val),next(next){}

		void addToList(Node *node){
			Node *pointer = this;
			while(pointer->next != NULL){
				pointer = pointer->next;
			}
			pointer->next = node;
			return;
		}
};

class BinaryTree{
	public:
		int value;
		BinaryTree *left;
		BinaryTree *right;
		BinaryTree(){} //handling implicit Copy Constructor
		BinaryTree(int val): value(val),left(NULL),right(NULL){}
		BinaryTree(int val, BinaryTree *left, BinaryTree *right): value(val),left(left), right(right){}
};

string convert_fraction_to_binary(double num){
  string binary="0.";
  while(num > 0){
    if(binary.size() > 32){
      return "ERROR: size>32";
    }
    num = num*2;
    if(num >= 1){
      binary += to_string(1);
      num -= 1;
    }else{
      binary += to_string(0);
    }
  }
  return binary;
}


int main()
{
  cout << convert_fraction_to_binary(0.625) << endl;
	return 0;
}

