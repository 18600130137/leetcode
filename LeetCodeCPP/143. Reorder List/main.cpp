//
//  main.cpp
//  143. Reorder List
//
//  Created by admin on 2019/5/8.
//  Copyright © 2019年 liu. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *  buildListNode(){
    ListNode* node1=new ListNode(1);
    ListNode* node2=new ListNode(2);
    ListNode* node3=new ListNode(3);
    ListNode* node4=new ListNode(4);
    ListNode* node5=new ListNode(5);
    ListNode* node6=new ListNode(6);
    
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    node5->next=node6;
    return node1;
}

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next){
            return;
        }
        ListNode *slow=head,*fast=head;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *preEnd=slow->next;
        while(preEnd->next){
            ListNode* cur=preEnd->next;
            preEnd->next=cur->next;
            cur->next=slow->next;
            slow->next=cur;
        }
        
        ListNode *p1=head;
        ListNode *p2=slow->next;
        while(p1!=slow){
            slow->next=p2->next;
            p2->next=p1->next;
            p1->next=p2;
            p1=p2->next;
            p2=slow->next;
        }
        
    }
};
int main(int argc, const char * argv[]) {
    ListNode * head=buildListNode();
    Solution so=Solution();
    so.reorderList(head);
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}
