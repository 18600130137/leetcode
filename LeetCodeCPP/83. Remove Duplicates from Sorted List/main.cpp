//
//  main.cpp
//  83. Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* cur=head;
        while(cur->next){
            if(cur->val==cur->next->val){
                cur->next=cur->next->next;
            }else{
                cur=cur->next;
            }
            
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    ListNode* input=buildListNode({1,1,2,3,3});
    Solution so=Solution();
    ListNode* ret=so.deleteDuplicates(input);
    printListNode(ret);
    return 0;
}
