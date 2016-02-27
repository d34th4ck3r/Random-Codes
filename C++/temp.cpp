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

void test_fun(vector<int> a){
  a.push_back(2);
  cout << a[0]  << endl;
}

int main()
{
  vector<int> a;
  test_fun(a);
  cout << a.size() << endl;
  return 0;
}

