//
//  main.cpp
//  210. Course Schedule II
//
//  Created by admin on 2019/6/13.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        int m=p.size();
        vector<int> ret;
        if(m==0){
            for(int i=0;i<n;i++){
                ret.push_back(i);
            }
            return ret;
        }
        vector<vector<int>> graph(n);
        vector<int>  indegree(n,0);
        for(auto  v:p){
            graph[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        queue<int> helper;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                helper.push(i);
            }
        }
        int count=0;
        while(!helper.empty()){
            int front=helper.front();
            helper.pop();
            count++;
            ret.push_back(front);
            for(auto  item:graph[front]){
                if(--indegree[item]==0){
                    helper.push(item);
                }
            }
        }
        vector<int>  empty;
        return (count==n)?ret:empty;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> input={{1,0},{2,0},{3,1},{3,2}};
    Solution so=Solution();
    vector<int> ret=so.findOrder(4, input);
    for(auto i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
