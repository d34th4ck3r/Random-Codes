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
    BinaryTree(int val): value(val),left(NULL),right(NULL){}
    BinaryTree(int val, BinaryTree *left, BinaryTree *right): value(val),left(left), right(right){}
    void insert(int val){
      if(val<=value){
        if(left == NULL){
          left = new BinaryTree(val);
          return;
        }
        left->insert(val);
      }else{
        if(right == NULL){
          right = new BinaryTree(val);
          return;
        }
        right->insert(val);
      }
    }

    BinaryTree* find(int val){
      if(value == val)
        return this;
      else{
        if(val<value){
          if(left != NULL)
            return left->find(val);
          return NULL;
        }else{
          if(right != NULL)
            return right->find(val);
          return NULL;
        }
      }
    }

    bool is_balanced(){
      if( ((right == NULL) && (left != NULL && (left->left != NULL || left->right != NULL))) ||
          ((left == NULL) && (right != NULL && (right->left != NULL || right->right != NULL))))
        return false;
      if(left != NULL && right != NULL)
        return left->is_balanced() && right->is_balanced();
      else if(left != NULL)
        return left->is_balanced();
      else if(right != NULL)
        return right->is_balanced();
      else
        return true;
    }

    static BinaryTree* convertArrayToBinaryTree(int *array,int N){
      int mid = N/2;
      BinaryTree *BT = new BinaryTree(array[mid]);
      if (N==1){
        return BT;
      }
      if(N==2){
        BT->left = new BinaryTree(array[0]);
        return BT;
      }
      BT->left = convertArrayToBinaryTree(&array[0],mid);
      BT->right = convertArrayToBinaryTree(&array[mid+1],N-1-mid);
      return BT;
    }

    void print_inorder(){
      if(left != NULL)
        left->print_inorder();
      cout << value << " ";
      if(right != NULL)
        right->print_inorder();
    }

    void print_preorder(){
      cout << value << " ";
      if(left != NULL)
        left->print_preorder();
      if(right != NULL)
        right->print_preorder();
    }

    void print_postorder(){
      if(left != NULL)
        left->print_postorder();
      if(right != NULL)
        right->print_postorder();
      cout << value << " ";
    }
};

int main()
{
  int array[] ={7,8,9,10,14,15,17};
  BinaryTree *bt = BinaryTree::convertArrayToBinaryTree(array,sizeof(array)/sizeof(array[0]));
  bt->print_inorder();
  NL;
  bt->print_preorder();
  NL;
  bt->print_postorder();
  NL;
  return 0;
}

