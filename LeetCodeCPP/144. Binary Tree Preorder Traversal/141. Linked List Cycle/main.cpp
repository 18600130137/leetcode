//
//  main.cpp
//  141. Linked List Cycle
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
    bool hasCycle(ListNode *head) {
        ListNode*slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *input=buildListNode();
    Solution so=Solution();
    bool ret=so.hasCycle(input);
    cout<<"Item has a circle:"<<ret<<endl;
    return 0;
}
