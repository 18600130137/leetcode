//
//  main.cpp
//  86. Partition List
//
//  Created by admin on 2019/4/3.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* helper1=new ListNode(-1);
        ListNode* helper2=new ListNode(-1);
        ListNode* cur1=helper1;
        ListNode* cur2=helper2;
        while(head!=NULL){
            if(head->val<x){
                cur1->next=head;
                cur1=cur1->next;
            }else{
                cur2->next=head;
                cur2=cur2->next;
            }
            head=head->next;
        }
        cur2->next=NULL;
        cur1->next=helper2->next;
        
        return helper1->next;
    }
};
int main(int argc, const char * argv[]) {
    ListNode* input=buildListNode({1,4,3,2,5,2});
    Solution so=Solution();
    ListNode* ret=so.partition(input, 3);
    printListNode(ret);
    return 0;
}
