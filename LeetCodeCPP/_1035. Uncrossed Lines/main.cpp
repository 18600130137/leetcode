//
//  main.cpp
//  _1035. Uncrossed Lines
//
//  Created by admin on 2019/4/29.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m=A.size();
        int n=B.size();
        vector<vector<int>>  dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(A[i-1]==B[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input1={1,4,2};
    vector<int> input2={1,2,4};
    Solution so=Solution();
    int ret=so.maxUncrossedLines(input1, input2);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
