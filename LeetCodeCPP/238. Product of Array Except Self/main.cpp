//
//  main.cpp
//  238. Product of Array Except Self
//
//  Created by admin on 2019/6/27.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf1(vector<int>& nums) {
        int m=nums.size();
        long long multi=LONG_MIN;
        vector<int>  ret(m,0);
        int zero_count=0;
        int zero_index=-1;
        for(int i=0;i<m;i++){
            if(nums[i]){
                if(multi==LONG_MIN){
                    multi=nums[i];
                }else{
                    multi*=nums[i];
                }
            }else{
                zero_count++;
                zero_index=i;
                if(zero_count>=2){
                    return ret;
                }
            }
            
        }
        if(zero_count==1){
            ret[zero_index]=multi;
            return ret;
        }
        
        for(int i=0;i<m;i++){
            ret[i]=(int)(multi/nums[i]);
        }
        return ret;
    }
    
    vector<int> productExceptSelf(vector<int>& nums) {
        int m=nums.size();
        vector<int> ret(m);
        ret[0]=1;
        for(int i=1;i<m;i++){
            ret[i]=ret[i-1]*nums[i-1];
        }
        int right=1;
        for(int i=m-1;i>=0;i--){
            ret[i]=ret[i]*right;
            right*=nums[i];
        }
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,2,3,4};
    Solution so=Solution();
    vector<int> ret=so.productExceptSelf(input);
    for(auto  i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
