//
//  main.cpp
//  _1122. Relative Sort Array
//
//  Created by admin on 2019/7/15.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>  helper(1001,0);
        for(auto  a1:arr1){
            helper[a1]++;
        }
        int start=0;
        for(auto a2:arr2){
            while(helper[a2]>0){
                arr1[start++]=a2;
                helper[a2]--;
            }
        }
        for(int i=0;i<=1000;i++){
            while(helper[i]>0){
                arr1[start++]=i;
                helper[i]--;
            }
        }
        
        return arr1;
        
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input1={2,3,1,3,2,4,6,7,9,2,19};
    vector<int> input2={2,1,4,3,9,6};
    Solution so=Solution();
    vector<int> ret=so.relativeSortArray(input1, input2);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
