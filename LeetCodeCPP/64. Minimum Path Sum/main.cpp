//
//  main.cpp
//  64. Minimum Path Sum
//
//  Created by admin on 2019/3/26.
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
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    continue;
                }else if(i==0){
                    grid[0][j]+=grid[0][j-1];
                }else if(j==0){
                    grid[i][0]+=grid[i-1][0];
                }else{
                    grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
                }
            }
        }
        return grid[m-1][n-1];
    }
    
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> input={{1,3,1},{1,5,1},{4,2,1}};
    Solution so=Solution();
    int ret=so.minPathSum(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
