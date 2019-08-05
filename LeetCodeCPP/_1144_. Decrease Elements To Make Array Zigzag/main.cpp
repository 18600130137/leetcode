//
//  main.cpp
//  _1144_. Decrease Elements To Make Array Zigzag
//
//  Created by admin on 2019/8/5.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        vector<int> ret={0,0};
        int m=nums.size();
        int left,right;
        for(int i=0;i<m;i++){
            left=i>0?nums[i-1]:1001;
            right=i<m-1?nums[i+1]:1001;
            ret[i%2]+=max(0,nums[i]-min(left,right)+1);
        }
        
        return min(ret[0],ret[1]);
    }
};


int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3};
    Solution so=Solution();
    int ret=so.movesToMakeZigzag(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
