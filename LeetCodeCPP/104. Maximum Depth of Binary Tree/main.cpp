//
//  main.cpp
//  104. Maximum Depth of Binary Tree
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
public:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        return 1+max(maxDepth(root->left),maxDepth(root->right));
        
    }
    
    int maxDepth1(TreeNode* root) {
        if(!root){
            return 0;
        }
        int depth=0;
        queue<TreeNode*>  helper;
        helper.push(root);
        while(!helper.empty()){
            int size=helper.size();
            for(int i=0;i<size;i++){
                TreeNode* t=helper.front();
                helper.pop();
                if(t->left){
                    helper.push(t->left);
                }
                if(t->right){
                    helper.push(t->right);
                }
            }
            depth++;
        }
        
        return depth;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={3,9,20,NULL,NULL,15,7};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    int depth=so.maxDepth1(root);
    cout<<"The max depth is:"<<depth<<endl;
    return 0;
}
