//
//  main.cpp
//  112. Path Sum
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
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root){
            return false;
        }
        sum-=root->val;
        if(!root->left && !root->right){
            return sum==0;
        }
        return hasPathSum(root->left,sum) || hasPathSum(root->right,sum);
    }
};
int main(int argc, const char * argv[]) {
    vector<int>  input={5,4,8,11,NULL,13,4,7,2,NULL,NULL,NULL,1};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    bool  ret=so.hasPathSum(root, 22);
    cout<<"Has  path sum:"<<ret<<endl;
    return 0;
}
