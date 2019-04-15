//
//  main.cpp
//  116. Populating Next Right Pointers in Each Node
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
        TreeNode*  now=root;
        while(now){
            TreeNode *L=now;
            while(L){
                if(L->left){
                    //cout<<"L->left->val:"<<L->left->val<<endl;
                    L->left->next=L->right;
                    if(L->next){
                        L->right->next=L->next->left;
                    }
                }
                L=L->next;
            }
            now=now->left;
        }
        return root;
    }
    
    TreeNode* connect(TreeNode* root) {
        if(!root){
            return root;
        }
        if(root->left){
            root->left->next=root->right;
            if(root->next){
                root->right->next=root->next->left;
            }
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,4,5,6,7};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    TreeNode *newCon=so.connect1(root);
    traversalTree(newCon);
    return 0;
}
