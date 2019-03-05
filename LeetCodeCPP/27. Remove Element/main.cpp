//
//  main.cpp
//  27. Remove Element
//
//  Created by admin on 2019/3/5.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement1(vector<int>& nums, int val) {
        int m=nums.size();
        int count=0;
        for(int i=0;i<m;i++){
            if(nums[i]==val){
                count++;
            }else{
                nums[i-count]=nums[i];
            }
        }
        
        return m-count;
    }
    
    int removeElement2(vector<int>& nums, int val) {
        int m=nums.size();
        int start=0;
        for(int i=0;i<m;i++){
            if(nums[i]!=val){
                nums[start++]=nums[i];
            }
        }
        
        return start;
    }
};


int main(int argc, const char * argv[]) {
    vector<int> input={0,1,2,2,3,0,4,2};
    Solution so=Solution();
    int ret=so.removeElement2(input, 2);
    cout<<"The ret is :"<<ret<<endl;
    for(auto item:input){
        cout<<item<<" ";
    }
    cout<<endl;
    return 0;
}
