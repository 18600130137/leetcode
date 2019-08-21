//
//  main.cpp
//  347. Top K Frequent Elements
//
//  Created by admin on 2019/8/21.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent1(vector<int>& nums, int k) {
        unordered_map<int,int>  helper;
        for(auto  n:nums){
            helper[n]++;
        }
        vector<pair<int,int>>  vec;
        for(auto h:helper){
            vec.push_back(make_pair(-h.second,h.first));
        }
        sort(vec.begin(),vec.end());
        
        vector<int> ret;
        for(int i=0;i<k;i++){
            ret.push_back(vec[i].second);
        }
        return ret;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int m=nums.size();
        unordered_map<int,int>  helper;
        for(auto  n:nums){
            helper[n]++;
        }
        vector<vector<int>>  bucket(m+1);
        for(auto h:helper){
            bucket[h.second].push_back(h.first);
        }
        vector<int> ret;
        for(int i=m;i>=0 &&ret.size()<k;i--){
            if(!bucket[i].empty()){
                for(auto b:bucket[i]){
                    ret.push_back(b);
                }
            }
        }
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={1,1,1,2,2,3};
    Solution so=Solution();
    vector<int> ret=so.topKFrequent(input, 2);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
