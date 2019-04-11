//
//  main.cpp
//  107. Binary Tree Level Order Traversal II
//
//  Created by admin on 2019/4/11.
//  Copyright © 2019年 liu. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
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
private:
    void dfs(TreeNode* root,vector<vector<int>> &ret,int level){
        if(root==NULL){
            return;
        }
        if(ret.size()==level){
            ret.push_back({});
        }
        ret[level].push_back(root->val);
        dfs(root->left,ret,level+1);
        dfs(root->right,ret,level+1);
        
    }
public:
    
    
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>  ret;
        dfs(root,ret,0);
        reverse(ret.begin(),ret.end());
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input={3,9,20,NULL,NULL,15,7};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    vector<vector<int>> ret=so.levelOrderBottom(root);
    for(auto item:ret){
        for(auto i:item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
