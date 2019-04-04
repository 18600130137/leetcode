//
//  main.cpp
//  92. Reverse Linked List II
//
//  Created by admin on 2019/4/4.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy=new ListNode(-1);
        ListNode* pre=dummy;
        pre->next=head;
        for(int i=1;i<m;i++){
            head=head->next;
            pre=pre->next;
        }
        for(int i=1;i<=n-m;i++){
            ListNode *tmp=pre->next;
            pre->next=head->next;
            head->next=head->next->next;
            pre->next->next=tmp;
        }
        
        return dummy->next;
    }
};

int main(int argc, const char * argv[]) {
    ListNode* input=buildListNode({1,2,3,4,5});
    Solution so=Solution();
    ListNode* ret=so.reverseBetween(input,2, 4);
    printListNode(ret);
    return 0;
}
