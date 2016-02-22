#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<limits>
#include<set>

using namespace std;

class Node{
   public:
      int val;
      Node *next;
      Node(int x): val(x), next(NULL){}
};

class BinaryTree{
   public:
      int val;
      BinaryTree *left;
      BinaryTree *right;
      BinaryTree(int x): val(x),left(NULL),right(NULL){}
      BinaryTree(int x, BinaryTree *left, BinaryTree *right): val(x), left(left),right(right){}
}

int main()
{
   return 0;
}

