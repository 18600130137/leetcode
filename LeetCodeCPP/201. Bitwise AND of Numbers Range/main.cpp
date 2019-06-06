//
//  main.cpp
//  201. Bitwise AND of Numbers Range
//
//  Created by admin on 2019/6/6.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd3(int m, int n) {
        int d = INT_MAX;
        while ((m & d) != (n & d)) {
            d&=d-1;
        }
        return m & d;
    }
    
    int rangeBitwiseAnd2(int m, int n) {
        int i=0;
        while (m!=n) {
            m>>=1;
            n>>=1;
            i++;
        }
        return m<<i;
    }
    
    int rangeBitwiseAnd1(int m, int n) {
        return n>m?rangeBitwiseAnd1(m>>1,n>>1)<<1:m;
    }
    
    int rangeBitwiseAnd(int m, int n) {
        while(m<n){
            n&=n-1;
        }
        return n;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.rangeBitwiseAnd(5, 7);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
