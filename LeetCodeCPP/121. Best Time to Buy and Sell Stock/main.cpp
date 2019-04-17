//
//  main.cpp
//  121. Best Time to Buy and Sell Stock
//
//  Created by admin on 2019/4/17.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m=prices.size();
        if(m<2){
            return 0;
        }
        int  min_=INT_MAX,ret=0;
        for(int i=0;i<m;i++){
            min_=min(min_,prices[i]);
            ret=max(ret,prices[i]-min_);
        }
        return  ret;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={7,1,5,3,6,4};
    Solution so=Solution();
    int ret=so.maxProfit(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
