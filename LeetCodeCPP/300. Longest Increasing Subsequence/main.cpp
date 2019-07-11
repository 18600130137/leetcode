//
//  main.cpp
//  300. Longest Increasing Subsequence
//
//  Created by admin on 2019/7/11.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS1(vector<int>& nums) {
        int m=nums.size();
        if(m<=1){
            return m;
        }
        vector<int> dp(m,1);
        for(int i=1;i<m;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
        }
        
        int maxLen=0;
        for(int i=0;i<m;i++){
            maxLen=max(maxLen,dp[i]);
        }
        return maxLen;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int m=nums.size();
        if(m<=1){
            return m;
        }
        vector<int> helper={nums[0]};
        for(int i=1;i<m;i++){
            if(nums[i]>helper.back()){
                helper.push_back(nums[i]);
            }else{
                *lower_bound(helper.begin(),helper.end(),nums[i])=nums[i];
            }
        }
        return helper.size();
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={10,9,2,5,3,7,101,18};
    Solution so=Solution();
    int ret=so.lengthOfLIS(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
