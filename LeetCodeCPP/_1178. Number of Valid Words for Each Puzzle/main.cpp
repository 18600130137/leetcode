//
//  main.cpp
//  _1178. Number of Valid Words for Each Puzzle
//
//  Created by admin on 2019/9/6.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;


const int  SIZE=26;

struct  TireNode{
    TireNode *childrens[SIZE];
    int count=0;
};



class Solution {
private:
    TireNode* getNode(){
        TireNode *node=new TireNode();
        for(int i=0;i<SIZE;i++){
            node->childrens[i]=nullptr;
        }
        node->count=0;
        return node;
    }
    
    void   insert(TireNode *root,set<char> &str){
        TireNode *cur=root;
        for(auto  c:str){
            int idx=c-'a';
            if(!cur->childrens[idx]){
                cur->childrens[idx]=getNode();
            }
            cur=cur->childrens[idx];
        }
        cur->count++;
    }
    
    int   search(TireNode *root,string puzzle,bool  findFirst,char first){
        if(!root){
            return 0;
        }
        int count=0;
        if(findFirst){
            count+=root->count;
        }
        for(auto  p:puzzle){
            int idx=p-'a';
            if(p==first){
                count+=search(root->childrens[idx],puzzle,true,first);
            }else{
                count+=search(root->childrens[idx],puzzle,findFirst,first);
            }
        }
        return count;
    }
    
    
    
    
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        TireNode* root=getNode();
        for(auto  w:words){
            set<char>  tmp(w.begin(),w.end());
            if(tmp.size()>7) continue;
            insert(root,tmp);
        }
        
        vector<int> ret;
        for(auto p:puzzles){
            ret.push_back(search(root,p,false,p[0]));
        }
        
        return ret;
        
    }
};


int main(int argc, const char * argv[]) {
    vector<string> input1={"aaaa","asas","able","ability","actt","actor","access"};
    vector<string> input2={"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
    Solution so=Solution();
    vector<int> searchRet=so.findNumOfValidWords(input1, input2);
    for(auto s:searchRet){
        cout<<s<<" ";
    }
    cout<<endl;
    return 0;
}
