//
//  main.cpp
//  108. Convert Sorted Array to Binary Search Tree
//
//  Created by admin on 2019/4/11.
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
private:
    TreeNode*  createBST(vector<int>& nums,int start,int end){
        if(start>end){
            return NULL;
        }
        int mid=(start+end)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=createBST(nums,start,mid-1);
        root->right=createBST(nums,mid+1,end);
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return  createBST(nums,0,nums.size()-1);
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input={-10,-3,0,5,9};
    Solution so=Solution();
    TreeNode* ret=so.sortedArrayToBST(input);
    traversalTree(ret);
    return 0;
}
