//
//  main.cpp
//  _1018. Binary Prefix Divisible By 5
//
//  Created by admin on 2019/4/1.
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
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int m=A.size();
        vector<bool> ret(m);
        ret[0]=(A[0]%5==0);
        for(int i=1;i<m;i++){
            A[i]=(A[i-1]*2+A[i])%5;
            ret[i]=(A[i]==0);
        }
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={0,1,1,1,1,1};
    Solution so=Solution();
    vector<bool> ret=so.prefixesDivBy5(input);
    for(auto i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
