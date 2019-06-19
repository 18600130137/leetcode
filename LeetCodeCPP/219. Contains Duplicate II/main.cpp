//
//  main.cpp
//  219. Contains Duplicate II
//
//  Created by admin on 2019/6/19.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    
    bool containsNearbyDuplicate1(vector<int>& nums, int k) {
        unordered_map<int,int> helper;
        for(int i=0;i<nums.size();i++){
            helper[nums[i]]++;
            if(i>=k+1){
                helper[nums[i-k-1]]--;
            }
            if(helper[nums[i]]>1){
                return true;
            }
        }
        return false;
    }
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> helper;
        for(int i=0;i<nums.size();i++){
            if(helper.count(nums[i]) && i-helper[nums[i]]<=k){
                return true;
            }
            helper[nums[i]]=i;
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,1};
    Solution so=Solution();
    bool  ret=so.containsNearbyDuplicate(input, 3);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
