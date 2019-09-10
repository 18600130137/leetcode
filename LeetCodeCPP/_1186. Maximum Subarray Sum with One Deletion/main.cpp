//
//  main.cpp
//  _1186. Maximum Subarray Sum with One Deletion
//
//  Created by admin on 2019/9/10.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int m=arr.size();
        vector<int>  leftAcc(m,0);
        leftAcc[0]=arr[0];
        int accMax=arr[0];
        for(int i=1;i<m;i++){
            leftAcc[i]=max(arr[i],leftAcc[i-1]+arr[i]);
            accMax=max(accMax,leftAcc[i]);
        }
        
        vector<int> rightAcc(m,0);
        rightAcc[m-1]=arr[m-1];
        for(int i=m-2;i>=0;i--){
            rightAcc[i]=max(arr[i],rightAcc[i+1]+arr[i]);
        }
        
        for(int i=1;i<m-1;i++){
            accMax=max(accMax,leftAcc[i-1]+rightAcc[i+1]);
        }
        
        return accMax;
    }
};


int main(int argc, const char * argv[]) {
    vector<int> input={1,-2,0,3};
    Solution so=Solution();
    int ret=so.maximumSum(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
