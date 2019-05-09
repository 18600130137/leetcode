//
//  main.cpp
//  147. Insertion Sort List
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
public:
    ListNode* insertionSortList1(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        //dummy->next=head;
        
        ListNode *pre=dummy;
        ListNode *cur=head;
        
        while(cur){
            ListNode *next=cur->next;
            while(pre->next!=NULL && pre->next->val<cur->val){
                pre=pre->next;
            }
            cur->next=pre->next;
            pre->next=cur;
            pre=dummy;
            cur=next;
        }
        
        return dummy->next;
    }
    
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        
        ListNode *pre=dummy;
        ListNode *cur=dummy->next;
        ListNode *preCur=dummy;
        
        while(cur){
            ListNode *next=cur->next;
            while(pre->next!=NULL && pre->next->val<cur->val){
                pre=pre->next;
            }
            if(cur==pre->next){
                preCur=cur;
                cur=cur->next;
                pre=dummy;
            }else{
                cur->next=pre->next;
                pre->next=cur;
                pre=dummy;
                preCur->next=next;
                cur=next;
            }
            
        }
        
        return dummy->next;
    }
};


int main(int argc, const char * argv[]) {
    ListNode *head=buildListNode();
    Solution so=Solution();
    ListNode * result=so.insertionSortList1(head);
    while (result) {
        cout<<result->val<<" ";
        result=result->next;
    }
    cout<<endl;
    return 0;
}
