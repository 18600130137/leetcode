//
//  main.cpp
//  144. Binary Tree Preorder Traversal
//
//  Created by admin on 2019/5/8.
//  Copyright © 2019年 liu. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

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

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ret;
        stack<TreeNode*> helper;
        helper.push(root);
        while(!helper.empty()){
            TreeNode* top=helper.top();
            helper.pop();
            ret.push_back(top->val);
            if(top->right){
                helper.push(top->right);
            }
            if(top->left){
                helper.push(top->left);
            }
        }
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,NULL,2,3};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    vector<int> ret=so.preorderTraversal(root);
    for(auto i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
