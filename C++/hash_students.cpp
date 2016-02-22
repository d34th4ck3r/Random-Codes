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
};

class Student{
   int id;
   public:
        Student(){}
        Student(int id): id(id){}
        int getId(){ return id;}
};

class Solution{
   public:
      map<int,Student> hashStudents(Student students[],int len){
         map<int,Student> hashStudents;
         for(int i=0;i<len;i++){
            hashStudents[students[i].getId()]=students[i];
         }
         return hashStudents;
      }
};

int main()
{
   Student s1(12);
   Student s2(13);
   Student s[2]={s1,s2};
   Solution sol;
   map<int,Student> my_map = sol.hashStudents(s,2);
   cout << my_map[12].getId()<<endl;
   return 0;
}

