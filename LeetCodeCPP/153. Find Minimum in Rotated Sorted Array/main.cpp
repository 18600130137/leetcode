//
//  main.cpp
//  153. Find Minimum in Rotated Sorted Array
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
        int low=0,high=nums.size()-1;
        
        while(low<high){
            if(nums[low]<nums[high]){
                return nums[low];
            }
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[high]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return nums[low];
    }
};


int main(int argc, const char * argv[]) {
    vector<int>  input={4,5,6,7,0,1,2};
    Solution so=Solution();
    int min_=so.findMin(input);
    cout<<"The min  is:"<<min_<<endl;
    return 0;
}
