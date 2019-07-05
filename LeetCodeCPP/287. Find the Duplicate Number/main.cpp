//
//  main.cpp
//  287. Find the Duplicate Number
//
//  Created by admin on 2019/7/5.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate2(vector<int>& nums) {
        int m=nums.size();
        if(m==1){
            return -1;
        }
        
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                if(nums[i]==nums[j]){
                    return nums[i];
                }
            }
        }
        
        return -1;
    }
    
    
    int findDuplicate3(vector<int>& nums) {
        int m=nums.size();
        if(m==1){
            return -1;
        }
        int slow=nums[0];
        int fast=nums[nums[0]];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        fast=0;
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
    
    int findDuplicate(vector<int>& nums) {
        int m=nums.size();
        if(m==1){
            return -1;
        }
        int left=1,right=m-1,count=0;
        while(left<right){
            int mid=left+(right-left)/2;
            count=0;
            for(int i=0;i<m;i++){
                if(nums[i]<=mid){
                    count++;
                }
            }
            if(count>mid){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        
        
        return left;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<int> input={1,3,4,2,2};
    int ret=so.findDuplicate(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
