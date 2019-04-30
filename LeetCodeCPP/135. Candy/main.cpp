//
//  main.cpp
//  135. Candy
//
//  Created by admin on 2019/4/30.
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
    int candy(vector<int>& ratings) {
        int m=ratings.size();
        if(m==0){
            return 0;
        }
        
        vector<int> dp(m,1);
        for(int i=1;i<m;i++){
            if(ratings[i]>ratings[i-1]){
                dp[i]=dp[i-1]+1;
            }
        }
        for(int i=m-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] && dp[i]<=dp[i+1]){
                dp[i]=dp[i+1]+1;
            }
        }
        
        int sum=0;
        for(auto i:dp){
            sum+=i;
        }
        
        return sum;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>  input={1,0,2};
    Solution so=Solution();
    int ret=so.candy(input);
    cout<<"The candy count is:"<<ret<<endl;
    return 0;
}
