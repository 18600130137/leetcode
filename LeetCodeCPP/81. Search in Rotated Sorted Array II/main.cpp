//
//  main.cpp
//  81. Search in Rotated Sorted Array II
//
//  Created by admin on 2019/4/2.
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
    bool search(vector<int>& nums, int target) {
        
        int m=nums.size();
        int left=0,right=m-1;
        
        while(left<=right){
            while(left<right && nums[left]==nums[right]){
                left++;
            }
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return true;
            }else if(nums[mid]>=nums[left]){
                if(target>=nums[left] && target<nums[mid]){  //限制在小空间内
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else if(nums[mid]<=nums[right]){
                if(target>nums[mid] && target<=nums[right]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
        }
        
        
        return false;
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input={2,5,6,0,0,1,2};
    Solution so=Solution();
    bool ret=so.search(input, 0);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
