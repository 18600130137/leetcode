//
//  main.cpp
//  110. Balanced Binary Tree
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
    bool  result=true;
    
    int  searchMaxDeep(TreeNode* root,int level){
        if(root==NULL){
            return level;
        }
        int left=searchMaxDeep(root->left,level+1);
        int right=searchMaxDeep(root->right,level+1);
        if(abs(left-right)>1){
            result=false;
        }
        return  max(left,right);
    }
    
    int depth(TreeNode* root){
        if(!root){
            return 0;
        }
        int DL=depth(root->left);
        if(DL==-1){
            return -1;
        }
        int DR=depth(root->right);
        if(DR==-1){
            return -1;
        }
        if(abs(DL-DR)>1){
            return -1;
        }
        return 1+max(DL,DR);
        
    }public:
  
    
    bool isBalanced1(TreeNode* root) {
        if(!root){
            return result;
        }
        searchMaxDeep(root,0);
        return result;
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        return depth(root)!=-1;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={3,9,20,NULL,NULL,15,7};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    bool ret=so.isBalanced1(root);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
