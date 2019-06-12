//
//  main.cpp
//  206. Reverse Linked List
//
//  Created by admin on 2019/6/12.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

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
    
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    return node1;
}
class Solution {
public:
    
    ListNode*  reverse(ListNode *from,ListNode *to){
        if(from!=NULL){
            ListNode *next=from->next;
            from->next=to;
            return reverse(next,from);
        }else{
            return to;
        }
    }
    
    
    ListNode* reverseList1(ListNode* head) {
        ListNode *pre=NULL,*next=NULL,*cur=head;
        while(cur!=NULL){
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode *node=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return node;
        
    }};


int main(int argc, const char * argv[]) {
    ListNode * head=buildListNode();
    Solution so=Solution();
    ListNode *ret= so.reverseList(head);
    while (ret) {
        cout<<ret->val<<" ";
        ret=ret->next;
    }
    cout<<endl;
    return 0;
}
