//
//  main.cpp
//  235. Lowest Common Ancestor of a Binary Search Tree
//
//  Created by admin on 2019/6/26.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
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
public:
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        while(true){
            if(root->val<min(p->val,q->val)){
                root=root->right;
            }else if(root->val>max(p->val,q->val)){
                root=root->left;
            }else{
                return root;
            }
        }
        
        
    }
};


int main(int argc, const char * argv[]) {
    vector<int> input={6,2,8,0,4,7,9,NULL,NULL,3,5};
    TreeNode* root= buildTree(input);
    Solution so=Solution();
    TreeNode * ret=so.lowestCommonAncestor(root, root->left, root->right);
    cout<<"The ret node value is:"<<ret->val<<endl;
    return 0;
}
