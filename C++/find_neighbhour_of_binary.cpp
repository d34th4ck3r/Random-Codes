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
#include<bitset>
using namespace std;

#define P(s) printf("%s\n",s)
#define Pint(n) printf("%d",n)
#define Sint(n) scanf("%d",&n)
#define TEST printf("Test Called!")
#define NL printf("\n")
#define print(s) cout<<s<<endl

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

int GetNext(int val){
  int change = 0;
  int c0=0;
  int c1=0;
  while(!( ((val>>change)%2)==1 && (((val>>(change+1))%2)==0) )){
    if(((val>>change)%2)==1)
      c1++;
    else
      c0++;
    change++;
  }
  c1++;
  c0++;
  val = val | (1<<(change+1));
  c1--;
  val = val & (~((1<<(change+1))-1));
  val = val | ((1<<(c1))-1);
  return val;
}

int GetPrev(int val){
  int change=0;
  int c0=0;
  int c1=0;
  while(!( ((val>>change)%2)==0 && (((val>>(change+1))%2)==1) )){
    if(((val>>change)%2)==1)
      c1++;
    else
      c0++;
    change++;
  }
  c0++;
  c1++;
  val = val & (~(1<<(change+1)));
  c0--;
  val = val & (~((1<<(change+1))-1));
  val = val | ( ((1<<(c1))-1)<<c0);
  return val;
}

int main()
{
  int i=44;
  print(GetNext(i));
  print(GetPrev(i));
	return 0;
}

