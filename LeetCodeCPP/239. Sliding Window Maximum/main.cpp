//
//  main.cpp
//  239. Sliding Window Maximum
//
//  Created by admin on 2019/6/27.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int m=nums.size();
        if(m==0 || k==0){
            return {};
        }
        
        deque<int>  helper;
        vector<int> ret(m-k+1);
        int ret_index=0;
        for(int i=0;i<m;i++){
            if(!helper.empty() && helper.front()<i-k+1){
                helper.pop_front();
            }
            while(!helper.empty() && nums[helper.back()]<nums[i]){
                helper.pop_back();
            }
            helper.push_back(i);
            if(i>=k-1){
                ret[ret_index++]=nums[helper.front()];
            }
        }
        return ret;
    }
    
    
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,3,-1,-3,5,3,6,7};
    Solution so=Solution();
    vector<int> ret=so.maxSlidingWindow(input, 3);
    cout<<"The ret is:"<<endl;
    for(auto i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
