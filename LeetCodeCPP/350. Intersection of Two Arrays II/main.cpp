//
//  main.cpp
//  350. Intersection of Two Arrays II
//
//  Created by admin on 2019/8/22.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>  helper;
        
        for(auto n1:nums1){
            helper[n1]++;
        }
        vector<int> ret;
        for(auto n2:nums2){
            if(--helper[n2]>=0){
                ret.push_back(n2);
            }
        }
        
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>   n1={4,9,5};
    vector<int>   n2={9,4,9,8,4};
    Solution so=Solution();
    vector<int> ret=so.intersect(n1, n2);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
