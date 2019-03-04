//
//  main.cpp
//  19. Remove Nth Node From End of List
//
//  Created by admin on 2019/2/28.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * slow=head;
        ListNode * fast=head;
        n++;
        while(fast && n){
            fast=fast->next;
            n--;
        }
        if(!fast && n==1){
            return head->next;
        }
        
        while(fast){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        
        return head;
        
    }
};



int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,4,5};
    ListNode * i1=buildListNode(input);
    int i2=2;
    Solution so=Solution();
    printListNode(i1);
    ListNode * ans=so.removeNthFromEnd(i1, i2);
    printListNode(ans);
    return 0;
}
