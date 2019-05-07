//
//  main.cpp
//  142. Linked List Cycle II
//
//  Created by admin on 2019/5/7.
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
    ListNode* node1=new ListNode(3);
    ListNode* node2=new ListNode(2);
    ListNode* node3=new ListNode(0);
    ListNode* node4=new ListNode(-4);
    
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node2;
    return node1;
}

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        bool hasCircle=false;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                hasCircle=true;
                break;
            }
        }
        if(!hasCircle){
            return NULL;
        }
        
        ListNode* walk=head;
        while(walk!=fast){
            walk=walk->next;
            fast=fast->next;
        }
        return walk;
    }
};

int main(int argc, const char * argv[]) {
    ListNode* input=buildListNode();
    Solution so=Solution();
    ListNode * ret=so.detectCycle(input);
    cout<<"The ret val is:"<<ret->val<<endl;
    return 0;
}
