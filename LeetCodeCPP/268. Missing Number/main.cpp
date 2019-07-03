//
//  main.cpp
//  268. Missing Number
//
//  Created by admin on 2019/7/2.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber2(vector<int>& nums) {
        nums.push_back(-1);
        int m=nums.size();
        for(int i=0;i<m;i++){
            while(nums[i]!=i && nums[i]!=-1){
                swap(nums[i],nums[nums[i]]);
            }
        }
        for(int i=0;i<m;i++){
            if(nums[i]==-1){
                return i;
            }
        }
        return -1;
        
    }
    
    //评估：三缺一
    int missingNumber1(vector<int>& nums) {
        int m=nums.size();
        int xor_=m;
        for(int i=0;i<m;i++){
            xor_=xor_^i^nums[i];
        }
        
        return xor_;
    }
    
    int missingNumber(vector<int>& nums) {
        int m=nums.size();
        int sum=m;
        for(int i=0;i<m;i++){
            sum+=(i-nums[i]);
        }
        
        return sum;
    }
};


int main(int argc, const char * argv[]) {
    vector<int> input={9,6,4,2,3,5,7,0,1};
    Solution so=Solution();
    int ret=so.missingNumber(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
