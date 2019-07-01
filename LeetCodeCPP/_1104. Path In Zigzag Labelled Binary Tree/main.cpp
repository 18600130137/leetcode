//
//  main.cpp
//  _1104. Path In Zigzag Labelled Binary Tree
//
//  Created by admin on 2019/7/1.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int log=1;
        while(log<=label){
            log<<=1;
        }
        vector<int> ret;
        while(label>=1){
            ret.push_back(label);
            label=log-label+log/2-1;
            label>>=1;
            log>>=1;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<int> ret=so.pathInZigZagTree(16);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
