//
//  main.cpp
//  327. Count of Range Sum
//
//  Created by admin on 2019/8/1.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int mergerSort(vector<long long>& helper,int left,int right,int lower,int upper){
        if(right-left<=1){
            return 0;
        }
        int mid=left+(right-left)/2;
        int count=mergerSort(helper,left,mid,lower,upper)+mergerSort(helper,mid,right,lower,upper);
        int m=mid,n=mid;
        for(int i=left;i<mid;i++){
            while(m<right && helper[m]-helper[i]<lower){
                m++;
            }
            while(n<right && helper[n]-helper[i]<=upper){
                n++;
            }
            count+=n-m;
        }
        inplace_merge(helper.begin()+left,helper.begin()+mid,helper.begin()+right);
        return count;
    }
    
public:
    int countRangeSum1(vector<int>& nums, int lower, int upper) {
        int m=nums.size();
        m++;
        vector<long long> helper(m,0);
        for(int i=1;i<m;i++){
            helper[i]=helper[i-1]+nums[i-1];
        }
        int ret=0;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                long long val=helper[j]-helper[i];
                if(val>=lower && val<=upper){
                    ret++;
                }
            }
        }
        return ret;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int m=nums.size();
        m++;
        vector<long long> helper(m,0);
        for(int i=1;i<m;i++){
            helper[i]=helper[i-1]+nums[i-1];
        }
        return mergerSort(helper,0,m,lower,upper);
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={-2,5,-1};
    Solution so=Solution();
    int ret=so.countRangeSum(input, -2, 2);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
