//
//  main.cpp
//  154. Find Minimum in Rotated Sorted Array II
//
//  Created by admin on 2019/5/14.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int m=nums.size();
        int low=0,high=m-1,mid=0;
        while(low<high){
            mid=low+(high-low)/2;
            if(nums[mid]>nums[high]){
                low=mid+1;
            }else if(nums[mid]<nums[high]){
                high=mid;
            }else{
                high--;
            }
        }
        
        return nums[low];
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={2,2,2,0,1};
    Solution so=Solution();
    int ret=so.findMin(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
