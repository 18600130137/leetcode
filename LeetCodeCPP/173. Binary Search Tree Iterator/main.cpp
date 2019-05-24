//
//  main.cpp
//  173. Binary Search Tree Iterator
//
//  Created by admin on 2019/5/24.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
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




class BSTIterator {
private:
    stack<TreeNode*> helper;
    
    void  pushAll(TreeNode* tree){
        for(;tree!=NULL;helper.push(tree),tree=tree->left);
    }
    
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    /** @return the next smallest number */
    int next() {
        if(!hasNext()){
            return -1;
        }
        TreeNode* top=helper.top();
        helper.pop();
        if(top->right){
            pushAll(top->right);
        }
        
        return top->val;
        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !helper.empty();
    }
};

//["BSTIterator","next","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]
//[[[7,3,15,null,null,9,20]],[null],[null],[null],[null],[null],[null],[null],[null],[null]]

void  excutor(TreeNode* root,vector<string> order){
    BSTIterator* obj;
    for(auto s:order){
        if(s=="BSTIterator"){
            obj=new BSTIterator(root);
            cout<<"Init"<<endl;
        }else if(s=="next"){
            cout<<"next=="<<obj->next()<<endl;
        }else if(s=="hasNext"){
            cout<<"hasNext=="<<obj->hasNext()<<endl;
        }
    }
}



int main(int argc, const char * argv[]) {
    vector<int> input={7,3,15,NULL,NULL,9,20};
    TreeNode *root=buildTree(input);
    vector<string> orderList={"BSTIterator","next","next","hasNext","next","hasNext","next","hasNext","next","hasNext"};
    excutor(root, orderList);
    return 0;
}
