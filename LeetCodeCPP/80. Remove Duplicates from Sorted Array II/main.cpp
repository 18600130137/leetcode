//
//  main.cpp
//  80. Remove Duplicates from Sorted Array II
//
//  Created by admin on 2019/4/1.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int m=nums.size();
        int j=0;
        for(int i=0;i<m;i++){
            if(j<2 ||nums[i]>nums[j-2]){
                nums[j++]=nums[i];
            }
        }
        
        return j;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={1,1,1,2,2,3};
    Solution so=Solution();
    int ret=so.removeDuplicates(input);
    cout<<"The ret is "<< ret<<endl;
    for(auto i:input){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
