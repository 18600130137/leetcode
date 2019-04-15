//
//  main.cpp
//  115. Distinct Subsequences
//
//  Created by admin on 2019/4/15.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct1(string s, string t) {
        int m=t.size();
        int n=s.size();
        vector<vector<long>> dp(m+1,vector<long>(n+1,0));
        for(int j=0;j<=n;j++){
            dp[0][j]=1;
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s[j]==t[i]){
                    dp[i+1][j+1]=dp[i+1][j]+dp[i][j];
                }else{
                    dp[i+1][j+1]=dp[i+1][j];
                }
            }
        }
        for(auto item:dp){
            for(auto i:item){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        
        return dp[m][n];
    }
    
    
    int numDistinct(string s, string t) {
        int m=t.size();
        int n=s.size();
        vector<long> dp(n+1,1);
        
        for(int i=0;i<m;i++){
            int last=dp[0];
            dp[0]=0;
            for(int j=0;j<n;j++){
                if(s[j]==t[i]){
                    int tmp=dp[j+1];
                    dp[j+1]=dp[j]+last;
                    last=tmp;
                }else{
                    last=dp[j+1];
                    dp[j+1]=dp[j];
                }
            }
        }
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.numDistinct1("rabbbit","rabbit");
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
