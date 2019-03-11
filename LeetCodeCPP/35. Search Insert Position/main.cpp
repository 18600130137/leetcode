//
//  main.cpp
//  35. Search Insert Position
//
//  Created by admin on 2019/3/11.
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
    int searchInsert(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>=target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        
        return left;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,3,4,7,8};
    Solution so=Solution();
    int ret=so.searchInsert(input, 4);
    cout<<"The ret is==="<<ret<<endl;
    return 0;
}
