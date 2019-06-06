//
//  main.cpp
//  199. Binary Tree Right Side View
//
//  Created by admin on 2019/6/6.
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
    void rightSearch(TreeNode* root,vector<int> &ret,int level){
        if(!root){
            return;
        }
        if(ret.size()==level){
            ret.push_back(root->val);
        }
        rightSearch(root->right,ret,level+1);
        rightSearch(root->left,ret,level+1);
        
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        rightSearch(root,ret,0);
        return ret;
    }
};



int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,NULL,5,NULL,4};
    TreeNode * root=buildTree(input);
    Solution so=Solution();
    vector<int> ret=so.rightSideView(root);
    for(auto item:ret){
        cout<<item<<" ";
    }
    cout<<endl;
    return 0;
}
