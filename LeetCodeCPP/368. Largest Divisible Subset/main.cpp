//
//  main.cpp
//  368. Largest Divisible Subset
//
//  Created by admin on 2019/9/18.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int m=nums.size();
        vector<int>  count(m,1);
        vector<int>  pre(m,-1);
        sort(nums.begin(),nums.end());
        int maxSeq=0;
        int idx=-1;
        for(int i=0;i<m;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(count[i]<count[j]+1){
                        count[i]=count[j]+1;
                        pre[i]=j;
                    }
                }
            }
            if(count[i]>maxSeq){
                maxSeq=count[i];
                idx=i;
            }
            
        }
        vector<int> ret;
        while(idx!=-1){
            ret.push_back(nums[idx]);
            idx=pre[idx];
        }
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={1,2,4,8};
    Solution so=Solution();
    vector<int> ret=so.largestDivisibleSubset(input);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
