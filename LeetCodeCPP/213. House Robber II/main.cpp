//
//  main.cpp
//  213. House Robber II
//
//  Created by admin on 2019/6/13.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int robMax(vector<int>& nums,int start,int end){
        int p1=nums[start],p2=max(nums[start],nums[start+1]);
        for(int i=start+2;i<end;i++){
            p1=max(p2,p1+nums[i]);
            swap(p1,p2);
        }
        
        return p2;
    }
    
    
    int rob(vector<int>& nums) {
        int m=nums.size();
        if(m==0){
            return 0;
        }else if(m==1){
            return nums[0];
        }else if(m==2){
            return max(nums[0],nums[1]);
        }
        
        return max(robMax(nums,0,m-1),robMax(nums,1,m));
        
    }
};


int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<int> input={2,3,2};
    int ret=so.rob(input);
    cout<<"The max rob is:"<<ret<<endl;
    return 0;
}
