//
//  main.cpp
//  102. Binary Tree Level Order Traversal
//
//  Created by admin on 2019/4/10.
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
    void traverse(TreeNode* root,vector<vector<int>> &ret,int level){
        if(!root){
            return;
        }
        if(ret.size()<=level){
            ret.push_back({});
        }
        ret[level].push_back(root->val);
        traverse(root->left,ret,level+1);
        traverse(root->right,ret,level+1);
    }
    
public:
    vector<vector<int>> levelOrder1(TreeNode* root) {
        vector<vector<int>>  ret;
        if(!root){
            return ret;
        }
        queue<TreeNode*> helper;
        helper.push(root);
        while(!helper.empty()){
            int size=helper.size();
            vector<int> tmp;
            for(int i=0;i<size;i++){
                TreeNode* t=helper.front();
                helper.pop();
                tmp.push_back(t->val);
                if(t->left){
                    helper.push(t->left);
                }
                if(t->right){
                    helper.push(t->right);
                }
            }
            ret.push_back(tmp);
        }
        return ret;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        traverse(root,ret,0);
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    vector<int> input={3,9,20,NULL,NULL,15,7};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    vector<vector<int>> ret=so.levelOrder(root);
    for (auto item:ret) {
        for(auto i:item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
