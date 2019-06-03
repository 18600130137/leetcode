//
//  main.cpp
//  _1074. Number of Submatrices That Sum to Target
//
//  Created by admin on 2019/6/3.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n-1;j++){
                matrix[i][j+1]+=matrix[i][j];
            }
        }
        
        int ret=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                unordered_map<int,int> helper;
                helper[0]=1;
                int cur=0;
                for(int k=0;k<m;k++){
                    cur+=matrix[k][j]-(i>0?matrix[k][i-1]:0);
                    ret+=helper[cur-target];
                    helper[cur]++;
                }
            }
        }
        
        
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>> input={{0,1,0},{1,1,1},{0,1,0}};
    Solution so=Solution();
    int ret=so.numSubmatrixSumTarget(input, 0);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
