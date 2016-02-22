#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
    ListNode *mergeTwoLists(ListNode *l1,ListNode *l2){
        ListNode *start;
        ListNode *currentPointer;
        int flag=0;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<l2->val){
                if(flag==0){
                    flag=1;
                    start=list1;
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
        if(list1==NULL)
            currentPointer->next=l2;
        else
            currentPointer->next=l1;
        return start;
        
    }
}
