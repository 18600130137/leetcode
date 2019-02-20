//
//  main.cpp
//  993. Cousins in Binary Tree
//
//  Created by admin on 2019/2/20.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
#include <queue>

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
    TreeNode* searchParentDepth(TreeNode* current,int search_val,int &depth){
        
        if(current->left!=NULL){
            if(current->left->val==search_val){
                return current;
            }else{
                depth+=1;
                TreeNode* parent=searchParentDepth(current->left,search_val,depth);
                if(!parent){
                    depth-=1;
                }else{
                    return parent;
                }
            }
        }
        if(current->right!=NULL){
            if(current->right->val==search_val){
                return current;
            }else{
                depth+=1;
                TreeNode* parent=searchParentDepth(current->right,search_val,depth);
                if(!parent){
                    depth-=1;
                }else{
                    return parent;
                }
                
            }
        }
        
        return NULL;
        
    }
    
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        bool  siblings=false;
        bool cousins=false;
        queue<TreeNode*>  q1,q2;
        q1.push(root);
        while(!q1.empty() && !cousins){
            while(!q1.empty()){
                auto f=q1.front();
                q1.pop();
                if(f!=nullptr){
                    if(f->val==x || f->val==y){
                        if(!cousins){
                            cousins=siblings=true;
                        }else{
                            return !siblings;
                        }
                    }
                    q2.push(f->left);
                    q2.push(f->right);
                    q2.push(nullptr);
                }else{
                    siblings=false;
                }
            }
            swap(q1,q2);
            
        }
        
        return false;
        
        
    }
};




int main(int argc, const char * argv[]) {
    vector<int>  vin={1,2,3,NULL,4,NULL,5};
    int in1=4,in2=5;
    TreeNode* input=buildTree(vin);
    traversalTree(input);
    Solution so=Solution();
    auto ret=so.isCousins(input,in1,in2);
    cout<<"最终计算结果为："<<ret<<endl;
    return 0;
}
