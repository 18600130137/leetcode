//
//  main.cpp
//  _1203. Sort Items by Groups Respecting Dependencies
//
//  Created by admin on 2019/9/26.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

class Solution {
private:
    map<int,set<int>>  group2Item;
    
    map<int,int>  groupInNum;
    map<int,set<int>>  groupDir;
    
    map<int,int>  itemInNum;
    map<int,set<int>> itemDir;
    
    
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int minGroup=m;
        for(int i=0;i<group.size();i++){
            if(group[i]==-1){
                group[i]=minGroup++;
            }
            group2Item[group[i]].insert(i);
        }
        
        for(int to=0;to<beforeItems.size();to++){
            int toGroup=group[to];
            for(auto from:beforeItems[to]){
                int fromGroup=group[from];
                if(fromGroup==toGroup){
                    itemDir[from].insert(to);
                    itemInNum[to]++;
                }else{
                    if(groupDir[fromGroup].count(toGroup)==0){
                        groupDir[fromGroup].insert(toGroup);
                        groupInNum[toGroup]++;
                    }
                }
            }
        }
        
        vector<int> groupAns;
        queue<int>  helper;
        
        for(int i=0;i<minGroup;i++){
            if(groupInNum[i]==0){
                groupAns.push_back(i);
                helper.push(i);
            }
        }
        
        while(!helper.empty()){
            int front=helper.front();
            helper.pop();
            for(auto  g:groupDir[front]){
                groupInNum[g]--;
                if(groupInNum[g]==0){
                    groupAns.push_back(g);
                    helper.push(g);
                }
            }
        }
        
        
        if(groupAns.size()!=minGroup){
            return {};
        }
        
        ;
        
        vector<int> ans;
        for(auto  g:groupAns){
            auto items=group2Item[g];
            int num=0;
            for(auto  i:items){
                if(itemInNum[i]==0){
                    helper.push(i);
                    ans.push_back(i);
                    num++;
                }
            }
            while(!helper.empty()){
                int itemFront=helper.front();
                helper.pop();
                for(auto  item:itemDir[itemFront]){
                    itemInNum[item]--;
                    if(itemInNum[item]==0){
                        helper.push(item);
                        ans.push_back(item);
                        num++;
                    }
                }
            }
            if(num!=items.size()){
                return {};
            }
            
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    int m=8;
    int n=2;
    vector<int>  p3={-1,-1,1,0,0,1,0,-1};
    vector<vector<int>> p4={{},{6},{5},{6},{3,6},{},{},{}};
    Solution so=Solution();
    vector<int> ret=so.sortItems(m, n, p3,p4);
    for(auto  r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
