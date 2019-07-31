//
//  main.cpp
//  324. Wiggle Sort II
//
//  Created by admin on 2019/7/31.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int reflect(int i,vector<int>& nums,int m){
        return nums[(1+2*(i)) % (m|1)];
    }
    
public:
    void wiggleSort(vector<int>& nums) {
        int m=nums.size();
        auto mid=nums.begin()+m/2;
        nth_element(nums.begin(),mid,nums.end());
        int mid_num=*mid;
        
        
        // Index-rewiring.
#define A(i) nums[(1+2*(i)) % (m|1)]
        int left=0,right=m-1,i=0;
        while(left<=right){
            
            if(A(left)>mid_num){
                swap(A(left++),A(i++));
            }else if(A(left)<mid_num){
                swap(A(left),A(right--));
            }else{
                left++;
            }
        }
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,5,1,1,6,4};
    Solution so=Solution();
    so.wiggleSort(input);
    for(auto r:input){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
