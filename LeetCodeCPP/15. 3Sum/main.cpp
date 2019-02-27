//
//  main.cpp
//  15. 3Sum
//
//  Created by admin on 2019/2/27.
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        int m=nums.size();
        vector<vector<int>>  ret;
        if(m<3){
            return ret;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<m-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int left=i+1,right=m-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum<0){
                    left++;
                }else if(sum>0){
                    right--;
                }else{
                    ret.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left]==nums[left+1]){
                        left++;
                    }
                    
                    while(left<right && nums[right]==nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return ret;
    }
};

void  printVectors(vector<vector<int>> ret){
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }
    
}


int main(int argc, const char * argv[]) {
    vector<int> input={-1, 0, 1, 2, -1, -4};
    Solution so=Solution();
    vector<vector<int>> ret=so.threeSum(input);
    printVectors(ret);
    return 0;
}
