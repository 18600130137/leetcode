//
//  main.cpp
//  101. Symmetric Tree
//
//  Created by admin on 2019/4/10.
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


class Solution {
private:
    bool isSame(TreeNode*  tree1,TreeNode* tree2){
        if(!tree1 && !tree2){
            return true;
        }
        if(!tree1 || !tree2){
            return false;
        }
        if(tree1->val!=tree2->val){
            return false;
        }
        return isSame(tree1->left,tree2->right) && isSame(tree1->right,tree2->left);
    }
    
public:
    bool isSymmetric1(TreeNode* root) {
        if(!root){
            return true;
        }
        return  isSame(root->left,root->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        queue<TreeNode*> helper;
        helper.push(root->left);
        helper.push(root->right);
        while(!helper.empty()){
            if(helper.size()%2!=0){
                return false;
            }
            TreeNode* t1=helper.front();
            helper.pop();
            TreeNode* t2=helper.front();
            helper.pop();
            if(t1 && t2){
                if(t1->val!=t2->val){
                    return false;
                }else{
                    helper.push(t1->left);
                    helper.push(t2->right);
                    helper.push(t1->right);
                    helper.push(t2->left);
                }
            }else if(t1 || t2){
                return false;
            }
            
        }
        
        return true;
        
    }
};


int main(int argc, const char * argv[]) {
    vector<int> input={1,2,2,3,4,4,3};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    int ret=so.isSymmetric(root);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
