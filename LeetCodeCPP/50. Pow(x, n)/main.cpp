//
//  main.cpp
//  50. Pow(x, n)
//
//  Created by admin on 2019/3/20.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        double tmp=myPow(x,n/2);
        if(n%2==0){
            return tmp*tmp;
        }else if(n>0){
            return tmp*tmp*x;
        }else{
            return tmp*tmp/x;
        }
    }
};


int main(int argc, const char * argv[]) {
    Solution so=Solution();
    double ret=so.myPow(2, 10);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
