//
//  main.cpp
//  _1145. Binary Tree Coloring Game
//
//  Created by admin on 2019/8/5.
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
    int left,right,val;
    
    TreeNode* findRed(TreeNode* root,int x){
        TreeNode* ret=NULL;
        if(root){
            if(root->val==x){
                ret=root;
            }else{
                TreeNode* tmp=findRed(root->left,x);
                if(tmp){
                    return tmp;
                }
                ret=findRed(root->right,x);
            }
        }
        return ret;
    }
    
    int  countNode(TreeNode* root){
        if(!root){
            return 0;
        }
        return countNode(root->left)+countNode(root->right)+1;
    }
    
    int countAll(TreeNode* root){
        if(!root){
            return 0;
        }
        int l=countAll(root->left);
        int r=countAll(root->right);
        if(root->val==val){
            left=l,right=r;
        }
        return l+r+1;
    }
    
public:
    bool btreeGameWinningMove1(TreeNode* root, int n, int x) {
        TreeNode* red=findRed(root,x);
        int leftCount=countNode(red->left);
        int rightCount=countNode(red->right);
        int blueMax=max(n-leftCount-rightCount-1,max(leftCount,rightCount));
        
        return blueMax>n/2;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        val=x;
        countAll(root);
        return max(n-left-right-1,max(left,right))>n/2;
    }
};


int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,4,5,6,7,8,9,10,11};
    TreeNode* root=buildTree(input);
    Solution so=Solution();
    bool ret=so.btreeGameWinningMove(root, 11,3);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
