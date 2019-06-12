//
//  main.cpp
//  209. Minimum Size Subarray Sum
//
//  Created by admin on 2019/6/12.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen1(int s, vector<int>& nums) {
        int m=nums.size();
        if(m==0){
            return 0;
        }
        int fast=0,slow=0,sum_=0,min_=INT_MAX;
        while(fast<m){
            sum_+=nums[fast++];
            while(sum_>=s){
                min_=min(min_,fast-slow);
                sum_-=nums[slow++];
            }
        }
        
        return min_==INT_MAX?0:min_;
        
    }
    
    int minSubArrayLen(int s, vector<int>& nums) {
        int m=nums.size(),min_=INT_MAX;
        if(m==0){
            return 0;
        }
        vector<int> sums(m+1,0);
        for(int i=1;i<=m;i++){
            sums[i]=sums[i-1]+nums[i-1];
        }
        
        for(int i=m;i>=0 && sums[i]>=s;i--){
            int j=upper_bound(sums.begin(),sums.end(),sums[i]-s)-sums.begin();
            min_=min(min_,i-j+1);
        }
        
        return min_==INT_MAX?0:min_;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input={2,3,1,2,4,3};
    Solution so=Solution();
    int ret=so.minSubArrayLen(7, input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
