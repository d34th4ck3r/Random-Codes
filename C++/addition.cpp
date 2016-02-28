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

  Node* addLists(Node* L1,Node* L2,int *remainder){  //works only if the node L1 and L2 are of same size.
    Node *sum;
    int add;
    if(L1->next == NULL && L2->next == NULL){
      add = L1->value + L2->value + *remainder;
      *remainder = add/10;
      sum = new Node(add%10);
      return sum;
    }
    else if(L1->next == NULL){
      sum = addLists(L1,L2->next,remainder);
    }else if(L2->next == NULL){
      sum = addLists(L1->next,L2,remainder);
    }else{
      sum = addLists(L1->next,L2->next,remainder);
    }
    add = L1->value + L2->value + *remainder;
    *remainder = add/10;
    Node *new_node = new Node(add%10);
    new_node->next = sum;
    sum = new_node;
    return sum;
  }

  public:
    int value;
    Node *next;
    Node(){} //handling implicit Copy Constructor
    Node(int val): value(val),next(NULL){}
    Node(int val,Node *next): value(val),next(next){}

    int size(){
      int s=0;
      Node *counter = this;
      while(counter != NULL){
        counter = counter->next;
        s++;
      }
      return s;
    }

    Node* AddToBeginning(Node* node){
      node->next = this;
      return node;
    }

    Node* AddToBeginning(int val){
      Node *new_node = new Node(val);
      AddToBeginning(new_node);
      return new_node;
    }

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

    Node reverse_add(Node& node){
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

    Node* operator + (Node& node){
      int remainder = 0;
      Node *new_this = this;
      Node* new_node = &node;
      int this_size = this->size();
      int node_size = node.size();
      if(this_size < node_size){
        for(int i=node_size; i>this_size;i--)
          new_this = this->AddToBeginning(0);
      }else{
        for(int i=this_size; i>node_size;i--)
          new_node = node.AddToBeginning(0);
      }
      Node *addition = addLists(new_this,new_node,&remainder);
      if(remainder>0){
        Node *new_node = new Node(remainder);
        new_node->next = addition;
        addition = new_node;
      }
      return addition;
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
  int array1[] = {9,9,9};
  Node* list1 = Node::convertArrayToLinkedList(array1,sizeof(array1)/sizeof(array1[0]));
  list1->print();
  int array2[] = {9,9,9};
  Node* list2 = Node::convertArrayToLinkedList(array2,sizeof(array2)/sizeof(array2[0]));
  list2->print();
  Node *new_list = *list1 + *list2;
  new_list->print();
  return 0;
}

