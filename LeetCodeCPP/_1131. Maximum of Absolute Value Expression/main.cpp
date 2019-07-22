//
//  main.cpp
//  _1131. Maximum of Absolute Value Expression
//
//  Created by admin on 2019/7/22.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int m=arr1.size();
        vector<int> range={-1,1};
        int ret=0;
        for(auto p:range){
            for(auto q:range){
                int left=p*arr1[0]+q*arr2[0]+0;
                for(int i=1;i<m;i++){
                    int right=p*arr1[i]+q*arr2[i]+i;
                    ret=max(ret,right-left);
                    left=min(left,right);
                }
                
            }
        }
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<int> input1={1,2,3,4};
    vector<int> input2={-1,4,5,6};
    
    int ret=so.maxAbsValExpr(input1, input2);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
