//
//  main.cpp
//  236. Lowest Common Ancestor of a Binary Tree
//
//  Created by admin on 2019/6/26.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode * left=lowestCommonAncestor(root->left, p, q);
        TreeNode * right=lowestCommonAncestor(root->right, p, q);
        
        return  left==NULL?right:(right==NULL?left:root);
        
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={3,5,1,6,2,0,8,NULL,NULL,7,4};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    TreeNode*  ret=so.lowestCommonAncestor(root,root->left,root->left->left);
    cout<<"The ret is:"<<ret->val<<endl;
    return 0;
}
