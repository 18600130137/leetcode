//
//  main.cpp
//  200. Number of Islands
//
//  Created by admin on 2019/6/6.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0 || grid[0].size()==0){
            return 0;
        }
        
        int m=grid.size(),n=grid[0].size();
        
        vector<pair<int,int>> surround={{-1,0},{1,0},{0,-1},{0,1}};
        int ret=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ret++;
                    queue<pair<int,int>> helper;
                    helper.push(make_pair(i,j));
                    grid[i][j]='0';
                    while(!helper.empty()){
                        pair<int,int> top=helper.front();
                        helper.pop();
                        
                        for(auto  p:surround){
                            pair<int,int> newPoint=make_pair(top.first+p.first,top.second+p.second);
                            if(newPoint.first>=0 && newPoint.first<m && newPoint.second>=0 && newPoint.second<n && grid[newPoint.first][newPoint.second]=='1'){
                                helper.push(newPoint);
                                grid[newPoint.first][newPoint.second]='0';
                            }
                            
                        }
                        
                    }
                    
                    
                }
            }
        }
        
        return ret;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<char>> input={{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    Solution so=Solution();
    int ret=so.numIslands(input);
    cout<<"The result is:"<<ret<<endl;
    return 0;
}
