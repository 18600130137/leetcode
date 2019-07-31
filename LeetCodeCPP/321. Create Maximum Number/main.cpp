//
//  main.cpp
//  321. Create Maximum Number
//
//  Created by admin on 2019/7/30.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int>  genMax(vector<int> &nums,int s){
        int m=nums.size();
        vector<int>  ans(s,0);
        for(int i=0,j=0;i<m;i++){
            while(m-i>s-j && j>0 && nums[i]>ans[j-1]){
                j--;
            }
            if(j<s){
                ans[j++]=nums[i];
            }
            
        }
        return ans;
    }
    
    bool   greater(const vector<int> &nums1,const vector<int> &nums2,int i,int j){
        while(i<nums1.size() && j<nums2.size() && nums1[i]==nums2[j]){
            i++;
            j++;
        }
        return j==nums2.size() || i<nums1.size() && nums1[i]>nums2[j];
    }
    
    vector<int>  merger(const vector<int> &nums1,const vector<int> &nums2,int k){
        vector<int>  ans(k,0);
        int i=0,j=0,s=0;
        for(int i=0,j=0,s=0;s<k;s++){
            ans[s]=greater(nums1,nums2,i,j)?nums1[i++]:nums2[j++];
        }
        return ans;
    }
    
    
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m=nums1.size(),n=nums2.size();
        vector<int>  maxAns(k,0);
        for(int i=max(k-n,0);i<=k && i<=m;i++){
            vector<int>  tmp=merger(genMax(nums1,i),genMax(nums2,k-i),k);
            maxAns=greater(tmp,maxAns,0,0)?tmp:maxAns;
        }
        return maxAns;
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input1={3,4,6,5};
    vector<int>  input2={9,1,2,5,8,3};
    Solution so=Solution();
    vector<int> ret=so.maxNumber(input1, input2, 5);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
