//
//  main.cpp
//  329. Longest Increasing Path in a Matrix
//
//  Created by admin on 2019/8/7.
//  Copyright © 2019年 liu. All rights reserved.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    vector<vector<int>> surround={{-1,0},{1,0},{0,-1},{0,1}};
    
    int  dfs(vector<vector<int>>& matrix,int i,int j,int m,int n,vector<vector<int>> &cache){
        if(cache[i][j]) return cache[i][j];
        int max_way=1;
        for(auto  s:surround){
            int x=i+s[0],y=j+s[1];
            if(x<0 || x>=m || y<0 || y>=n || matrix[i][j]<=matrix[x][y]) continue;
            max_way=max(max_way,1+dfs(matrix,x,y,m,n,cache));
            
        }
        cache[i][j]=max_way;
        return max_way;
    }
    
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0){
            return 0;
        }
        int n=matrix[0].size();
        if(n==0){
            return 0;
        }
        vector<vector<int>> cache(m,vector<int>(n,0));
        int max_way=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                max_way=max(max_way,dfs(matrix,i,j,m,n,cache));
            }
        }
        
        return max_way;
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>>  input={{9,9,4},{6,6,8},{2,1,1}};
    Solution so=Solution();
    int ret=so.longestIncreasingPath(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
