//
//  main.cpp
//  82. Remove Duplicates from Sorted List II
//
//  Created by admin on 2019/4/2.
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

ListNode *  buildListNode(vector<int> v){
    ListNode * head=new ListNode(-1);
    ListNode * cur=head;
    for(int i:v){
        cur->next=new ListNode(i);
        cur=cur->next;
    }
    return head->next;
}

void printListNode(ListNode * n){
    while (n) {
        cout<<n->val<<" ";
        n=n->next;
    }
    cout<<endl;
}
class Solution {
public:
    ListNode* deleteDuplicates1(ListNode* head) {
        ListNode* cur=head;
        ListNode* pre=new ListNode(-1);
        pre->next=cur;
        while(cur){
            bool headRepeat=false;
            while(cur->next && cur->val==cur->next->val){
                headRepeat=true;
                cur->next=cur->next->next;
            }
            if(headRepeat){
                if(head->val==cur->val){
                    head=cur->next;
                }
                pre->next=cur->next;
                cur=pre->next;
            }else{
                pre=cur;
                cur=cur->next;
            }
        }
        
        return head;
        
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* pre=dummy;
        ListNode* cur=head;
        while(cur){
            while(cur->next && cur->val==cur->next->val){
                cur=cur->next;
            }
            if(pre->next==cur){
                pre=pre->next;
            }else{
                pre->next=cur->next;
            }
            cur=cur->next;
        }
        
        return dummy->next;
        
    }
};

int main(int argc, const char * argv[]) {
    ListNode* input=buildListNode({1,1,1,2,3,3,4});
    Solution so=Solution();
    ListNode* ret=so.deleteDuplicates(input);
    printListNode(ret);
    return 0;
}
