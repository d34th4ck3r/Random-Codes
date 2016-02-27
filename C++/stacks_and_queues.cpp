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

    static Node* convertArrayToLinkedList(int *array,int N){
      Node *start = new Node(array[0]);
      Node *end = start;
      for(int i=1;i<N;i++){                                                
        Node *node = new Node(array[i]);              
        end->next = node;              
        end = end->next;
      }
      return start;  
    }

    void print(){
      Node *current = this;
      while(current!=NULL){
        cout << current->value <<" ";
        current = current->next;
      }
      cout << endl;
    }

    void remove_duplicates(){
      map<int,bool> Hash;
      Node *prev = this;
      Hash[prev->value] = true;
      Node *curr = this->next;
      while(curr!=NULL){
        if(Hash.find(curr->value) == Hash.end()){
          Hash[curr->value] = true;
          prev = curr;
          curr = curr->next;
        }else{
          prev->next = curr->next;
          Node *temp = curr;
          curr = curr->next;
          delete temp;
        }
      }
    }

    Node* parition_by(int val){
      Node *center = this;
      Node *less = center,*more = center, *pointer = this->next;
      center->next = NULL;
      while(pointer != NULL){
        if(pointer->value < val){
          Node *temp = pointer;
          pointer = pointer->next;
          temp->next = less;
          less = temp;
        }else{
          more->next = pointer;
          pointer = pointer->next;
          more = more->next;
          more->next = NULL;
        }
      }
      return less;
    }

    Node operator + (Node& node){
      Node *P1 = this;
      Node *P2 = &node;
      Node *start, *counter;
      int remainder=0;
      while(P1 != NULL || P2 != NULL){
        int add = value + node.value;
        if(P1 !=NULL && P2 !=NULL){
          add = P1->value + P2->value + remainder;
          remainder = add/10;
        }else if(P1 != NULL){
          add = P1->value + remainder;
          remainder = add/10;
        }else{
          add = P2->value + remainder;
          remainder = add/10;
        }
        Node *temp = new Node(add % 10);
        if(P1==this){
          start = temp;
          counter = temp;
        }else{
          counter->next = temp;
          counter = temp;
        }
        if(P1 != NULL)
          P1 = P1->next;
        if(P2 != NULL)
          P2 = P2->next;
      }
      if(remainder > 0){
        Node *temp = new Node(remainder);
        counter->next = temp;
        counter = temp;
      }
      return *start;
    }
};

class Stack{
  Node *top;
  public:

  Stack():top(NULL){}

  void push(int val){
    if(top != NULL){
      Node *new_node = new Node(val);
      new_node->next = top;
      top = new_node;
    }else{
      top = new Node(val);
    }
  }

  int pop(){
    if(top != NULL){
      int val = top->value;
      Node *temp = top;
      top = top->next;
      delete temp;
      return val;
    }
    return -1;
  }

  int peek(){
    return top->value;
  }
};

class Queue{
  Node *start,*end;
  public:
    Queue():start(NULL),end(NULL){}

    void enqueue(int val){
      if(end != NULL){
        Node *new_node = new Node(val);
        end->next = new_node;
        end = end->next;
      }else{
        start = new Node(val);
        end = start;
      }
    }

    int dequeue(){
      if(start !=NULL){
        int val = start->value;
        Node *temp = start;
        start = start->next;
        delete temp;
        return val;
      }
      return -1;
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
   int array1[] = {3,3,3,3,3,3,3};
   Node* list1 = Node::convertArrayToLinkedList(array1,sizeof(array1)/sizeof(array1[0]));
   list1->print();
   int array2[] = {4,2,3};
   Node* list2 = Node::convertArrayToLinkedList(array2,sizeof(array2)/sizeof(array2[0]));
   list2->print();
   Node new_list = *list1 + *list2;
   new_list.print();
   return 0;
}

