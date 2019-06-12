//
//  main.cpp
//  207. Course Schedule
//
//  Created by admin on 2019/6/12.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<pair<int, int>>& p) {
        //1、直接满足条件
        int m=p.size();
        if(n==0 || m==0){
            return true;
        }
        //2、构建邻接表 入度表
        vector<vector<int>> graph(n);
        vector<int>  indegree(n,0);
        for(auto  item:p){
            graph[item.second].push_back(item.first);
            indegree[item.first]++;
        }
        
        //3、构建起点队列
        queue<int> helper;
        for(int i=0;i<n;i++){
            if(!indegree[i]){
                helper.push(i);
            }
        }
        
        //4、走起
        int count=0;
        while(!helper.empty()){
            int front=helper.front();
            helper.pop();
            count++;
            for(auto i:graph[front]){
                if(--indegree[i]==0){
                    helper.push(i);
                }
            }
            
        }
        
        return count==n;
    }
};

int main(int argc, const char * argv[]) {
    vector<pair<int,int>>  input={{1,0}};
    Solution so=Solution();
    bool ret=so.canFinish(2, input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
