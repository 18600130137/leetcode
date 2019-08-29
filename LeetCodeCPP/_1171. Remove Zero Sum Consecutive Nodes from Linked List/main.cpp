//
//  main.cpp
//  _1171. Remove Zero Sum Consecutive Nodes from Linked List
//
//  Created by admin on 2019/8/29.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode*  buildList(vector<int> &input){
    ListNode *dummy=new ListNode(-1);
    ListNode* cur=dummy;
    for(auto  i:input){
        cur->next=new ListNode(i);
        cur=cur->next;
    }
    return dummy->next;
}


class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *cur=head;
        unordered_map<int,ListNode*> helper;
        helper[0]=dummy;
        int lastValue=0;
        while(cur){
            lastValue+=cur->val;
            if(helper.count(lastValue)){
                cur=helper[lastValue]->next;
                int p=lastValue+cur->val;
                while(p!=lastValue){
                    helper.erase(p);
                    cur=cur->next;
                    p+=cur->val;
                }
                helper[lastValue]->next=cur->next;
            }else{
                helper[lastValue]=cur;
            }
            cur=cur->next;
        }
        
        return dummy->next;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={1,3,2,-3,-2,5,5,-5,1};
    ListNode* head=buildList(input);
    Solution so=Solution();
    ListNode* ret=so.removeZeroSumSublists(head);
    while (ret) {
        cout<<ret->val<<" ";
        ret=ret->next;
    }
    cout<<endl;
    return 0;
}
