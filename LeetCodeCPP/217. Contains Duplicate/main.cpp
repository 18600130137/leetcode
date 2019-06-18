//
//  main.cpp
//  217. Contains Duplicate
//
//  Created by admin on 2019/6/18.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>  helper;
        for(int i=0;i<nums.size();i++){
            if(helper.count(nums[i])){
                return true;
            }else{
                helper.insert(nums[i]);
            }
        }
        return  false;
    }
    
    bool containsDuplicate1(vector<int>& nums) {
        return  unordered_set<int>(nums.begin(),nums.end()).size()<nums.size();
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,1};
    Solution so=Solution();
    bool ret=so.containsDuplicate(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
