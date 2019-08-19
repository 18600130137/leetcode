//
//  main.cpp
//  1162. As Far from Land as Possible
//
//  Created by admin on 2019/8/19.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    vector<pair<int,int>>  surround={{-1,0},{1,0},{0,-1},{0,1}};
    
    
    void  dfs(vector<vector<int>>& grid,int i,int j,int step,bool isLand,int m,int n){
        if(!isLand){
            if(i<0 || i>=m || j<0 || j>=n || (grid[i][j]>0 && grid[i][j]<=step)){
                return;
            }
            grid[i][j]=step;
        }
        dfs(grid,i-1,j,step+1,false,m,n);
        dfs(grid,i+1,j,step+1,false,m,n);
        dfs(grid,i,j-1,step+1,false,m,n);
        dfs(grid,i,j+1,step+1,false,m,n);
        
    }
    
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,1,true,m,n);
                }
            }
        }
        int ret=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>1){
                    ret=max(ret,grid[i][j]-1);
                }
            }
        }
        
        return ret;
    }
    
    int maxDistance1(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        
        queue<pair<int,int>> helper;
        vector<vector<bool>>  visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    helper.push(make_pair(i,j));
                    visited[i][j]=true;
                }
            }
        }
        int level=-1;
        while(!helper.empty()){
            int len=helper.size();
            for(int i=0;i<len;i++){
                pair<int,int> front=helper.front();
                helper.pop();
                for(auto s:surround){
                    int s1=front.first+s.first;
                    int s2=front.second+s.second;
                    if(s1>=0 && s1<m && s2>=0 && s2<n && !visited[s1][s2]&& grid[s1][s2]==0){
                        helper.push(make_pair(s1,s2));
                        visited[s1][s2]=true;
                    }
                    
                }
            }
            level++;
        }
        
        
        return level<=0?-1:level;
        
    }};
int main(int argc, const char * argv[]) {
    vector<vector<int>> input={{1,0,0},{0,0,0},{0,0,0}};
    Solution so=Solution();
    int ret=so.maxDistance1(input);
    cout<<"The max step is:"<<ret<<endl;
}
