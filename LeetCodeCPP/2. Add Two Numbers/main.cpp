//
//  main.cpp
//  2. Add Two Numbers
//
//  Created by admin on 2019/2/21.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


/**
 * Definition for singly-linked list.
  */
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
     ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
         ListNode* head=new ListNode(-1);
         ListNode* cur=head;
         int carry=0;
         while(l1 || l2 || carry){
             if(l1){
                 carry+=l1->val;
                 l1=l1->next;
             }
             if(l2){
                 carry+=l2->val;
                 l2=l2->next;
             }
             cur->next=new ListNode(carry%10);
             cur=cur->next;
             carry=carry/10;
         }
         return  head->next;
     }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        
        int carry=0;
        ListNode* head=l1;
        ListNode* pre=l1;
        while(l1){
            int l2_val=(l2==NULL?0:l2->val);
            l1->val+=l2_val+carry;
            carry=l1->val/10;
            l1->val%=10;
            pre=l1;
            l1=l1->next;
            l2=(l2==NULL?l2:l2->next);
            if(l1==NULL){
                l1=pre;
                l1->next=l2;
                l1=l1->next;
                l2=NULL;
            }
        }
        if(carry){
            pre->next=new ListNode(carry);
        }
        
        
        
        return  head;
    }
};

ListNode* getNode(vector<int> &input){
    ListNode *head=new ListNode(-1);
    ListNode *curr=head;
    for(int  i: input){
        curr->next=new ListNode(i);
        curr=curr->next;
    }
    
    return head->next;
}

void printNode(ListNode* in){
    while (in) {
        cout<<in->val<<" ";
        in=in->next;
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    vector<int>  input1={2,4,3};
    vector<int>  input2={5,6,4,5};
    ListNode * node1=getNode(input1);
    ListNode* node2=getNode(input2);
    Solution so=Solution();
    ListNode * ret=so.addTwoNumbers1(node1, node2);
    printNode(ret);
    
    return 0;
}
