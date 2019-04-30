//
//  main.cpp
//  _1034. Coloring A Border
//
//  Created by admin on 2019/4/29.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void helper(vector<vector<int>>& grid,int r0, int c0, int color,int sColor,int R,int C){
        if(r0<0 || r0>=R || c0<0 || c0>=C || grid[r0][c0]!=sColor){
            return;
        }
        
        int count=0;
        if(r0>0 && (grid[r0-1][c0]==sColor || grid[r0-1][c0]==-2*sColor || grid[r0-1][c0]==-sColor)){
            count++;
        }
        if(r0<R-1 && (grid[r0+1][c0]==sColor || grid[r0+1][c0]==-2*sColor || grid[r0+1][c0]==-sColor)){
            count++;
        }
        if(c0>0 && (grid[r0][c0-1]==sColor || grid[r0][c0-1]==-2*sColor || grid[r0][c0-1]==-sColor)){
            count++;
        }
        if(c0<C-1 && (grid[r0][c0+1]==sColor || grid[r0][c0+1]==-2*sColor || grid[r0][c0+1]==-sColor)){
            count++;
        }
        if(count==4){
            grid[r0][c0]=-sColor;
        }else{
            grid[r0][c0]=-2*sColor;
        }
        helper(grid,r0-1,c0,color,sColor,R,C);
        helper(grid,r0+1,c0,color,sColor,R,C);
        helper(grid,r0,c0-1,color,sColor,R,C);
        helper(grid,r0,c0+1,color,sColor,R,C);
    }
    
    
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int sColor=grid[r0][c0];
        if(sColor==color){
            return grid;
        }
        int R=grid.size();
        int C=grid[0].size();
        helper(grid,r0,c0,color,sColor,R,C);
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j]==-sColor){
                    grid[i][j]=sColor;
                }else if(grid[i][j]==-2*sColor){
                    grid[i][j]=color;
                }
            }
        }
        return grid;
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>>  input={{1,2,2},{2,3,2}};
    Solution so=Solution();
    vector<vector<int>> ret=so.colorBorder(input, 0, 1, 3);
    for(auto item:ret){
        for(auto i:item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
