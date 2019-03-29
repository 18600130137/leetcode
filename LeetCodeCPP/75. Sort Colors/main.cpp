//
//  main.cpp
//  75. Sort Colors
//
//  Created by admin on 2019/3/29.
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
    void sortColors(vector<int>& nums) {
        int i=0,j=i,k=nums.size()-1;
        while(j<=k){
            if(nums[j]==0){
                swap(nums[i++],nums[j++]);
            }else if(nums[j]==1){
                j++;
            }else{
                swap(nums[j],nums[k--]);
            }
        }
        
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input={2,0,2,1,1,0};
    Solution so=Solution();
    so.sortColors(input);
    for(auto i:input){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
