//
//  main.cpp
//  307. Range Sum Query - Mutable
//
//  Created by admin on 2019/7/17.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class SegmentTreeNode{
    
public:
    int start=0,end=0,sum=0;
    SegmentTreeNode *left;
    SegmentTreeNode *right;
    
    
    SegmentTreeNode(int start,int end){
        this->start=start;
        this->end=end;
        left=NULL;
        right=NULL;
        sum=0;
    }
    
};


class NumArray {
private:
    int m=0;
    SegmentTreeNode *root;
    
    SegmentTreeNode*  buildTree(vector<int>& nums,int start,int end){
        if(start>end){
            return NULL;
        }else{
            SegmentTreeNode*  node=new SegmentTreeNode(start,end);
            if(start==end){
                node->sum=nums[start];
            }else{
                int mid=start+(end-start)/2;
                node->left=buildTree(nums,start,mid);
                node->right=buildTree(nums,mid+1,end);
                node->sum=node->left->sum+node->right->sum;
            }
            return node;
        }
    }
    
    void  updateTree(SegmentTreeNode *root,int i,int val){
        if(!root) return;
        if(root->start==root->end){
            root->sum=val;
        }else{
            int mid=root->start+(root->end-root->start)/2;
            if(i<=mid){
                updateTree(root->left,i,val);
            }else{
                updateTree(root->right,i,val);
            }
            //root->sum==(root->left?root->left->sum:0)+(root->right?root->right->sum:0);
            root->sum=root->left->sum+root->right->sum;
        }
    }
    
    int sumRangeTree(SegmentTreeNode *root,int i,int j){
        if(!root){
            return 0;
        }
        if(root->start==i && root->end==j){
            return root->sum;
        }else{
            int mid=root->start+(root->end-root->start)/2;
            if(j<=mid){
                return sumRangeTree(root->left,i,j);
            }else if(i>=mid+1){
                return sumRangeTree(root->right,i,j);
            }else{
                return sumRangeTree(root->left,i,mid)+sumRangeTree(root->right,mid+1,j);
            }
        }
    }
    
    
    
public:
    
    NumArray(vector<int>& nums) {
        m=nums.size();
        if(m==0){
            return;
        }
        root=buildTree(nums,0,nums.size()-1);
        
    }
    
    void update(int i, int val) {
        if(m==0){
            return;
        }
        
        updateTree(root,i,val);
        
    }
    
    int sumRange(int i, int j) {
        if(m==0){
            return 0;
        }
        return sumRangeTree(root,i,j);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={0,9,5,7,3};
    NumArray arr=NumArray(input);
    int ret1=arr.sumRange(4, 4);
    cout<<"The ret1 is:"<<ret1<<endl;
    int ret2=arr.sumRange(2,4);
    cout<<"The ret2 is:"<<ret2<<endl;
    return 0;
}
