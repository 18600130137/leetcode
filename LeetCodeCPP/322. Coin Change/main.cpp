//
//  main.cpp
//  322. Coin Change
//
//  Created by admin on 2019/7/30.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int  helper(vector<int>& coins, int amount,vector<int>& rem){
        if(amount<0){
            return -1;
        }else if(amount==0){
            return 0;
        }
        if(rem[amount-1]){
            return rem[amount-1];
        }
        int  min_=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int  res=helper(coins,amount-coins[i],rem);
            if(res>=0 && res<min_){
                min_=res+1;
            }
        }
        rem[amount-1]=(min_==INT_MAX?-1:min_);
        
        return rem[amount-1];
    }
    
    
public:
    int coinChange1(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i){
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        
        return dp[amount]>amount?-1:dp[amount];
    }
    
    int coinChange(vector<int>& coins, int amount){
        if(amount<1){
            return 0;
        }
        vector<int>  rem(amount,0);
        return helper(coins,amount,rem);
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={1, 2, 5};
    Solution so=Solution();
    int ret=so.coinChange(input, 11);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
