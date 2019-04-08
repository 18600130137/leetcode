//
//  main.cpp
//  94. Binary Tree Inorder Traversal
//
//  Created by admin on 2019/4/8.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root){
            return ret;
        }
        stack<TreeNode*> helper;
        while(root!=NULL || !helper.empty()){
            while(root!=NULL){
                helper.push(root);
                root=root->left;
            }
            TreeNode* tmp=helper.top();
            helper.pop();
            ret.push_back(tmp->val);
            if(tmp->right){
                root=tmp->right;
            }
        }
        
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={1,NULL,2,3};
    TreeNode * root=buildTree(input);
    Solution so=Solution();
    vector<int>  ret=so.inorderTraversal(root);
    for(auto i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
