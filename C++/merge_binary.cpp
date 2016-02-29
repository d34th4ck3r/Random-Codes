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

class Node{
   public:
      int value;
      Node *next;
      Node(){} //handling implicit Copy Constructor
      Node(int val): value(val){}
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
      BinaryTree(int val): value(val){}
      BinaryTree(int val, BinaryTree *left, BinaryTree *right): value(val),left(left), right(right){}
};

int main()
{
  int i = 2, j = 6;
  int mask = (~0)<<(j+1) | (~((~0)<<i));
  int N = 0b10000000000;
  int M = 0b10011;
  N = N & mask;
  N = N | (M<<i);
  string binary =  bitset<32>(N).to_string();
  cout << binary << endl;
  return 0;
}

