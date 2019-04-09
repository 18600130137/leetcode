//
//  main.cpp
//  100. Same Tree
//
//  Created by admin on 2019/4/9.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

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
public:
    
    bool isSameTree1(TreeNode* p, TreeNode* q) {
        if(!p&&!q){
            return true;
        }
        stack<TreeNode*> ts;
        ts.push(q);
        ts.push(p);
        while(!ts.empty()){
            TreeNode* p_tmp=ts.top();
            ts.pop();
            TreeNode* q_tmp=ts.top();
            ts.pop();
            if(p_tmp&&q_tmp){
                if(p_tmp->val!=q_tmp->val){
                    return false;
                }
                ts.push(p_tmp->left);
                ts.push(q_tmp->left);
                ts.push(p_tmp->right);
                ts.push(q_tmp->right);
            }
            else if(p_tmp||q_tmp){
                return false;
            }
        }
        return true;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p && q){
            if(p->val!=q->val){
                return false;
            }
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }else if(p || q){
            return false;
        }else{
            return true;
        }
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input1={1,2,1};
    vector<int> input2={1,1,2};
    TreeNode* t1=buildTree(input1);
    TreeNode* t2=buildTree(input2);
    Solution so=Solution();
    bool ret=so.isSameTree1(t1, t2);
    cout<<"Is same tree==="<<ret<<endl;
    return 0;
}
