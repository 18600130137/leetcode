//
//  main.cpp
//  26. Remove Duplicates from Sorted Array
//
//  Created by admin on 2019/3/5.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
     int removeDuplicates1(vector<int>& nums) {
         int m=nums.size();
         if(m<=1){
             return m;
         }

         int count=1;
         for(int i=m-2;i>=0;i--){
             if(nums[i]==nums[i+1]){
                 nums.erase(nums.begin()+i,nums.begin()+i+1);
             }else{
                 count++;
             }
         }
         return count;
     }
    
    int removeDuplicates2(vector<int>& nums) {
        int m=nums.size();
        if(m<=1){
            return m;
        }
        
        int count=0;
        for(int i=1;i<m;i++){
            if(nums[i]==nums[i-1]){
                count++;
            }else{
                nums[i-count]=nums[i];
            }
        }
        
        return m-count;
    }
};


int main(int argc, const char * argv[]) {
    vector<int>  input={0,0,1,1,1,2,2,3,3,4};
    Solution so=Solution();
    int ret=so.removeDuplicates2(input);
    cout<<"The ret is:"<<ret<<endl;
    for(int  i:input){
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}
