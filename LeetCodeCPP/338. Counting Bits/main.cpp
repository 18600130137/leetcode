//
//  main.cpp
//  338. Counting Bits
//
//  Created by admin on 2019/8/16.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> countBits1(int num) {
        vector<int> ret(num+1,0);
        for(int i=1;i<=num;i++){
            ret[i]=ret[i>>1]+(i&1);
        }
        return ret;
    }
    
    vector<int> countBits(int num) {
        vector<int> ret(num+1,0);
        for(int i=1;i<=num;i++){
            ret[i]=ret[i&(i-1)]+1;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<int>  ret=so.countBits(5);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
