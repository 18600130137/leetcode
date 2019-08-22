//
//  main.cpp
//  352. Data Stream as Disjoint Intervals
//
//  Created by admin on 2019/8/22.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class SummaryRanges {
private:
    map<int,vector<int>>  tree;
    
    int lowerKey(map<int,vector<int>>  tree,int key){
        auto lowerIter=tree.lower_bound(key);
        if(lowerIter==tree.begin()){
            return -1;
        }
        
        return (--lowerIter)->first;
    }
    
    int upperKey(map<int,vector<int>>  tree,int key){
        auto upperIter=tree.upper_bound(key);
        if(upperIter==tree.end()){
            return -1;
        }
        return upperIter->first;
    }
    
    
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if(tree.count(val)) return;
        int l=lowerKey(tree,val);
        int r=upperKey(tree,val);
        if(l!=-1 && r!=-1 && tree[l][1]+1==val && val+1==r){
            tree[l][1]=tree[r][1];
            tree.erase(r);
        }else if(l!=-1 && tree[l][1]+1>=val){
            tree[l][1]=max(tree[l][1],val);
        }else if(r!=-1 && val+1==r){
            tree[val]={val,tree[r][1]};
            tree.erase(r);
        }else{
            tree[val]={val,val};
        }
        
        
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;
        for(auto t:tree){
            ret.push_back(t.second);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    SummaryRanges* obj = new SummaryRanges();
    obj->addNum(5);
    vector<vector<int>> param_2 = obj->getIntervals();
    for(auto p:param_2){
        cout<<p[0]<<" "<<p[1]<<endl;
    }
    obj->addNum(6);
    vector<vector<int>> param_3 = obj->getIntervals();
    for(auto p:param_3){
        cout<<p[0]<<" "<<p[1]<<endl;
    }    return 0;
}
