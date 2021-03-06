//
//  main.cpp
//  297. Serialize and Deserialize Binary Tree
//
//  Created by admin on 2019/7/10.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
#include <queue>
#include <unordered_set>
#include <sstream>

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

class Codec {
private:
    void  helperWrite(TreeNode* root,ostringstream &oss){
        if(!root){
            oss<<"# ";
        }else{
            oss<<root->val<<' ';
            helperWrite(root->left,oss);
            helperWrite(root->right,oss);
        }
    }
    
    TreeNode* helperRead(istringstream &oss){
        string next;
        oss>>next;
        if(next=="#"){
            return NULL;
        }else{
            TreeNode * root=new TreeNode(stoi(next));
            root->left=helperRead(oss);
            root->right=helperRead(oss);
            return root;
        }
    }
    
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        helperWrite(root,oss);
        return oss.str();
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return helperRead(iss);
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,NULL,NULL,4,5};
    TreeNode*  root=buildTree(input);
    Codec codec;
    string tmp=codec.serialize(root);
    cout<<"The tmp is:"<<tmp<<endl;
    TreeNode* ret=codec.deserialize(tmp);
    traversalTree(ret);
    return 0;
}
