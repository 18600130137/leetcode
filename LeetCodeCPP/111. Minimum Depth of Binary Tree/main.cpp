//
//  main.cpp
//  111. Minimum Depth of Binary Tree
//
//  Created by admin on 2019/4/12.
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
    int minD(TreeNode *root,int level){
        if(root==NULL){
            return  level;
        }
        return  min(minD(root->left,level+1),minD(root->right,level+1));
    }
    
    
public:
    
    int minDepth1(TreeNode* root) {
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }
        if(!root->right){
            return minDepth1(root->left)+1;
        }else if(!root->left){
            return minDepth1(root->right)+1;
        }else{
            return min(minDepth(root->left),minDepth(root->right))+1;
        }
    }
    
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int DL=minDepth(root->left);
        int DR=minDepth(root->right);
        
        return (DL==0 || DR==0)?(DL+DR+1):1+min(DL,DR);
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={3,9,20,NULL,NULL,15,7};
    TreeNode* root= buildTree(input);
    Solution so=Solution();
    int depth=so.minDepth1(root);
    cout<<"The depth is:"<<depth<<endl;
    return 0;
}
