//
//  main.cpp
//  _1019. Next Greater Node In Linked List
//
//  Created by admin on 2019/4/1.
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>   ret,stack;
        for(ListNode *node=head;node;node=node->next){
            while(stack.size()>0 && node->val>ret[stack.back()]){
                ret[stack.back()]=node->val;
                stack.pop_back();
            }
            stack.push_back(ret.size());
            ret.push_back(node->val);
        }
        for(auto i:stack){
            ret[i]=0;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input={1,7,5,1,9,2,5,1};
    ListNode* in=buildListNode(input);
    Solution so=Solution();
    vector<int> ret=so.nextLargerNodes(in);
    for(auto i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
