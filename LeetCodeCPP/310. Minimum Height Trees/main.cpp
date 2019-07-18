//
//  main.cpp
//  310. Minimum Height Trees
//
//  Created by admin on 2019/7/18.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
    
    
public:
    vector<int> findMinHeightTrees1(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        
        unordered_map<int,unordered_set<int>> helper;
        for(auto e:edges){
            helper[e[0]].insert(e[1]);
            helper[e[1]].insert(e[0]);
        }
        
        vector<int> leaves;
        for(auto h:helper){
            if(h.second.size()==1){
                leaves.push_back(h.first);
            }
        }
        while(n>2){
            n=n-leaves.size();
            vector<int> swap;
            for(auto l:leaves){
                int j=*(helper[l].begin());
                helper[j].erase(l);
                if(helper[j].size()==1){
                    swap.push_back(j);
                }
            }
            leaves=swap;
        }
        
        return leaves;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        
        vector<unordered_set<int>> helper(n);
        for(auto e:edges){
            helper[e[0]].insert(e[1]);
            helper[e[1]].insert(e[0]);
        }
        
        vector<int> leaves;
        for(int i=0;i<n;i++){
            if(helper[i].size()==1){
                leaves.push_back(i);
            }
        }
        while(n>2){
            n=n-leaves.size();
            vector<int> swap;
            for(auto l:leaves){
                int j=*(helper[l].begin());
                helper[j].erase(l);
                if(helper[j].size()==1){
                    swap.push_back(j);
                }
            }
            leaves=swap;
        }
        
        return leaves;
    }};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<vector<int>> input={{1,0},{1,2},{1,3}};
    vector<int> ret=so.findMinHeightTrees(4,input);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
