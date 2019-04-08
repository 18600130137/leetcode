//
//  main.cpp
//  _1022. Sum of Root To Leaf Binary Numbers
//
//  Created by admin on 2019/4/8.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
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
//        if(in[start]){
//            f->left=new TreeNode(in[start]);
//            helper.push(f->left);
//        }
        f->left=new TreeNode(in[start]);
        helper.push(f->left);
        
        start++;
        if(start>=m){
            break;
        }
//        if(in[start]){
//            f->right=new TreeNode(in[start]);
//            helper.push(f->right);
//        }
        f->right=new TreeNode(in[start]);
        helper.push(f->right);
        
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
    int mode=pow(2,31)-1;
    
public:
    int sumRootToLeaf(TreeNode* root,int val=0) {
        int cur=(2*val+root->val)%mode;
        if(!root->left && !root->right){
            return cur;
        }

        return (root->left?sumRootToLeaf(root->left,cur):0)+(root->right?sumRootToLeaf(root->right,cur):0);
        
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input={1,0,1,0,1,0,1};
    TreeNode* root=buildTree(input);
    traversalTree(root);
    Solution so=Solution();
    int ret=so.sumRootToLeaf(root);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
