//
//  main.cpp
//  994. Rotting Oranges
//
//  Created by admin on 2019/2/20.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
private:
    int rotting(vector<vector<int>>& grid,int x,int y,int d){
        size_t m=grid.size();
        size_t n=grid[0].size();
        if(x<0 || x>=m || y<0 || y>=n || grid[x][y]!=1){
            return 0;
        }
        grid[x][y]=d+3;
        return 1;
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        size_t m=grid.size();
        size_t n=grid[0].size();
        int fresh=0;
        for(int i=0;i<m;i++){
            fresh+=count_if(grid[i].begin(),grid[i].end(),[](int a){
                return a==1;
            });
        }
        int d=0;
        for(int last_fresh=fresh;fresh>0;d++){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==d+2){
                        fresh-=rotting(grid,i-1,j,d)+rotting(grid,i+1,j,d)+rotting(grid,i,j-1,d)+rotting(grid,i,j+1,d);
                    }
                }
            }
            if(fresh==exchange(last_fresh,fresh)){
                return -1;
            }
        }
        
        return d;
    }
    
};

vector<vector<int>>   getInputData(){
    return {{2,1,1},{1,1,0},{0,1,1}};
}



int main(int argc, const char * argv[]) {
    vector<vector<int>>  input1=getInputData();
    Solution so=Solution();
    int ret=so.orangesRotting(input1);
    cout<<"Ret result is:"<<ret<<endl;
    return 0;
}
