//
//  main.cpp
//  16. 3Sum Closest
//
//  Created by admin on 2019/2/27.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int m=nums.size();
        if(m<=3){
            int sum=0;
            for(int i=0;i<m;i++){
                sum+=nums[i];
            }
            return sum;
        }
        sort(nums.begin(),nums.end());
        int ret=0;
        int minDiff=INT_MAX;
        for(int i=0;i<m-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int left=i+1,right=m-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(abs(target-sum)<minDiff){
                    minDiff=abs(target-sum);
                    ret=sum;
                }
                if(target-sum>0){
                    left++;
                }else if(target-sum<0){
                    right--;
                }else{
                    return target;
                }
            }
            
        }
        return ret;
        
    }
};



int main(int argc, const char * argv[]) {
    vector<int> input1={-1, 2, 1, -4};
    int  input2=1;
    Solution so=Solution();
    int ret=so.threeSumClosest(input1, input2);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
