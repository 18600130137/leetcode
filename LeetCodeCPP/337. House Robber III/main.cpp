//
//  main.cpp
//  337. House Robber III
//
//  Created by admin on 2019/8/16.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int robGo(TreeNode *root,unordered_map<TreeNode*,int> &helper) {
        if (root == NULL) return 0;
        if(helper.count(root)){
            return helper[root];
        }
        
        int val = 0;
        
        if (root->left != NULL) {
            val += robGo(root->left->left,helper) + robGo(root->left->right,helper);
        }
        
        if (root->right != NULL) {
            val += robGo(root->right->left,helper) + robGo(root->right->right,helper);
        }
        int bigger=max(val + root->val, robGo(root->left,helper) + robGo(root->right,helper));
        helper[root]=bigger;
        return bigger;
    }
    
    vector<int>  robSuper(TreeNode* root){
        if(!root)  return vector(2,0);
        vector<int> left=robSuper(root->left);
        vector<int> right=robSuper(root->right);
        vector<int> res(2,0);
        res[0]=max(left[0],left[1])+max(right[0],right[1]);
        res[1]=root->val+left[0]+right[0];
        
        return res;
    }
    
    
public:
    int rob1(TreeNode* root) {
        unordered_map<TreeNode*,int> helper;
        return robGo(root,helper);
    }
    
    int rob(TreeNode* root) {
        vector<int> ret=robSuper(root);
        return max(ret[0],ret[1]);
    }
};
int main(int argc, const char * argv[]) {
    vector<int>  input={3,2,3,NULL,3,NULL,1};
    return 0;
}
