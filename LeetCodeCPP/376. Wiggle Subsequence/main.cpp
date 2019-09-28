//
//  main.cpp
//  376. Wiggle Subsequence
//
//  Created by admin on 2019/9/28.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int m=nums.size();
        if(m==0){
            return 0;
        }
        vector<int>   up(m,1);
        vector<int>   down(m,1);
        for(int i=1;i<m;i++){
            if(nums[i]>nums[i-1]){
                up[i]=down[i-1]+1;
                down[i]=down[i-1];
            }else if(nums[i]<nums[i-1]){
                down[i]=up[i-1]+1;
                up[i]=up[i-1];
            }else{
                down[i]=down[i-1];
                up[i]=up[i-1];
            }
        }
        
        return max(up[m-1],down[m-1]);
        
    }
};
int main(int argc, const char * argv[]) {
    vector<int>  input={1,7,4,9,2,5};
    Solution so=Solution();
    int ret=so.wiggleMaxLength(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
