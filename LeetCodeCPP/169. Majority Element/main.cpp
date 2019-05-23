//
//  main.cpp
//  169. Majority Element
//
//  Created by admin on 2019/5/23.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement1(vector<int>& nums) {
        unordered_map<int,int>  helper;
        int m=nums.size();
        for(int i=0;i<m;i++){
            helper[nums[i]]+=1;
            if(helper[nums[i]]>m/2){
                return nums[i];
            }
        }
        return -1;
    }
    
    //梅尔投票法
    int majorityElement(vector<int>& nums) {
        int major=nums[0],count=1;
        
        for(int i=1;i<nums.size();i++){
            if(count==0){
                count++;
                major=nums[i];
            }else if(major==nums[i]){
                count++;
            }else{
                count--;
            }
        }
        return major;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={2,2,1,1,1,2,2};
    Solution so=Solution();
    int ret=so.majorityElement(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
