//
//  main.cpp
//  109. Convert Sorted List to Binary Search Tree
//
//  Created by admin on 2019/4/11.
//  Copyright © 2019年 liu. All rights reserved.
//

/**
 * Definition for singly-linked list.
 */
#include <iostream>
#include <vector>
#include <queue>
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
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

void traversalTree(TreeNode*  root,int level=0){
    queue<TreeNode*> helper;
    helper.push(root);
    helper.push(NULL);
    int add_more=0;
    while (!helper.empty()) {
        auto f=helper.front();
        helper.pop();
        if(f==NULL){
            level++;
            if (add_more>0){
                helper.push(NULL);
                add_more=0;
            }
        }else{
            cout<<"Traversal val:"<<f->val<<" level:"<<level<<endl;
            if(f->left){
                add_more++;
                helper.push(f->left);
            }
            if(f->right){
                add_more++;
                helper.push(f->right);
            }
            
        }
        
    }
}

class Solution {
private:
    TreeNode* bstHelper(ListNode* head,ListNode* tail){
        if(head==tail){
            return NULL;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=tail && fast->next!=tail){
            fast=fast->next->next;
            slow=slow->next;
        }
        TreeNode* root=new TreeNode(slow->val);
        root->left=bstHelper(head,slow);
        root->right=bstHelper(slow->next,tail);
        // cout<<"slow==="<<slow->val<<endl;
        
        return root;
    }
    
public:
    TreeNode* sortedListToBST1(ListNode* head) {
        if(!head){
            return NULL;
        }
        
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* pre=slow;
        while(fast!=NULL){
            if(fast->next){
                fast=fast->next->next;
                pre=slow;
                slow=slow->next;
            }else{
                fast=fast->next;
            }
        }
        //cout<<pre->val<<" "<<slow->val<<endl;
        TreeNode* root=new TreeNode(slow->val);
        if(pre==slow){
            return root;
        }
        
        pre->next=NULL;
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return bstHelper(head,NULL);
    }
};



int main(int argc, const char * argv[]) {
    vector<int> input={-10,-3,0,5,9};
    ListNode* head=buildListNode(input);
    Solution so=Solution();
    TreeNode* ret=so.sortedListToBST(head);
    traversalTree(ret);
    return 0;
}
