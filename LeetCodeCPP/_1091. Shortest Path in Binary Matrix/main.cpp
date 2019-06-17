//
//  main.cpp
//  _1091. Shortest Path in Binary Matrix
//
//  Created by admin on 2019/6/17.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    bool  check(vector<vector<int>>& grid,int i,int j,int n){
        if(i>=0 && i<n && j>=0 && j<n && grid[i][j]==0){
            return true;
        }
        return false;
    }
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0){
            return 0;
        }
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        queue<vector<int>>  helper;
        helper.push({0,0,1});
        grid[0][0]=1;
        vector<vector<int>> surround={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        //vector<vector<int>> surround={{1,0},{0,1},{1,1}};
        while(!helper.empty()){
            vector<int> front=helper.front();
            helper.pop();
            for(auto  s:surround){
                int i=front[0]+s[0],j=front[1]+s[1];
                if(check(grid,i,j,n)){
                    if(i==n-1 && j==n-1){
                        return front[2]+1;
                    }
                    grid[i][j]=1;
                    helper.push({i,j,front[2]+1});
                }
            }
        }
        
        
        return -1;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>>  input={{0,0,0},{1,1,0},{1,1,0}};
    Solution so=Solution();
    int ret=so.shortestPathBinaryMatrix(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
