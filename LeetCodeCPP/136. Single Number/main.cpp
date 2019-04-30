//
//  main.cpp
//  136. Single Number
//
//  Created by admin on 2019/4/30.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int  ret=nums[0];
        for(int i=1;i<nums.size();i++){
            ret^=nums[i];
        }
        return  ret;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={2,1,4,1,2};
    Solution so=Solution();
    int ret=so.singleNumber(input);
    cout<<"The single Number is:"<<ret<<endl;
    return 0;
}
