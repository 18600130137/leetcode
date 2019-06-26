//
//  main.cpp
//  234. Palindrome Linked List
//
//  Created by admin on 2019/6/26.
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

ListNode *  buildListNode(vector<int> input){
    ListNode * head=NULL;
    ListNode *cur=NULL;
    for(auto  item:input){
        if(!head){
            head=new ListNode(item);
            cur=head;
        }else{
            cur->next=new ListNode(item);
            cur=cur->next;
        }
    }
    
    return head;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode* rev=NULL,*fast=head,*slow=head;
        
        while(fast && fast->next){
            fast=fast->next->next;
            auto tmp=slow;
            slow=slow->next;
            tmp->next=rev;
            rev=tmp;
        }
        if(fast){
            slow=slow->next;
        }
        while(rev && rev->val==slow->val){
            rev=rev->next;
            slow=slow->next;
        }
        return not rev;
        
    }
};


int main(int argc, const char * argv[]) {
    vector<int> input={1,2,2,1};
    ListNode* head=buildListNode(input);
    Solution so=Solution();
    bool ret=so.isPalindrome(head);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
