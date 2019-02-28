//
//  main.cpp
//  18. 4Sum
//
//  Created by admin on 2019/2/28.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>   ans;
        int m=nums.size();
        if(m<4){
            return  ans;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<m-3;i++){
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target){  //too big
                break;
            }
            if(nums[i]+nums[m-3]+nums[m-2]+nums[m-1]<target){ //too small
                continue;
            }
            if(i>0 && nums[i]==nums[i-1]){     //duplicate
                continue;
            }
            for(int j=i+1;j<m-2;j++){
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target){//too big
                    break;
                }
                if(nums[i]+nums[j]+nums[m-2]+nums[m-1]<target) //too small
                {
                    continue;
                }
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int left=j+1,right=m-1;
                while(left<right){
                    int sum=nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum>target){
                        right--;
                    }else if(sum<target){
                        left++;
                    }else{
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left<right && nums[left]==nums[left+1]){
                            left++;
                        }
                        while(left<right && nums[right]==nums[right-1]){
                            right--;
                        }
                        left++;
                        right--;
                    }
                    
                }
        }
    }
    return ans;
    
}
};

void  printVectors(vector<vector<int>> ret){
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main(int argc, const char * argv[]) {
    //vector<int>  input1={1, 0, -1, 0, -2, 2};
    vector<int>  input1={0, 0, 0, 0};
    int input2=0;
    Solution so=Solution();
    vector<vector<int>> ans=so.fourSum(input1, input2);
    printVectors(ans);
    return 0;
}
