//
//  main.cpp
//  103. Binary Tree Zigzag Level Order Traversal
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
    void  travelZig(TreeNode* root,vector<vector<int>> &ret,int level){
        if(!root) return;
        if(ret.size()<=level){
            ret.push_back({});
        }
        if(level%2==0){
            ret[level].push_back(root->val);
        }else{
            ret[level].insert(ret[level].begin(),root->val);
        }
        travelZig(root->left,ret,level+1);
        travelZig(root->right,ret,level+1);
    }
    
    
public:
    vector<vector<int>> zigzagLevelOrder1(TreeNode* root) {
        vector<vector<int>>  ret;
        travelZig(root,ret,0);
        return ret;
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>  ret;
        if(!root) return ret;
        queue<TreeNode*>  helper;
        helper.push(root);
        bool leftToRight=true;
        while(!helper.empty()){
            int size=helper.size();
            vector<int> tmp(size);
            for(int i=0;i<size;i++){
                TreeNode* t=helper.front();
                helper.pop();
                int index=leftToRight? i:size-1-i;
                tmp[index]=t->val;
                if(t->left){
                    helper.push(t->left);
                }
                if(t->right){
                    helper.push(t->right);
                }
            }
            leftToRight=!leftToRight;
            ret.push_back(tmp);
        }
        
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    vector<int> input={3,9,20,NULL,NULL,15,7};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    vector<vector<int>> ret=so.zigzagLevelOrder1(root);
    for (auto item:ret) {
        for(auto i:item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
