//
//  main.cpp
//  88. Merge Sorted Array
//
//  Created by admin on 2019/4/3.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)    {
        
        int i=m-1,j=n-1,tar=m+n-1;
        while(i>=0 && j>=0){
            nums1[tar--]=(nums1[i]>=nums2[j]?nums1[i--]:nums2[j--]);
        }
        while(j>=0){
            nums1[tar--]=nums2[j--];
        }
        
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input1={1,2,3,0,0,0};
    vector<int> input2={2,5,6};
    Solution so=Solution();
    so.merge(input1, 3, input2, 3);
    for(auto i:input1){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
