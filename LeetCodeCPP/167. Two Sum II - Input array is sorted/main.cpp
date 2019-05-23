//
//  main.cpp
//  167. Two Sum II - Input array is sorted
//
//  Created by admin on 2019/5/23.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0,right=numbers.size()-1;
        while(left<right){
            if(numbers[left]+numbers[right]<target){
                left++;
            }else if(numbers[left]+numbers[right]>target){
                right--;
            }else{
                return {left+1,right+1};
            }
        }
        return {};
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={2,7,11,15};
    Solution so=Solution();
    vector<int> ret=so.twoSum(input, 9);
    cout<<"The ret is:"<<ret[0]<<","<<ret[1]<<endl;
    return 0;
}
