//
//  main.cpp
//  326. Power of Three
//
//  Created by admin on 2019/8/1.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree1(int n) {
        if(n<1){
            return 0;
        }
        while(n%3==0){
            n=n/3;
        }
        return n==1;
    }
    
    bool isPowerOfThree2(int n) {
        double logN=log10(n)/log10(3);
        return (int)logN==logN;
    }
    
    bool isPowerOfThree(int n){
        return n>0 && 1162261467%n==0;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.isPowerOfThree(27);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
