//
//  main.cpp
//  113. Path Sum II
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
    void  searchPath(TreeNode* root,vector<int> &curPath,int cur_sum,vector<vector<int>> &ret){
        curPath.push_back(root->val);
        cur_sum-=root->val;
        
        if(root->left==NULL && root->right==NULL){
            if(cur_sum==0){
                ret.push_back(curPath);
            }
        }else{
            if(root->left!=NULL){
                searchPath(root->left,curPath,cur_sum,ret);
            }
            
            if(root->right!=NULL){
                searchPath(root->right,curPath,cur_sum,ret);
            }
        }
        
        cur_sum+=root->val;
        curPath.pop_back();
    }
    
    void pathHelper(TreeNode* root, int sum,vector<vector<int>>  &ret,vector<int>  &tmp){
        if(!root) return;
        sum-=root->val;
        tmp.push_back(root->val);
        if(!root->left && !root->right){
            if(sum==0){
                ret.push_back(tmp);
            }
        }
        pathHelper(root->left,sum,ret,tmp);
        pathHelper(root->right,sum,ret,tmp);
        
        sum+=root->val;
        tmp.pop_back();
    }
public:
    
    
    vector<vector<int>> pathSum1(TreeNode* root, int sum) {
        vector<vector<int>>  ret;
        vector<int>  tmp;
        if(root!=NULL){
            searchPath(root,tmp,sum,ret);
        }
        return ret;
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>  ret;
        vector<int>  tmp;
        pathHelper(root,sum,ret,tmp);
        return ret;
    }
    
};

int main(int argc, const char * argv[]) {
    vector<int> input={5,4,8,11,NULL,13,4,7,2,NULL,NULL,5,1};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    vector<vector<int>> ret=so.pathSum(root, 22);
    for(auto item:ret){
        for(auto i:item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
