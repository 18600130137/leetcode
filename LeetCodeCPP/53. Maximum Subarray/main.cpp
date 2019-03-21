//
//  main.cpp
//  53. Maximum Subarray
//
//  Created by admin on 2019/3/21.
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
    int maxSubArray(vector<int>& nums) {
        int m=nums.size();
        if(m==0){
            return 0;
        }
        vector<int>  dp(m);
        int M=nums[0];
        dp[0]=M;
        for(int i=1;i<m;i++){
            dp[i]=nums[i]+(dp[i-1]>0?dp[i-1]:0);
            M=max(M,dp[i]);
        }
        return M;
    }
};


int main(int argc, const char * argv[]) {
    vector<int> input={-2,1,-3,4,-1,2,1,-5,4};
    Solution so=Solution();
    int ret=so.maxSubArray(input);
    cout<<"The ret  is:"<<ret<<endl;
    return 0;
}
