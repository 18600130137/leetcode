//
//  main.cpp
//  _1026. Maximum Difference Between Node and Ancestor
//
//  Created by admin on 2019/4/16.
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
    int maxDiff=0;
    void maxDiffHelper(TreeNode* root,int minVal,int maxVal){
        if(!root->left && !root->right){
            maxDiff=max(maxDiff,maxVal-minVal);
            return;
        }
        if(root->left){
            maxDiffHelper(root->left,min(minVal,root->left->val),max(maxVal,root->left->val));
        }
        
        if(root->right){
            maxDiffHelper(root->right,min(minVal,root->right->val),max(maxVal,root->right->val));
        }
        
        
    }
    
    
public:
    int maxAncestorDiff1(TreeNode* root) {
        if(!root){
            return 0;
        }
        maxDiffHelper(root,root->val,root->val);
        return maxDiff;
    }
    
    int maxAncestorDiff(TreeNode* root,int minVal=100000,int maxVal=0) {
        return root?max(maxAncestorDiff(root->left,min(minVal,root->val),max(maxVal,root->val)),maxAncestorDiff(root->right,min(minVal,root->val),max(maxVal,root->val))):maxVal-minVal;
    }
};



int main(int argc, const char * argv[]) {
    vector<int> input={8,3,10,1,6,NULL,14,NULL,NULL,4,7,13};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    int depth=so.maxAncestorDiff1(root);
    cout<<"The depth is:"<<depth<<endl;
    return 0;
}
