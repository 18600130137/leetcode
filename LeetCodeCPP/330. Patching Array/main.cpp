//
//  main.cpp
//  330. Patching Array
//
//  Created by admin on 2019/8/7.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int m=nums.size();
        long long factor=1,i=0,ret=0;
        
        while(factor<=n){
            if(i<m && nums[i]<=factor){
                factor+=nums[i++];
            }else{
                ret++;
                factor+=factor;
            }
            //cout<<"factor=="<<factor<<endl;
        }
        
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<int> input={1,2,3,10};
    int ret=so.minPatches(input, 30);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
