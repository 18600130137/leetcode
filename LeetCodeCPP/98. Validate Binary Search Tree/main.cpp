//
//  main.cpp
//  98. Validate Binary Search Tree
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
public:
    bool isValidBST1(TreeNode* root,long left=LONG_MIN,long right=LONG_MAX) {
        if(root==NULL){
            return true;
        }
        if(root->val<=left || root->val>=right){
            return false;
        }
        return isValidBST1(root->left,left,root->val) && isValidBST1(root->right,root->val,right);
        
    }
    
    
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> helper;
        TreeNode* pre=NULL;
        while(root!=NULL || !helper.empty()){
            while(root!=NULL){
                helper.push(root);
                root=root->left;
            }
            root=helper.top();
            helper.pop();
            if(pre!=NULL && root->val<=pre->val){
                return false;
            }
            pre=root;
            // cout<<"pre value:"<<pre->val<<endl;
            root=root->right;
        }
        
        
        return true;
    }
};



int main(int argc, const char * argv[]) {
    vector<int>  input={2,1,3};
    vector<int>  input2={5,1,4,NULL,NULL,3,6};
    TreeNode* root=buildTree(input2);
    Solution so=Solution();
    bool ret=so.isValidBST(root);
    cout<<"Is valid ret:"<<ret<<endl;
    return 0;
}
