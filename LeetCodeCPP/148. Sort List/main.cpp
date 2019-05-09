//
//  main.cpp
//  148. Sort List
//
//  Created by admin on 2019/5/9.
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
    ListNode* node1=new ListNode(4);
    ListNode* node2=new ListNode(2);
    ListNode* node3=new ListNode(1);
    ListNode* node4=new ListNode(3);
    
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    return node1;
}


class Solution {
private:
    ListNode* merger(ListNode *left,ListNode *right){
        ListNode *dummy=new ListNode(-1);
        ListNode *cur=dummy;
        while(left && right){
            if(left->val<right->val){
                cur->next=left;
                left=left->next;
            }else{
                cur->next=right;
                right=right->next;
            }
            cur=cur->next;
        }
        cur->next=left?left:right;
        
        return dummy->next;
    }
    
    ListNode* merger1(ListNode *left,ListNode *right){
        ListNode *dummy=new ListNode(-1);
        dummy->next=left;
        ListNode *cur=dummy;
        
        while(left && right){
            if(left->val<right->val){
                left=left->next;
            }else{
                ListNode *tmp=right;
                right=right->next;
                tmp->next=cur->next;
                cur->next=tmp;
            }
            cur=cur->next;
        }
        if(right){
            cur->next=right;
        }
        
        return dummy->next;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode *slow=head,*fast=head,*pre=NULL;
        while(fast && fast->next){
            fast=fast->next->next;
            pre=slow;
            slow=slow->next;
        }
        pre->next=NULL;
        ListNode * left=sortList(head);
        ListNode * right=sortList(slow);
        
        return merger1(left,right);
        
    }
};
int main(int argc, const char * argv[]) {
    ListNode* head=buildListNode();
    Solution so=Solution();
    ListNode *ret= so.sortList(head);
    while(ret){
        cout<<ret->val<<" ";
        ret=ret->next;
    }
    cout<<endl;
    return 0;
}
