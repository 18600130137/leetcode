//
//  main.cpp
//  260. Single Number III
//
//  Created by admin on 2019/7/2.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber1(vector<int>& nums) {
        int m=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ret;
        for(int i=0;i<m;i++){
            if(i==m-1|| nums[i]!=nums[i+1]){
                ret.push_back(nums[i]);
            }else{
                i++;
            }
        }
        return ret;
    }
    
    vector<int> singleNumber(vector<int>& nums) {
        int m=nums.size();
        int tmp=0;
        for(int i=0;i<m;i++){
            tmp^=nums[i];
        }
        tmp&=-tmp;
        int num1=0,num2=0;
        for(int i=0;i<m;i++){
            if((nums[i]&tmp)==0){
                num1^=nums[i];
            }else{
                num2^=nums[i];
            }
        }
        return {num1,num2};
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={1,2,1,3,2,5};
    Solution so=Solution();
    vector<int> ret=so.singleNumber(input);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
