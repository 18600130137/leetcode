//
//  main.cpp
//  117. Populating Next Right Pointers in Each Node II
//
//  Created by admin on 2019/4/15.
//  Copyright © 2019年 liu. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left=NULL;
    TreeNode *right=NULL;
    TreeNode *next=NULL;
    TreeNode(int x) : val(x), left(NULL), right(NULL),next(NULL) {}
};

TreeNode*  buildTree(vector<int> &in){
    TreeNode * root=new TreeNode(in[0]);
    queue<TreeNode*> helper;
    helper.push(root);
    size_t m=in.size(),start=1;
    while (!helper.empty() && start<m) {
        auto  f=helper.front();
        helper.pop();
        if(in[start]){
            f->left=new TreeNode(in[start]);
            helper.push(f->left);
        }
        
        start++;
        if(start>=m){
            break;
        }
        if(in[start]){
            f->right=new TreeNode(in[start]);
            helper.push(f->right);
        }
        
        start++;
    }
    return root;
}

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
            cout<<"Traversal val:"<<f->val<<" Next val:"<<(f->next==NULL?-1:f->next->val)<<"     level:"<<level<<endl;
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
public:
    TreeNode* connect1(TreeNode* root) {
        TreeNode* pre=NULL;
        TreeNode* head=NULL;
        TreeNode * cur=root;
        while(cur){
            while(cur){
                if(cur->left){
                    if(pre){
                        pre->next=cur->left;
                    }else{
                        head=cur->left;
                    }
                    pre=cur->left;
                }
                if(cur->right){
                    if(pre){
                        pre->next=cur->right;
                    }else{
                        head=cur->right;
                    }
                    pre=cur->right;
                }
                cur=cur->next;
            }
            cur=head;
            head=NULL;
            pre=NULL;
            
        }
        
        return root;
    }
    
    TreeNode* connect(TreeNode* root) {
        TreeNode * cur=root;
        while(cur){
            TreeNode* head=new TreeNode(-1);
            TreeNode*pre=head;
            
            while(cur){
                if(cur->left){
                    pre->next=cur->left;
                    pre=pre->next;
                }
                if(cur->right){
                    pre->next=cur->right;
                    pre=pre->next;
                }
                cur=cur->next;
            }
            cur=head->next;
        }
        
        return root;
    }
};


int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,4,5,NULL,7};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    TreeNode* ret=so.connect(root);
    traversalTree(ret);
    return 0;
}
