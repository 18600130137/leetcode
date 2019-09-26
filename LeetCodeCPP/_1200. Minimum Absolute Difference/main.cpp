//
//  main.cpp
//  _1200. Minimum Absolute Difference
//
//  Created by admin on 2019/9/26.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int m=arr.size();
        sort(arr.begin(),arr.end());
        int minDiff=INT_MAX;
        for(int i=1;i<m;i++){
            minDiff=min(minDiff,arr[i]-arr[i-1]);
        }
        //cout<<"minDiff==="<<minDiff<<endl;
        vector<vector<int>> ret;
        for(int i=1;i<m;i++){
            if(arr[i]-arr[i-1]==minDiff){
                ret.push_back({arr[i-1],arr[i]});
            }
        }
        return  ret;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={4,2,1,3};
    Solution so=Solution();
    vector<vector<int>> ret=so.minimumAbsDifference(input);
    for(auto re:ret){
        for(auto r:re){
            cout<<r<<" ";
        }
        cout<<endl;
    }
    return 0;
}
