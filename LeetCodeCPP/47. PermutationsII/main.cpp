//
//  main.cpp
//  47. PermutationsII
//
//  Created by admin on 2019/3/18.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    // void  helper(vector<vector<int>>  &ret,vector<int> &nums,int start){
    //     if(start>=nums.size()-1){
    //         ret.push_back(nums);
    //         return;
    //     }
    //     for(int i=start;i<nums.size();i++){
    //         if(i>start && nums[i]==nums[start]){
    //             continue;
    //         }
    //         swap(nums[start],nums[i]);
    //         helper(ret,nums,start+1);
    //         swap(nums[start],nums[i]);
    //     }
    // }
    
    void  helper1(vector<vector<int>>  &ret,vector<int> nums,int start){
        if(start>=nums.size()-1){
            ret.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[start]){
                continue;
            }
            swap(nums[start],nums[i]);
            helper1(ret,nums,start+1);
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>  ret;
        helper1(ret,nums,0);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,1,2,2};
    Solution so=Solution();
    vector<vector<int>> ret=so.permuteUnique(input);
    for(vector<int> item:ret){
        for(int i:item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
