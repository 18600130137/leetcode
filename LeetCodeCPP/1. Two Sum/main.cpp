//
//  main.cpp
//  1. Two Sum
//
//  Created by admin on 2019/2/20.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
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
    vector<int> twoSum(vector<int>& nums, int target) {
        size_t m=nums.size();
        unordered_map<int,int> helper;
        
        for(int i=0;i<m;i++){
            if(helper.count(nums[i])>0){
                return {helper[nums[i]],i};
            }else{
                helper[target-nums[i]]=i;
            }
        }
        
        return {};
    }
};

int main(int argc, const char * argv[]) {
    vector<int> i1={2,7,11,15};
    int i2=9;
    Solution so=Solution();
    auto ret=so.twoSum(i1,i2);
    if(ret.size()>=2){
        cout<<ret[0]<<","<<ret[1]<<endl;
    }
    return 0;
}
