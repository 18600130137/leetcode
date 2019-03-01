//
//  main.cpp
//  21. Merge Two Sorted Lists
//
//  Created by admin on 2019/3/1.
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

class Solution {
public:
         ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
             if(!l1){
                 return l2;
             }
             if(!l2){
                 return l1;
             }
             if(l1->val<=l2->val){
                 l1->next=mergeTwoLists1(l1->next,l2);
                 return l1;
             }else{
                 l2->next=mergeTwoLists1(l1,l2->next);
                 return l2;
             }
    
         }
    
          ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
             ListNode *helper=new ListNode(-1);
             ListNode *cur=helper;
             while(l1 && l2){
                 if(l1->val<=l2->val){
                     cur->next=l1;
                     l1=l1->next;
                 }else{
                     cur->next=l2;
                     l2=l2->next;
                 }
                 cur=cur->next;
             }
             if(l1){
                 cur->next=l1;
             }
             if(l2){
                 cur->next=l2;
             }
             return helper->next;
    
         }
    
    
    ListNode* mergeTwoLists3(ListNode* l1, ListNode* l2) {
        ListNode *helper=new ListNode(-1);
        helper->next=l1;
        ListNode *cur=helper;
        while(l1 && l2){
            if(l1->val<=l2->val){
                l1=l1->next;
            }else{
                ListNode *tmp1=cur->next;
                cur->next=l2;
                ListNode *tmp2=l2->next;
                l2->next=tmp1;
                l2=tmp2;
            }
            cur=cur->next;
        }
        if(l2){
            cur->next=l2;
        }
        
        return helper->next;
    }
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


int main(int argc, const char * argv[]) {
    vector<int> input1={1,2,4};
    vector<int> input2={1,3,4};
    ListNode * node1=buildListNode(input1);
    ListNode*  node2=buildListNode(input2);
    Solution so=Solution();
    ListNode* ret= so.mergeTwoLists3(node1, node2);
    printListNode(ret);
    return 0;
}
