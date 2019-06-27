//
//  main.cpp
//  237. Delete Node in a Linked List
//
//  Created by admin on 2019/6/27.
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
    ListNode* node1=new ListNode(4);
    ListNode* node2=new ListNode(5);
    ListNode* node3=new ListNode(1);
    ListNode* node4=new ListNode(9);
    
    
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    return node1;
}

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node!=NULL && node->next!=NULL){
            node->val=node->next->val;
            node->next=node->next->next;
        }
    }
};

int main(int argc, const char * argv[]) {
    ListNode* head=buildListNode();
    ListNode* input=head->next;
    Solution so=Solution();
    so.deleteNode(input);
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    
    
    return 0;
}
