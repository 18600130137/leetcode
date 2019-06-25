//
//  main.cpp
//  230. Kth Smallest Element in a BST
//
//  Created by admin on 2019/6/25.
//  Copyright © 2019年 liu. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
    int count=0;
    int ret=0;
    
    void helper(TreeNode* root){
        if(root->left){
            helper(root->left);
        }
        count--;
        if(count==0){
            ret=root->val;
            return;
        }
        if(root->right){
            helper(root->right);
        }
    }
    
    int nodeCount(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1+nodeCount(root->left)+nodeCount(root->right);
    }
    
public:
    int kthSmallest3(TreeNode* root, int k) {
        count=k;
        helper(root);
        return ret;
    }
    
    int kthSmallest2(TreeNode* root, int k) {
        int leftCount=nodeCount(root->left);
        if(k<=leftCount){
            return kthSmallest(root->left,k);
        }else if(k>leftCount+1){
            return kthSmallest(root->right,k-leftCount-1);
        }
        return root->val;
    }
    
    int kthSmallest1(TreeNode* root, int k) {
        stack<TreeNode*> helper;
        while(root){
            helper.push(root);
            root=root->left;
        }
        while(!helper.empty()){
            TreeNode*  top=helper.top();
            helper.pop();
            k--;
            if(k==0){
                return top->val;
            }
            if(top->right){
                top=top->right;
                while(top){
                    helper.push(top);
                    top=top->left;
                }
            }
        }
        return -1;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> helper;
        while(root || !helper.empty()){
            while(root){
                helper.push(root);
                root=root->left;
            }
            TreeNode* top=helper.top();
            helper.pop();
            k--;
            if(k==0){
                return  top->val;
            }
            root=top->right;
        }
        return -1;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={5,3,6,2,4,NULL,NULL,1};
    TreeNode *root=buildTree(input);
    Solution so=Solution();
    int ret=so.kthSmallest(root, 3);
    cout<<"The  ret is:"<<ret<<endl;
    return 0;
}
