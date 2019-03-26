//
//  main.cpp
//  61. Rotate List
//
//  Created by admin on 2019/3/26.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        
        ListNode* tail=head;
        int len=1;
        while(tail->next!=NULL){
            tail=tail->next;
            len++;
        }
        k%=len;
        tail->next=head;
        for(int i=0;i<len-k;i++){
            tail=tail->next;
        }
        head=tail->next;
        tail->next=NULL;
        return head;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *input=buildListNode({1,2,3,4,5});
    Solution so=Solution();
    ListNode *ret=so.rotateRight(input, 2);
    printListNode(ret);
    return 0;
}
