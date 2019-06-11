//
//  main.cpp
//  124. Binary Tree Maximum Path Sum
//
//  Created by admin on 2019/4/18.
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
    int maxPath=INT_MIN;
    int pathDepth(TreeNode* root){
        if(!root){
            return 0;
        }
        int left=max(0,pathDepth(root->left));
        int right=max(0,pathDepth(root->right));
        maxPath=max(maxPath,left+right+root->val);
        return max(left,right)+root->val;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        pathDepth(root);
        return maxPath;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={-10,9,20,NULL,NULL,15,7};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    int ret=so.maxPathSum(root);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
