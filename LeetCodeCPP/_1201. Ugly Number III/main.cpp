//
//  main.cpp
//  _1201. Ugly Number III
//
//  Created by admin on 2019/9/26.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
private:
    int  gcd(int a,int b){
        if(a==0){
            return b;
        }
        return gcd(b%a,a);
    }
    
    long long lcm(long long a,long long b){
        return (a*b)/gcd(a,b);
    }
    
    int count(int N,int a,int b,int c){
        return (int)(N/a+N/b+N/c-N/lcm(a,b)-N/lcm(b,c)-N/lcm(a,c)+N/lcm(lcm(a,b),c));
    }
    
    
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int left=1,right=INT_MAX;
        while(left<right){
            int mid=left+(right-left)/2;
            if(count(mid,a,b,c)<n){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        return left;
    }
};
int main(int argc, const char * argv[]) {
    int n = 5, a = 2, b = 11, c = 13;
    Solution so=Solution();
    int ret=so.nthUglyNumber(n, a, b, c);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
