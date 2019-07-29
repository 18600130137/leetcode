//
//  main.cpp
//  _1139. Largest 1-Bordered Square
//
//  Created by admin on 2019/7/29.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0){
            return 0;
        }
        int n=grid[0].size();
        if(n==0){
            return 0;
        }
        vector<vector<int>> hor(m,vector<int>(n,0));
        vector<vector<int>> ver(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)  continue;
                hor[i][j]=grid[i][j]+(j>0?hor[i][j-1]:0);
                ver[i][j]=grid[i][j]+(i>0?ver[i-1][j]:0);
            }
        }
        
        int max_=0;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int min_=min(hor[i][j],ver[i][j]);
                while(min_>max_){
                    if(hor[i-min_+1][j]>=min_ && ver[i][j-min_+1]>=min_){
                        max_=min_;
                        break;
                    }else{
                        min_--;
                    }
                }
            }
        }
        
        return max_*max_;
        
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>> input={{1,1,1},{1,0,1},{1,1,1}};
    Solution so=Solution();
    int ret=so.largest1BorderedSquare(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
