//
//  main.cpp
//  29. Divide Two Integers_
//
//  Created by admin on 2019/3/6.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //wrong
    int divide1(int dividend, int divisor) {
        if(divisor==0){
            return dividend>=0? INT_MAX:INT_MIN;
        }
        long ret=(long)dividend/divisor;
        if(ret>INT_MAX ||ret<INT_MIN){
            return INT_MAX;
        }else{
            return (int)ret;
        }
    }
    
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }
        
        long d1=labs(dividend);
        long d2=labs(divisor);
        
        long ret=0,x=0;
        while(d1>=d2){
            for(x=0;d1>=(d2<<x<<1);x++);
            
            ret+=1<<x;
            d1-=d2<<x;
        }
        return (dividend>0)==(divisor>0)? ret:-ret;
        
        
    }
};


int main(int argc, const char * argv[]) {
    int input1=-2147483648;
    int input2=1;
    Solution so=Solution();
    int ret=so.divide(input1, input2);
    cout<<"The ret is:"<<ret<<endl;
    
    
    return 0;
}
