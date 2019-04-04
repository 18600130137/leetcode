//
//  main.cpp
//  89. Gray Code
//
//  Created by admin on 2019/4/4.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int m=1<<n;
        vector<int> ret;
        for(int i=0;i<m;i++){
            ret.push_back(i^i>>1);
        }
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<int> ret=so.grayCode(2);
    for(auto i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
