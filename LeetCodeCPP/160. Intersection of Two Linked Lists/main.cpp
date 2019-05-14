//
//  main.cpp
//  160. Intersection of Two Linked Lists
//
//  Created by admin on 2019/5/14.
//  Copyright © 2019年 liu. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<ListNode*>  buildListNode(){
    ListNode* node1=new ListNode(4);
    ListNode* node2=new ListNode(1);
    ListNode* node3=new ListNode(8);
    ListNode* node4=new ListNode(4);
    ListNode* node5=new ListNode(5);
    
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    
    ListNode* node1_=new ListNode(5);
    ListNode* node2_=new ListNode(0);
    ListNode* node3_=new ListNode(1);
    node1_->next=node2_;
    node2_->next=node3_;
    node3_->next=node3;
    
    
    return {node1,node1_};
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL){
            return NULL;
        }
        ListNode *pa=headA,*pb=headB;
        while(pa!=pb){
            if(pa==NULL){
                pa=headB;
            }else{
                pa=pa->next;
            }
            
            if(pb==NULL){
                pb=headA;
            }else{
                pb=pb->next;
            }
        }
        
        return pa;
    }
    
    
};

int main(int argc, const char * argv[]) {
    vector<ListNode*>  input=buildListNode();
    Solution so=Solution();
    ListNode* ret=so.getIntersectionNode(input[0], input[1]);
    while(ret){
        cout<<ret->val<<" ";
        ret=ret->next;
    }
    cout<<endl;
    return 0;
}
