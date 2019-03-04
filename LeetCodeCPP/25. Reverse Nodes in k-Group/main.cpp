//
//  main.cpp
//  25. Reverse Nodes in k-Group
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
private:
    int  getLen(ListNode* head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int m=getLen(head);
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* cur=dummy;
        for(int i=0;i<m/k;i++){
            for(int j=0;j<k-1;j++){
                ListNode* tmp=cur->next;
                cur->next=head->next;
                head->next=head->next->next;
                cur->next->next=tmp;
            }
            cur=head;
            head=head->next;
        }
        
        return dummy->next;
    }
};


int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,4,5,6};
    ListNode* inputNode=buildListNode(input);
    Solution so=Solution();
    ListNode* back=so.reverseKGroup(inputNode,3);
    printListNode(back);
    return 0;
}
