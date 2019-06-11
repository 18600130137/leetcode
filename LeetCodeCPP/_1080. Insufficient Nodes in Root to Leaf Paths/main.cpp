//
//  main.cpp
//  _1080. Insufficient Nodes in Root to Leaf Paths
//
//  Created by admin on 2019/6/11.
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

void traversalTree(TreeNode*  root,int level=0){
    queue<TreeNode*> helper;
    helper.push(root);
    helper.push(NULL);
    int add_more=0;
    while (!helper.empty()) {
        auto f=helper.front();
        helper.pop();
        if(f==NULL){
            level++;
            if (add_more>0){
                helper.push(NULL);
                add_more=0;
            }
        }else{
            cout<<"Traversal val:"<<f->val<<" level:"<<level<<endl;
            if(f->left){
                add_more++;
                helper.push(f->left);
            }
            if(f->right){
                add_more++;
                helper.push(f->right);
            }
            
        }
        
    }
}

class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(root->left==root->right){
            return root->val>=limit?root:NULL;
        }
        if(root->left){
            root->left=sufficientSubset(root->left,limit-root->val);
        }
        if(root->right){
            root->right=sufficientSubset(root->right,limit-root->val);
        }
        return root->left==root->right?NULL:root;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14};
    TreeNode *root=buildTree(input);
    Solution so=Solution();
    TreeNode *ret=so.sufficientSubset(root, 1);
    traversalTree(ret);
    return 0;
}
