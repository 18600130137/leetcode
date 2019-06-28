//
//  main.cpp
//  257. Binary Tree Paths
//
//  Created by admin on 2019/6/28.
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
    void  searchPath(TreeNode* root,string cur,vector<string> & ret){
        if(root->left==NULL && root->right==NULL){
            ret.push_back(cur);
            return;
        }
        
        if(root->left!=NULL){
            searchPath(root->left,cur+"->"+to_string(root->left->val),ret);
        }
        if(root->right!=NULL){
            searchPath(root->right,cur+"->"+to_string(root->right->val),ret);
        }
        
        
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>  ret;
        if(root!=NULL){
            searchPath(root,to_string(root->val),ret);
        }
        return  ret;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,NULL,5};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    vector<string> ret=so.binaryTreePaths(root);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
