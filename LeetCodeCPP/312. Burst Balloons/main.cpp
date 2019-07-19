//
//  main.cpp
//  312. Burst Balloons
//
//  Created by admin on 2019/7/19.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int helper(vector<int> &nums,vector<vector<int>> &mem,int left,int right){
        if(left+1==right){
            return 0;
        }
        if(mem[left][right]>0){
            return mem[left][right];
        }
        int  ans=0;
        for(int i=left+1;i<right;i++){
            ans=max(ans,nums[left]*nums[i]*nums[right]+helper(nums,mem,left,i)+helper(nums,mem,i,right));
        }
        mem[left][right]=ans;
        return ans;
    }
    
    
public:
    int maxCoins1(vector<int>& inums) {
        int m=inums.size();
        vector<int>  nums(m+2,0);
        int n=1;
        for(int i=0;i<m;i++){
            nums[n++]=inums[i];
        }
        nums[0]=nums[n++]=1;
        vector<vector<int>>  dp(n,vector<int>(n,0));
        for(int k=2;k<n;k++){
            for(int left=0;left<n-k;left++){
                int right=left+k;
                for(int i=left+1;i<right;i++){
                    dp[left][right]=max(dp[left][right],nums[left]*nums[i]*nums[right]+dp[left][i]+dp[i][right]);
                }
            }
        }
        
        return dp[0][n-1];
        
    }
    
    int maxCoins(vector<int>& inums) {
        int m=inums.size();
        vector<int>  nums(m+2,0);
        int n=1;
        for(int i=0;i<m;i++){
            nums[n++]=inums[i];
        }
        nums[0]=nums[n++]=1;
        vector<vector<int>> mem(n,vector<int>(n,0));
        
        return helper(nums,mem,0,n-1);
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input={3,1,5,8};
    Solution so=Solution();
    int ret=so.maxCoins(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
