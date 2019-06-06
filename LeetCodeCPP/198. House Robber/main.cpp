//
//  main.cpp
//  198. House Robber
//
//  Created by admin on 2019/6/5.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob1(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        int *rob=new int[n];
        rob[0]=nums[0];
        rob[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int a=nums[i]+rob[i-2];
            int b=rob[i-1];
            rob[i]=max(a,b);
        }
        
        return rob[n-1];
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        int *rob=new int[2];
        rob[0]=nums[0];
        rob[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int a=nums[i]+rob[0];
            int b=rob[1];
            rob[0]=rob[1];
            rob[1]=max(a,b);
        }
        
        return rob[1];
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,1};
    Solution so=Solution();
    int ret=so.rob(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
