//
//  main.cpp
//  _1028. Recover a Tree From Preorder Traversal
//
//  Created by admin on 2019/4/16.
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
    TreeNode* recoverFromPreorder(string S) {
        int m=S.size();
        stack<TreeNode*> helper;
        for(int i=0;i<m;){
            int depth=0,val=0;
            while(S[i]=='-'){
                depth++;
                i++;
            }
            while(i<m && S[i]!='-'){
                val=val*10+(S[i]-'0');
                i++;
            }
            //cout<<i<<" "<<depth<<" "<<val<<" "<<helper.size()<<endl;
            TreeNode* tmp=new TreeNode(val);
            while(depth<helper.size()){
                helper.pop();
            }
            if(!helper.empty()){
                if(!helper.top()->left){
                    helper.top()->left=tmp;
                }else{
                    helper.top()->right=tmp;
                }
            }
            
            helper.push(tmp);
        }
        
        while(helper.size()>1){
            helper.pop();
        }
        return helper.top();
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    TreeNode* ret=so.recoverFromPreorder("1-2--3--4-5--6--7");
    traversalTree(ret);
    return 0;
}
