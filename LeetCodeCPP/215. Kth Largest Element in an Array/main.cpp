//
//  main.cpp
//  215. Kth Largest Element in an Array
//
//  Created by admin on 2019/6/18.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest2(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),[](int a,int b){
            return a>=b;
        });
        return nums[k-1];
    }
    
    int findKthLargest1(vector<int>& nums, int k) {
        nth_element(nums.begin(),nums.begin()+k-1,nums.end(),greater<int>());
        return nums[k-1];
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        partial_sort(nums.begin(),nums.begin()+k,nums.end(),greater<int>());
        return nums[k-1];
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={3,2,1,5,6,4};
    Solution so=Solution();
    int ret=so.findKthLargest(input, 2);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
