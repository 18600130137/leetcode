//
//  main.cpp
//  203. Remove Linked List Elements
//
//  Created by admin on 2019/6/10.
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

ListNode *  buildListNode(vector<int> input){
    ListNode * head=NULL;
    ListNode *cur=NULL;
    for(auto  item:input){
        if(!head){
            head=new ListNode(item);
            cur=head;
        }else{
            cur->next=new ListNode(item);
            cur=cur->next;
        }
    }
    
    return head;
}
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return NULL;
        }
        
        while(head!=NULL && head->val==val){
            head=head->next;
        }
        
        ListNode *move=head;
        while(move!=NULL&& move->next!=NULL){
            if(move->next->val==val){
                move->next=move->next->next;
            }else{
                move=move->next;
            }
            
        }
        
        return head;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,2,6,3,4,5,6};
    ListNode* head=buildListNode(input);
    Solution so=Solution();
    ListNode * del=so.removeElements(head, 6);
    while (del) {
        cout<<del->val<<" ";
        del=del->next;
    }
    cout<<endl;
    return 0;
}
