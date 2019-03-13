//
//  main.cpp
//  41. First Missing Positive
//
//  Created by admin on 2019/3/13.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    //use extra space
     int firstMissingPositive1(vector<int>& nums) {
         set<int> helper(nums.begin(),nums.end());
         for(int i=1;i<=nums.size()+1;i++){
             if(helper.count(i)==0){
                 return i;
             }
         }
         return nums.size()+1;
     }
    
    
    int firstMissingPositive(vector<int>& nums) {
        int m=nums.size();
        
        for(int i=0;i<m;i++){
            while (nums[i]-1>=0 && nums[i]-1<m && nums[nums[i]-1]!=nums[i])                   {
                swap(nums[nums[i]-1],nums[i]);
            }
        }
        
        int i=0;
        for(;i<m;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        
        return i+1;
    }
};


int main(int argc, const char * argv[]) {
    vector<int>  input={3,4,-1,1};
    Solution so=Solution();
    int ret=so.firstMissingPositive(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
