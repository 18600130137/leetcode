//
//  main.cpp
//  45. Jump Game II
//
//  Created by admin on 2019/3/15.
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
private:
    int minStep=INT_MAX;
    void helper(vector<int>& nums,int start,int step){
        if(step>minStep){
            return;
        }
        
        if(start>=nums.size()-1){
            minStep=min(minStep,step);
            return;
        }
        
        for(int i=1;i<=nums[start];i++){
            helper(nums,start+i,step+1);
        }
    }
    
public:
    int jump1(vector<int>& nums) {
        helper(nums,0,0);
        return minStep;
    }
    
    int jump(vector<int>& nums) {
        int m=nums.size();
        int low=0,high=0,step=0;
        while(high<m-1){
            int preLow=low;
            int preHigh=high;
            for(int i=preLow;i<=preHigh;i++){
                high=max(high,i+nums[i]);
            }
            low=preHigh+1;
            step++;
        }
        return step;
    }
    
};


int main(int argc, const char * argv[]) {
    //vector<int>  input={2,3,1,1,4};
    //vector<int>  input={5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9};
    vector<int>  input={8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    Solution so=Solution();
    int step=so.jump(input);
    cout<<"The  min  step is:"<<step<<endl;
    return 0;
}
