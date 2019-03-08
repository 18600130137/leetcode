//
//  main.cpp
//  33. Search in Rotated Sorted Array
//
//  Created by admin on 2019/3/8.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
         int search1(vector<int>& nums, int target) {
             int m=nums.size();
             if(m==0){
                 return -1;
             }
             bool left_search=false;
             if(target>=nums[0]){
                 left_search=true;
             }else{
                 left_search=false;
             }
             int left=0,right=m-1;
             if(left_search){
                     while(left<=right){
                         int mid=left+(right-left)/2;
                         if(nums[mid]<nums[left]){
                             right=mid-1;
                         }else if(nums[mid]<target){
                             left=mid+1;
                         }else if(nums[mid]>target){
                             right=mid-1;
                         }else{
                             return mid;
                         }
                     }
                 }else{
                   while(left<=right){
                     int mid=left+(right-left)/2;
                     if(nums[mid]>nums[right]){
                         left=mid+1;
                     }else if(nums[mid]<target){
                         left=mid+1;
                     }else if(nums[mid]>target){
                         right=mid-1;
                     }else{
                         return mid;
                     }
                   }
    
                 }
             return -1;
         }
    
    int search(vector<int>& nums, int target) {
        int m=nums.size();
        if(m==0){
            return -1;
        }
        int left=0,right=m-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            
            if(nums[mid]>=nums[left]){
                if(target>=nums[left] && target<nums[mid]){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else{
                if(target>nums[mid] && target<=nums[right]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
        }
        
        return -1;
        
    }
    
    
    
};


int main(int argc, const char * argv[]) {
    vector<int>  input={4,5,6,7,0,1,2};
    Solution so=Solution();
    int ret=so.search(input, 0);
    cout<<"The ret is==="<<ret<<endl;
    return 0;
}
