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

struct Node{
   int val;
   Node *next;
   Node(int x): val(x), next(NULL){}
};

Node* mergeSortedList(Node* l1,Node* l2){
   if(l1==NULL)
      return l2;
   if(l2==NULL)
      return l1;
   ListNode *start=NULL;
   ListNode *currentPointer=NULL;
   int flag=0;
   while(l1!=NULL && l2!=NULL){
      if(l1->val<l2->val){
         if(flag==0){
            flag=1;
            start=l1;
            currentPointer=start;
            l1=l1->next;
         }else{
            currentPointer->next=l1;
            l1=l1->next;
            currentPointer=currentPointer->next;
         }
      }else{
         if(flag==0){
            flag=1;
            start=l2;
            currentPointer=start;
            l2=l2->next;
         }else{
            currentPointer->next=l2;
            l2=l2->next;
            currentPointer=currentPointer->next;
         }
      }
   }
   if(currentPointer!=NULL){
      if(l1==NULL)
         currentPointer->next=l2;
      else
         currentPointer->next=l1;
   }
   return start;
}

Node* sortLinkedList(Node *start,Node *end){
   Node *middle=head,*new_end=head;
   while(new_end!=end){
      middle=middle->next;
      if(new_end->next!=end)
        new_end=new_end->next->next;
   }
   Node* left=sortLinkedList(start,middle);
   Node* right=sortLinkedList(middle,end);

}

int main()
{

   return 0;
}

