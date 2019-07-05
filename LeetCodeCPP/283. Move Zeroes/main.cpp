//
//  main.cpp
//  283. Move Zeroes
//
//  Created by admin on 2019/7/5.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes2(vector<int>& nums) {
        int m=nums.size();
        int i=m-1;
        while(i>=0 && nums[i]==0){
            i--;
        }
        for(;i>=0;i--){
            if(nums[i]==0){
                nums.erase(nums.begin()+i);
                nums.push_back(0);
            }
        }
    }
    
    void moveZeroes1(vector<int>& nums) {
        int m=nums.size();
        int count0=0;
        for(int i=0;i<m;i++){
            if(nums[i]==0){
                count0++;
            }
        }
        nums.erase(remove(nums.begin(),nums.end(),0),nums.end());
        for(int i=0;i<count0;i++){
            nums.push_back(0);
        }
    }
    
    void moveZeroes(vector<int>& nums) {
        int m=nums.size();
        int insertPos=0;
        for(int i=0;i<m;i++){
            if(nums[i]!=0){
                nums[insertPos++]=nums[i];
            }
        }
        while(insertPos<m){
            nums[insertPos++]=0;
        }
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={0,1,0,3,12};
    Solution so=Solution();
    so.moveZeroes(input);
    
    for(auto i:input){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
