//
//  main.cpp
//  105. Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildHelper(vector<int>& preorder, vector<int>& inorder,int pl,int pr,int il,int ir){
        if(pl>pr){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[pl]);
        int pos=0;
        for(int i=il;i<=ir;i++){
            if(inorder[i]==preorder[pl]){
                pos=i;
                break;
            }
        }
        root->left=buildHelper(preorder,inorder,pl+1,pl+pos-il,il,pos-1);
        root->right=buildHelper(preorder,inorder,pl+pos-il+1,pr,pos+1,ir);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildHelper(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input1={3,9,20,15,7};
    vector<int> input2={9,3,15,20,7};
    Solution so=Solution();
    TreeNode* ret=so.buildTree(input1, input2);
    traversalTree(ret);
    return 0;
}
