//
//  main.cpp
//  4. Median of Two Sorted Arrays
//
//  Created by admin on 2019/2/21.
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
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=(int)nums1.size();
        int n=(int)nums2.size();
        if(m>n){
            swap(nums1,nums2);
            swap(m,n);
        }
        int min_i=0,max_i=m,half=(m+n+1)/2;
        while(min_i<=max_i){
            int i=(min_i+max_i)/2;
            int j=half-i;
            if(i>0 && nums1[i-1]>nums2[j]){
                max_i=i-1;
            }else if(i< m &&nums1[i]<nums2[j-1]){
                min_i=i+1;
            }else{
                int maxLeft=0;
                int minRight=0;
                if(i==0){
                    maxLeft=nums2[j-1];
                }else if(j==0){
                    maxLeft=nums1[i-1];
                }else{
                    maxLeft=max(nums1[i-1],nums2[j-1]);
                }
                if((m+n)%2==1){
                    return maxLeft;
                }
                
                if(i==m){
                    minRight=nums2[j];
                }else if(j==n){
                    minRight=nums1[i];
                }else{
                    minRight=min(nums1[i],nums2[j]);
                }
                return (maxLeft+minRight)/2.0;
                
            }
            
        }
        
        
        return 0;
        
    }
};





int main(int argc, const char * argv[]) {
    vector<int> input1={1,2,3,4};
    vector<int> input2={3,4,5};
    Solution so=Solution();
    double ret=so.findMedianSortedArrays(input1, input2);
    cout << "ret result is:"<<ret<<endl;
    return 0;
}
