//
//  main.cpp
//  72. Edit Distance
//
//  Created by admin on 2019/3/28.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
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
    int minDistance1(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        
        vector<vector<int>>  dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            dp[i][0]=i;
        }
        for(int j=1;j<=n;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
            }
        }
        
        
        return dp[m][n];
    }
    
    int minDistance2(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        
        vector<int> pre(n+1,0),cur(n+1,0);
        
        for(int j=1;j<=n;j++){
            pre[j]=j;
        }
        
        for(int i=1;i<=m;i++){
            cur[0]=i;
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    cur[j]=pre[j-1];
                }else{
                    
                    cur[j]=min(pre[j-1],min(cur[j-1],pre[j]))+1;
                }
            }
            fill(pre.begin(),pre.end(),0);
            swap(pre,cur);
        }
        return pre[n];
    }
    
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        
        vector<int> dp(n+1,0);
        
        for(int j=1;j<=n;j++){
            dp[j]=j;
        }
        
        int pre;
        for(int i=1;i<=m;i++){
            pre=dp[0];
            dp[0]=i;
            for(int j=1;j<=n;j++){
                int tmp=dp[j];
                if(word1[i-1]==word2[j-1]){
                    dp[j]=pre;
                }else{
                    dp[j]=min(pre,min(dp[j-1],dp[j]))+1;
                }
                pre=tmp;
            }
        }
        
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {
    string input1="horse";
    string input2="ros";
    Solution so=Solution();
    int ret=so.minDistance(input1, input2);
    cout<<"The ret is:"<<ret<<endl;
    
    return 0;
}
