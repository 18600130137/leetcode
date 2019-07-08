//
//  main.cpp
//  _1110. Delete Nodes And Return Forest
//
//  Created by admin on 2019/7/8.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
#include <queue>
#include <unordered_set>

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
    TreeNode* helper(TreeNode* tree,bool isRoot,unordered_set<int> &set,vector<TreeNode*> &ret){
        if(!tree){
            return NULL;
        }
        bool  isDeleted=(set.count(tree->val)>0);
        if(isRoot && !isDeleted){
            ret.push_back(tree);
        }
        tree->left=helper(tree->left,isDeleted,set,ret);
        tree->right=helper(tree->right,isDeleted,set,ret);
        return isDeleted? NULL:tree;
    }
    
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> set;
        vector<TreeNode*> ret;
        for(auto d:to_delete){
            set.insert(d);
        }
        helper(root,true,set,ret);
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,4,5,6,7};
    TreeNode* root=buildTree(input);
    vector<int> deletedList={3,5};
    Solution so=Solution();
    vector<TreeNode*> ret=so.delNodes(root, deletedList);
    for(auto r:ret){
        traversalTree(r);
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
