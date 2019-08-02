//
//  main.cpp
//  328. Odd Even Linked List
//
//  Created by admin on 2019/8/2.
//  Copyright © 2019年 liu. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *buildListNode(vector<int> input){
    ListNode *dummy=new ListNode(-1);
    ListNode *cur=dummy;
    for(auto  i:input){
        cur->next=new ListNode(i);
        cur=cur->next;
    }
    return dummy->next;
}




class Solution {
public:
    ListNode* oddEvenList1(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* tail=head;
        int len=1;
        while(tail->next!=NULL){
            tail=tail->next;
            len++;
        }
        
        ListNode* cur=head;
        ListNode* tail_mov=tail;
        int step=0;
        while(cur->next && step<len/2){
            step++;
            tail_mov->next=cur->next;
            cur->next=cur->next->next;
            cur=cur->next;
            tail_mov=tail_mov->next;
            tail_mov->next=NULL;
        }
        return head;
    }
    
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode *odd=head,*even=head->next,*evenHead=even;
        while(even!=NULL && even->next!=NULL){
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
    }
};



int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,4,5,6,7,8};
    ListNode *head=buildListNode(input);
    Solution so=Solution();
    ListNode* ret=so.oddEvenList(head);
    while (ret) {
        cout<<ret->val<<" ";
        ret=ret->next;
    }
    cout<<endl;
    return 0;
}
