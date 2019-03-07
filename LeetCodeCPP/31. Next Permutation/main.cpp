//
//  main.cpp
//  31. Next Permutation
//
//  Created by admin on 2019/3/7.
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
private:
    void swap(vector<int>& nums,int index){
        for(int i=nums.size()-1;i>=1;i--){
            if(nums[i]>nums[index]){
                int tmp=nums[i];
                nums[i]=nums[index];
                nums[index]=tmp;
                break;
            }
        }
    }
    
    
public:
    void nextPermutation(vector<int>& nums) {
        int m=nums.size();
        if(m<=1){
            return;
        }
        int i=m-1;
        for(;i>=1;i--){
            if(nums[i]>nums[i-1]){
                break;
            }
        }
        if(i!=0){
            swap(nums,i-1);
        }
        reverse(nums.begin()+i,nums.end());
        
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input={1,2,3,4,5};
    Solution so=Solution();
    so.nextPermutation(input);

    for (int i:input) {
        cout<<i<<" ";
    }
    cout<<endl;
    
    
  
    return 0;
}
