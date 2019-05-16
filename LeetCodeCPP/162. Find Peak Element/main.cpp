//
//  main.cpp
//  162. Find Peak Element
//
//  Created by admin on 2019/5/16.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int m=nums.size();
        int left=0,right=m-1;
        while(left<right){
            int mid1=(left+right)/2;
            int mid2=mid1+1;
            if(nums[mid1]<nums[mid2]){
                left=mid2;
            }else{
                right=mid1;
            }
        }
        return left;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input={1,2,1,3,5,6,4};
    Solution so=Solution();
    int ret=so.findPeakElement(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
