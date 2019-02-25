//
//  main.cpp
//  998. Maximum Binary Tree II
//
//  Created by admin on 2019/2/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root && root->val>val){
            root->right=insertIntoMaxTree(root->right,val);
            return root;
        }
        TreeNode *newNode=new TreeNode(val);
        newNode->left=root;
        return newNode;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int> inputV={5,2,3,NULL,1};
    TreeNode* input1=buildTree(inputV);
    int input2=4;
    Solution so=Solution();
    TreeNode* ret=so.insertIntoMaxTree(input1, input2);
    traversalTree(ret);
    return 0;
}
