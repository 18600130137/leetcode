//
//  main.cpp
//  90. Subsets II
//
//  Created by admin on 2019/4/4.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int m=nums.size();
        vector<vector<int>> ret;
        ret.push_back({});
        int last_size=0;
        for(int i=0;i<m;i++){
            bool equal=false;
            if(i>0 && nums[i]==nums[i-1]){
                equal=true;
            }
            int s=ret.size();
            for(int j=0;j<s;j++){
                if(j<last_size && equal){
                    continue;
                }
                vector<int> tmp=ret[j];
                tmp.push_back(nums[i]);
                ret.push_back(tmp);
            }
            last_size=s;
        }
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input={1,2,2};
    Solution so=Solution();
    vector<vector<int>> ret=so.subsetsWithDup(input);
    for(auto item:ret){
        for(int i:item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
