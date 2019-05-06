//
//  main.cpp
//  _1039. Minimum Score Triangulation of Polygon
//
//  Created by admin on 2019/5/6.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int n=A.size();
        vector<vector<int>>  dp(n,vector<int>(n));
        
        
        for(int d=2;d<n;d++){
            for(int i=0;i+d<n;i++){
                int j=i+d;
                dp[i][j]=INT_MAX;
                for(int k=i+1;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+A[i]*A[j]*A[k]);
                }
            }
        }
        return dp[0][n-1];
    }
};




int main(int argc, const char * argv[]) {
    vector<int> input={1,3,1,4,1,5};
    Solution so=Solution();
    int ret=so.minScoreTriangulation(input);
    cout<<"The  ret is:"<<ret<<endl;
    return 0;
}
