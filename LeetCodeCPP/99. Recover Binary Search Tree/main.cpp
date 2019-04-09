//
//  main.cpp
//  99. Recover Binary Search Tree
//
//  Created by admin on 2019/4/9.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
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
    TreeNode* pre=NULL;
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    
    void  inOrder(TreeNode * root){
        if(!root) return;
        inOrder(root->left);
        if(pre!=NULL && first==NULL && pre->val>=root->val){
            first=pre;
        }
        
        if(first!=NULL && pre->val>=root->val){
            second=root;
            if(pre!=first){
                return;
            }
        }
        pre=root;
        inOrder(root->right);
    }
    
public:
    void recoverTree1(TreeNode* root) {
        stack<TreeNode*> helper;
        TreeNode* pre=NULL;
        bool first=false;
        TreeNode *second;
        int tag=INT_MAX;
        while(root!=NULL || !helper.empty()){
            while(root!=NULL){
                helper.push(root);
                root=root->left;
            }
            root=helper.top();
            helper.pop();
            if(pre!=NULL && !first && pre->val>=root->val){
                first=true;
                second=root;
                tag=root->val;
            }
            if(!first){
                pre=root;
            }else if(root->val<tag){
                tag=root->val;
                second=root;
            }
            
            root=root->right;
        }
        int tmp=pre->val;
        pre->val=second->val;
        second->val=tmp;
    }
    
    void recoverTree(TreeNode* root) {
        inOrder(root);
        int tmp=first->val;
        first->val=second->val;
        second->val=tmp;
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input={1,3,NULL,NULL,2};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    so.recoverTree1(root);
    traversalTree(root);
    return 0;
}
