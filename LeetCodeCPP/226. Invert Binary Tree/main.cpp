//
//  main.cpp
//  226. Invert Binary Tree
//
//  Created by admin on 2019/6/21.
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
    TreeNode*   invertTree(TreeNode* root){
        if(root==NULL){
            return root;
        }
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
    
    
    TreeNode* invertTree1(TreeNode* root) {
        if(!root)  return root;
        queue<TreeNode*>  q;
        q.push(root);
        while(q.size()>0){
            TreeNode* tmpNode=q.front();
            q.pop();
            auto tmp=tmpNode->left;
            tmpNode->left=tmpNode->right;
            tmpNode->right=tmp;
            if(tmpNode->left)  q.push(tmpNode->left);
            if(tmpNode->right) q.push(tmpNode->right);
        }
        return  root;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={4,7,2,9,6,3,1};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    TreeNode * ret=so.invertTree(root);
    traversalTree(ret);
    
    return 0;
}
