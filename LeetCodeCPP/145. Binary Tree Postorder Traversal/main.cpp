//
//  main.cpp
//  145. Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ret;
        TreeNode *p=root;
        stack<TreeNode*> helper;
        while(!helper.empty() || p){
            if(p){
                helper.push(p);
                ret.push_back(p->val);
                p=p->right;
            }else{
                TreeNode *top=helper.top();
                helper.pop();
                p=top->left;
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,4,5,6,7};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    vector<int>  ret=so.postorderTraversal(root);
    for(auto i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
