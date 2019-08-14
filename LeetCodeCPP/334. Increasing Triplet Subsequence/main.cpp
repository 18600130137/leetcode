//
//  main.cpp
//  334. Increasing Triplet Subsequence
//
//  Created by admin on 2019/8/14.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m=nums.size();
        int small=INT_MAX,big=INT_MAX;
        for(int i=0;i<m;i++){
            if(nums[i]<=small){
                small=nums[i];
            }else if(nums[i]<=big){
                big=nums[i];
            }else{
                return true;
            }
        }
        return false;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input={1,2,3,4,5};
    Solution so=Solution();
    bool ret=so.increasingTriplet(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
