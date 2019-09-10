//
//  main.cpp
//  _1187. Make Array Strictly Increasing
//
//  Created by admin on 2019/9/10.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        unordered_map<int,int>  dp;
        dp[-1]=0;
        for(auto a1:arr1){
            unordered_map<int,int> tmp;
            for(auto d:dp){
                if(a1>d.first){
                    int lastCount=tmp.count(a1)>0?tmp[a1]:INT_MAX;
                    tmp[a1]=min(lastCount,d.second);
                }
                auto  iterUpper=upper_bound(arr2.begin(),arr2.end(),d.first);
                if(iterUpper!=arr2.end()){
                    int lastCount=tmp.count(*iterUpper)>0?tmp[*iterUpper]:INT_MAX;
                    tmp[*iterUpper]=min(lastCount,d.second+1);
                }
            }
            dp=tmp;
        }
        if(dp.empty()){
            return -1;
        }else{
            int ret=INT_MAX;
            for(auto d:dp){
                ret=min(ret,d.second);
            }
            return ret;
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input1={1,5,3,6,7};
    vector<int> input2={1,3,2,4};
    Solution so=Solution();
    int ret=so.makeArrayIncreasing(input1, input2);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
