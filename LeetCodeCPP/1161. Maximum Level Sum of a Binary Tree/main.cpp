//
//  main.cpp
//  1161. Maximum Level Sum of a Binary Tree
//
//  Created by admin on 2019/8/19.
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
private:
    vector<int>  sums;
    
    void dfs(TreeNode* root,int level){
        if(!root) return;
        if(sums.size()<level){
            sums.resize(level);
        }
        sums[level-1]+=root->val;
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    
    
public:
    int maxLevelSum(TreeNode* root) {
        dfs(root,1);
        int res=0;
        for(int i=1;i<sums.size();i++){
            if(sums[i]>sums[res]){
                res=i;
            }
        }
        return res+1;
    }
};


int main(int argc, const char * argv[]) {
    vector<int> input={1,7,0,7,-8,NULL,NULL};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    int idx=so.maxLevelSum(root);
    cout<<"The ret idx is:"<<idx<<endl;
    return 0;
}
