//
//  main.cpp
//  _1175. Prime Arrangements
//
//  Created by admin on 2019/9/2.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;



class Solution {
private:
    const int mode=1000000007;
    
    int primeCount(int n){
        vector<bool>  dp(n+1,true);
        dp[0]=dp[1]=false;
        for(int i=2;i*i<=n;i++){
            if(dp[i]){
                for(int j=i*i;j<=n;j+=i){
                    dp[j]=false;
                }
            }
        }
        int primeCount=0;
        for(auto d:dp){
            if(d){
                primeCount++;
            }
        }
        return primeCount;
    }
    
    int factorial(int n){
        long long ret=1;
        for(int i=2;i<=n;i++){
            ret=(ret*i)%mode;
        }
        return ret;
    }
    
    
public:
    int numPrimeArrangements(int n) {
        int pCount=primeCount(n);
        long long pFac=factorial(pCount);
        long long otherFac=factorial(n-pCount);
        
        return (pFac*otherFac)%mode;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int countRet=so.numPrimeArrangements(100);
    cout<<"The ret is:"<<countRet<<endl;
    return 0;
}
