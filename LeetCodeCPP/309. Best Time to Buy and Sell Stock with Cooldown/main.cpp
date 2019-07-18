//
//  main.cpp
//  309. Best Time to Buy and Sell Stock with Cooldown
//
//  Created by admin on 2019/7/18.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m=prices.size();
        if(m<=1){
            return 0;
        }
        vector<int>  buy(m+1,0),sell(m+1,0);
        buy[1]=-prices[0];
        for(int i=2;i<=m;i++){
            buy[i]=max(buy[i-1],sell[i-2]-prices[i-1]);
            sell[i]=max(sell[i-1],buy[i-1]+prices[i-1]);
        }
        
        return sell[m];
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input={1,2,3,0,2};
    Solution so=Solution();
    int ret=so.maxProfit(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
