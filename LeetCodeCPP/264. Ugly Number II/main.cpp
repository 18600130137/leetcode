//
//  main.cpp
//  264. Ugly Number II
//
//  Created by admin on 2019/7/2.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> helper{1};
        int i2=0,i3=0,i5=0;
        for(int i=1;i<n;i++){
            int next=min(min(helper[i2]*2,helper[i3]*3),helper[i5]*5);
            helper.push_back(next);
            if (next == helper[i2] * 2)
                ++i2;
            if (next == helper[i3] * 3)
                ++i3;
            if (next == helper[i5] * 5)
                ++i5;
            
        }
        return helper[n-1];
        
        
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.nthUglyNumber(10);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
