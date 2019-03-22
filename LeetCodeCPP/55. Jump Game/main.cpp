//
//  main.cpp
//  55. Jump Game
//
//  Created by admin on 2019/3/22.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
    
public:
    bool canJump(vector<int>& nums) {
        int m=nums.size();
        int walkMax=0;
        for(int i=0;i<m;i++){
            if(i>walkMax){
                return false;
            }
            walkMax=max(walkMax,i+nums[i]);
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={2,3,2,1,0,4};
    Solution so=Solution();
    bool ret=so.canJump(input);
    cout<<"It can  jump :"<<ret<<endl;
    return 0;
}
