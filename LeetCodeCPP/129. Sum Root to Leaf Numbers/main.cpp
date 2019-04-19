//
//  main.cpp
//  129. Sum Root to Leaf Numbers
//
//  Created by admin on 2019/4/19.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

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
        if(in[start]!=-1){
            f->left=new TreeNode(in[start]);
            helper.push(f->left);
        }
        
        start++;
        if(start>=m){
            break;
        }
        if(in[start]!=-1){
            f->right=new TreeNode(in[start]);
            helper.push(f->right);
        }
        
        start++;
    }
    return root;
}

class Solution {
private:
    int sumHelper(TreeNode* root,int last){
        if(!root){
            return 0;
        }
        last=last*10+root->val;
        if(!root->left && !root->right){
            return last;
        }
        
        return sumHelper(root->left,last)+sumHelper(root->right,last);
        
    }
    
public:
    int sumNumbers(TreeNode* root) {
        return sumHelper(root,0);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={4,9,0,5,1};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    int ret=so.sumNumbers(root);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
