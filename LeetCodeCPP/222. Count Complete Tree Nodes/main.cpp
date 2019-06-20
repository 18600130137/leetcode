//
//  main.cpp
//  222. Count Complete Tree Nodes
//
//  Created by admin on 2019/6/20.
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
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int h=0;
        TreeNode *forLeft=root,*forRight=root;
        while(forRight){
            h++;
            forRight=forRight->right;
            forLeft=forLeft->left;
        }
        if(forLeft==NULL){
            return (1<<h)-1;
        }
        
        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};


int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,4,5,6};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    int ret=so.countNodes(root);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
