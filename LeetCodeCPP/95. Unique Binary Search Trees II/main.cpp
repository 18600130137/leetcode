//
//  main.cpp
//  95. Unique Binary Search Trees II
//
//  Created by admin on 2019/4/8.
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
private:
    vector<TreeNode*>  helper(int left,int right){
        vector<TreeNode*> ret;
        if(left>right){
            ret.push_back(NULL);
            return ret;
        }
        for(int i=left;i<=right;i++){
            vector<TreeNode*> leftNodes=helper(left,i-1);
            vector<TreeNode*> rightNodes=helper(i+1,right);
            for(auto l:leftNodes){
                for(auto r:rightNodes){
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    ret.push_back(root);
                }
            }
        }
        
        return ret;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n<=0){
            return {};
        }
        
        return helper(1,n);
    }
};


int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<TreeNode*> ret=so.generateTrees(3);
    for(auto t:ret){
        traversalTree(t);
        cout<<endl;
    }
    return 0;
}
