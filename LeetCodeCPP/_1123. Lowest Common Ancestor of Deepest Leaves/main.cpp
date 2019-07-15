//
//  main.cpp
//  _1123. Lowest Common Ancestor of Deepest Leaves
//
//  Created by admin on 2019/7/15.
//  Copyright © 2019年 liu. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;
#include <queue>
#include <unordered_set>
#include <sstream>

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
private:
    int depth(TreeNode* root){
        if(!root){
            return 0;
        }
        return max(depth(root->left),depth(root->right))+1;
    }
    
    TreeNode*  helper(TreeNode * root,int index,int maxDepth){
        if(!root){
            return root;
        }
        if(index==maxDepth){
            return root;
        }
        TreeNode * left=helper(root->left,index+1,maxDepth);
        TreeNode * right=helper(root->right,index+1,maxDepth);
        if(left && right){
            return root;
        }
        if(left){
            return left;
        }
        return right;
    }
    
    
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxDepth=depth(root);
        return helper(root,0,maxDepth-1);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,4,5};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    TreeNode* rootO=so.lcaDeepestLeaves(root);
    traversalTree(rootO);
    return 0;
}
