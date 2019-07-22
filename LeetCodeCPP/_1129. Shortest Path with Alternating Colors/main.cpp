//
//  main.cpp
//  _1129. Shortest Path with Alternating Colors
//
//  Created by admin on 2019/7/22.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class  Step{
    
public:
    int node_id;
    int color;
    int step;
    
    Step(int node_id,int color,int step){
        this->node_id=node_id;
        this->color=color;
        this->step=step;
    }
    
};

class Solution {
    
private:
    const int RED=0;
    const int BLUE=1;
    
    void  BFS(vector<unordered_map<int,unordered_set<int>>> &helper,vector<int> &ret,int color){
        queue<Step>  q;
        Step  start(0,color,0);
        q.push(start);
        unordered_set<string>  visited;
        visited.insert(to_string(0)+"#"+to_string(color));
        while(!q.empty()){
            Step tmp=q.front();
            q.pop();
            ret[tmp.node_id]=min(ret[tmp.node_id],tmp.step);
            auto  next=helper[tmp.color][tmp.node_id];
            for(auto s=next.begin();s!=next.end();s++){
                string nextStr=to_string(*s)+"#"+to_string(1-tmp.color);
                if(visited.count(nextStr)==0){
                    visited.insert(nextStr);
                    Step  st(*s,1-tmp.color,tmp.step+1);
                    q.push(st);
                }
                
            }
            
            
        }
        
        
    }
   
    
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int>   ret(n,INT_MAX);
        unordered_map<int,unordered_set<int>> red;
        for(auto r:red_edges){
            red[r[0]].insert(r[1]);
        }
        unordered_map<int,unordered_set<int>> blue;
        for(auto b:blue_edges){
            blue[b[0]].insert(b[1]);
        }
        vector<unordered_map<int,unordered_set<int>>> helper={red,blue};
        BFS(helper,ret,RED);
        BFS(helper,ret,BLUE);
        for(int i=0;i<n;i++){
            if(ret[i]==INT_MAX){
                ret[i]=-1;
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int point_count=5;
    vector<vector<int>> red_line={{0,1},{1,2},{2,3},{3,4}};
    vector<vector<int>> blue_line={{1,2},{2,3},{3,1}};
    
    vector<int> ret=so.shortestAlternatingPaths(5, red_line, blue_line);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
