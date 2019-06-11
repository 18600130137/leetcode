//
//  main.cpp
//  204. Count Primes
//
//  Created by admin on 2019/6/11.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


class Solution {
private:
    int isPrime(int n){
        if(n==2){
            return 1;
        }
        
        for(int i=2;i<=(int)sqrt(n);i++){
            if(n%i==0){
                return 0;
            }
        }
        
        return 1;
    }
    
public:
    int countPrimes1(int n) {
        n--;
        int count=0;
        for(int i=2;i<=n;i++){
            count+=isPrime(i);
        }
        return count;
    }
    
    int countPrimes(int n) {   //所有的数由质数组成
        vector<bool> helper(n,false);
        int count=0;
        for(int i=2;i<n;i++){
            if(!helper[i]){
                count++;
                for(int j=2;i*j<n;j++){
                    helper[i*j]=true;
                }
            }
        }
        
        return count;
    }};


int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.countPrimes(100);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
