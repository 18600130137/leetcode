//
//  main.cpp
//  78. Subsets
//
//  Created by admin on 2019/4/1.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.push_back({});
        int m=nums.size();
        for(int i=0;i<m;i++){
            int size=ret.size();
            for(int j=0;j<size;j++){
                vector<int> tmp=ret[j];
                tmp.push_back(nums[i]);
                ret.push_back(tmp);
            }
        }
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input={1,2,3};
    Solution so=Solution();
    vector<vector<int>> ret=so.subsets(input);
    for(auto item:ret){
        for(auto i:item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
