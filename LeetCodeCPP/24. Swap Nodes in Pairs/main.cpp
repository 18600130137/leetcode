//
//  main.cpp
//  24. Swap Nodes in Pairs
//
//  Created by admin on 2019/3/4.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *cur=dummy;
        while(head && head->next){
            cur->next=head->next;
            head->next=head->next->next;
            cur->next->next=head;
            head=head->next;
            cur=cur->next->next;
        }
        return  dummy->next;
    }
};


int main(int argc, const char * argv[]) {
    vector<int>  intput={1,2,3,4,5};
    ListNode* inputNode=buildListNode(intput);
    printListNode(inputNode);
    Solution so=Solution();
    ListNode* output=so.swapPairs(inputNode);
    printListNode(output);
    return 0;
}
