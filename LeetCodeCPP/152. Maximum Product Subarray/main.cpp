//
//  main.cpp
//  152. Maximum Product Subarray
//
//  Created by admin on 2019/5/13.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPro=nums[0];
        
        for(int i=1,imin=maxPro,imax=maxPro;i<nums.size();i++){
            if(nums[i]<0){
                swap(imin,imax);
            }
            imin=min(nums[i],imin*nums[i]);
            imax=max(nums[i],imax*nums[i]);
            maxPro=max(maxPro,imax);
        }
        
        return maxPro;
    }
};


int main(int argc, const char * argv[]) {
    vector<int> input={2,3,-2,4};
    Solution so=Solution();
    int ret=so.maxProduct(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
