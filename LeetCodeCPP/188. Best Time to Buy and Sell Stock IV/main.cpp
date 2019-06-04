//
//  main.cpp
//  188. Best Time to Buy and Sell Stock IV
//
//  Created by admin on 2019/6/4.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int quickSovle(vector<int>& prices,int count){
        int sum=0;
        for(int i=1;i<count;i++){
            if(prices[i]>prices[i-1]){
                sum+=prices[i]-prices[i-1];
            }
        }
        return sum;
    }
    
    int maxProfit1(int k, vector<int>& prices) {
        const int count=prices.size();
        if(count<=1){
            return 0;
        }
        if(k>=count/2){
            return  quickSovle(prices,count);
        }
        int dp[k+1][count];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=k;i++){
            int tmpMax=-prices[0];
            for(int j=1;j<count;j++){
                dp[i][j]=max(dp[i][j-1],tmpMax+prices[j]);
                tmpMax=max(tmpMax,dp[i-1][j-1]-prices[j]);
            }
        }
        return dp[k][count-1];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        const int m=prices.size();
        if(m<=1){
            return 0;
        }
        if(k>=m/2){
            return quickSovle(prices,m);
        }
        vector<int>  local(k+1,0);
        vector<int>  global(k+1,0);
        for(int i=0;i<m-1;i++){
            int diff=prices[i+1]-prices[i];
            for(int j=k;j>=1;j--){
                local[j]=max(global[j-1]+(diff>0?diff:0),local[j]+diff);
                global[j]=max(global[j],local[j]);
            }
            
        }
        
        return global[k];
        
    }};

int main(int argc, const char * argv[]) {
    vector<int> input={2,4,1};
    Solution so=Solution();
    int ret=so.maxProfit(2, input);
    cout<<"The ret is:"<<ret<<endl;
    
    return 0;
}
