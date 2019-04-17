//
//  main.cpp
//  123. Best Time to Buy and Sell Stock III
//
//  Created by admin on 2019/4/17.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
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
    int maxProfit(vector<int>& prices) {
        int m=prices.size();
        vector<int> firstMax(m);
        int minBuy=INT_MAX,maxProfit=0;
        for(int i=0;i<m;i++){
            minBuy=min(minBuy,prices[i]);
            maxProfit=max(maxProfit,prices[i]-minBuy);
            firstMax[i]=maxProfit;
        }
        maxProfit=0;
        int maxSell=0;
        int ret=0;
        for(int i=m-2;i>=0;i--){
            maxSell=max(maxSell,prices[i+1]);
            maxProfit=max(maxProfit,maxSell-prices[i]);
            ret=max(ret,firstMax[i]+maxProfit);
        }
        
        return ret;
        
    }
    
    int maxProfit2(vector<int>& prices) {
        int m=prices.size();
        if(m<=1){
            return 0;
        }
        int profit1=0,profit2=0,money1=INT_MIN,money2=INT_MIN;
        
        // for(int i=0;i<m;i++){
        //     profit2=max(profit2,money2+prices[i]);     //获得第二次卖出最大收益
        //     money2=max(money2,profit1-prices[i]);      //获得第二次买入最小成本
        //     profit1=max(profit1,money1+prices[i]);   //获得第一次卖出最大收益
        //     money1=max(money1,-prices[i]);           //获得第一次买入最小成本
        // }
        
        for(int i=0;i<m;i++){
            money1=max(money1,-prices[i]);           //获得第一次买入最小成本
            profit1=max(profit1,money1+prices[i]);   //获得第一次卖出最大收益
            money2=max(money2,profit1-prices[i]);      //获得第二次买入最小成本
            profit2=max(profit2,money2+prices[i]);     //获得第二次卖出最大收益
        }
        return profit2;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={3,3,5,0,0,3,1,4};
    Solution so=Solution();
    int ret=so.maxProfit2(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
