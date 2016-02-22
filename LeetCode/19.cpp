#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* previous=head;
        ListNode* nth=head;
        ListNode* end=head;
        for (int i=1; i<n; i++)
            end=end->next;
        while(end->next!=NULL){
            previous=nth;
            nth=nth->next;
            end=end->next;
        }
        if(previous!=NULL && nth!=NULL){
            previous->next=nth->next;
            delete(nth);
        }
        if(previous==nth)
            return NULL;
        return head;
    }
};