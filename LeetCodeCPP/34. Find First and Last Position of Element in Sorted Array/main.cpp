//
//  main.cpp
//  34. Find First and Last Position of Element in Sorted Array
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
    vector<int> searchRange1(vector<int>& nums, int target) {
        int left=0;
        int m=nums.size();
        if(m==0){
            return {-1,-1};
        }
        
        int right=m-1;
        
        int li=-1,ri=-1;
        
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                if(mid==0 || nums[mid-1]<target){
                    li=mid;
                    break;
                }else{
                    right=mid-1;
                }
            }else if(nums[mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        
        if(li!=-1){
            left=li;
        }else{
            left=0;
        }
        right=m-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                if(mid==m-1 ||  nums[mid+1]>target){
                    ri=mid;
                    break;
                }else{
                    left=mid+1;
                }
            }else if(nums[mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        
        
        
        
        return {li,ri};
        
        
        
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int m=nums.size();
        int li=-1,ri=-1;
        if(m==0){
            return {li,ri};
        }
        int left=0;
        int right=m-1;
        
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                int ls=mid,rs=mid;
                while(left<=ls){
                    int mid_l=left+(ls-left)/2;
                    if(nums[mid_l]==target){
                        if(mid_l==0 || nums[mid_l-1]<target){
                            li=mid_l;
                            break;
                        }else{
                            ls=mid_l-1;
                        }
                    }else{
                        left=mid_l+1;
                    }
                }
                while(rs<=right){
                    int mid_r=rs+(right-rs)/2;
                    if(nums[mid_r]==target){
                        if(mid_r==m-1 || nums[mid_r+1]>target){
                            ri=mid_r;
                            break;
                        }else{
                            rs=mid_r+1;
                        }
                    }else{
                        right=mid_r-1;
                    }
                }
                break;
            }else if(nums[mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        
        return {li,ri};
        
    }
};


int main(int argc, const char * argv[]) {
    vector<int>  input1={5,7,7,8,8,10};
    Solution so=Solution();
    vector<int> ret=so.searchRange(input1, 8);
    cout<<"The result is:"<<ret[0]<<" "<<ret[1]<<endl;
    return 0;
}
