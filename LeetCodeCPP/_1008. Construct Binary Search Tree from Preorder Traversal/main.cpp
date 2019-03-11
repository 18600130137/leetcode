//
//  main.cpp
//  _1008. Construct Binary Search Tree from Preorder Traversal
//
//  Created by admin on 2019/3/11.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


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



class Solution {
private:
    int i=0;
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder,int bound=INT_MAX) {
        if(i==preorder.size() || preorder[i]>bound){
            return NULL;
        }
        TreeNode * tree=new TreeNode(preorder[i++]);
        tree->left=bstFromPreorder(preorder,tree->val);
        tree->right=bstFromPreorder(preorder,bound);
        return  tree;
        
    }
};


int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<int> input={8,5,1,7,10,12};
    TreeNode * ret=so.bstFromPreorder(input);
    traversalTree(ret);
    return 0;
}
