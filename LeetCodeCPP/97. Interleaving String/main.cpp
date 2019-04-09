//
//  main.cpp
//  97. Interleaving String
//
//  Created by admin on 2019/4/9.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size();
        int n=s2.size();
        int t=s3.size();
        if(m+n!=t){
            return false;
        }
        
        vector<vector<bool>>  dp(m+1,vector<bool>(n+1,false));
        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 && j==0){
                    dp[0][0]=true;
                }else if(i==0){
                    dp[0][j]=dp[0][j-1]&&s2[j-1]==s3[i+j-1];
                }else if(j==0){
                    dp[i][0]=dp[i-1][0]&&s1[i-1]==s3[i+j-1];
                }else{
                    dp[i][j]=dp[i][j-1]&&s2[j-1]==s3[i+j-1] || dp[i-1][j]&&s1[i-1]==s3[i+j-1];
                }
            }
        }
        
        return dp[m][n];
        
        
    }
};
int main(int argc, const char * argv[]) {
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    Solution so=Solution();
    bool ret=so.isInterleave(s1, s2, s3);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
