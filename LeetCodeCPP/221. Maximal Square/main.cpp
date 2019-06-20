//
//  main.cpp
//  221. Maximal Square
//
//  Created by admin on 2019/6/20.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare2(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0){
            return 0;
        }
        int n=matrix[0].size();
        if(n==0){
            return 0;
        }
        int maxSide=0;
        vector<vector<int>>  dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!i || !j || matrix[i][j]=='0'){
                    dp[i][j]=matrix[i][j]-'0';
                }else{
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
                maxSide=max(maxSide,dp[i][j]);
            }
        }
        return maxSide*maxSide;
    }
    
    int maximalSquare1(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0){
            return 0;
        }
        int n=matrix[0].size();
        if(n==0){
            return 0;
        }
        int maxSide=0;
        //vector<vector<int>>  dp(m,vector<int>(n,0));
        vector<int>  cur(n,0),pre(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!i || !j || matrix[i][j]=='0'){
                    cur[j]=matrix[i][j]-'0';
                }else{
                    cur[j]=min(cur[j-1],min(pre[j],pre[j-1]))+1;
                }
                maxSide=max(maxSide,cur[j]);
            }
            fill(pre.begin(),pre.end(),0);
            swap(pre,cur);
        }
        return maxSide*maxSide;
    }
    
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0){
            return 0;
        }
        int n=matrix[0].size();
        if(n==0){
            return 0;
        }
        int maxSide=0,pre=0;
        //vector<vector<int>>  dp(m,vector<int>(n,0));
        vector<int>  cur(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int tmp=cur[j];
                if(!i || !j || matrix[i][j]=='0'){
                    cur[j]=matrix[i][j]-'0';
                }else{
                    cur[j]=min(pre,min(cur[j],cur[j-1]))+1;
                }
                maxSide=max(maxSide,cur[j]);
                pre=tmp;
            }
        }
        return maxSide*maxSide;
    }
};



int main(int argc, const char * argv[]) {
    vector<vector<char>> input={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    Solution so=Solution();
    int ret=so.maximalSquare(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
