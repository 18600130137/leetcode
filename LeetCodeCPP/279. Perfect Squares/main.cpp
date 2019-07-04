//
//  main.cpp
//  279. Perfect Squares
//
//  Created by admin on 2019/7/4.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;


class Solution {
private:
    bool  isSquare(int n){
        int ret=(int)sqrt(n);
        return n==ret*ret;
    }
    
public:
    int numSquares3(int n) {
        if(n<=0){
            return 0;
        }
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        
        return dp[n];
    }
    
    int numSquares2(int n) {
        if(n<=0){
            return 0;
        }
        vector<int> dp={0};
        while(dp.size()<=n){
            int m=dp.size();
            int next=INT_MAX;
            for(int j=1;j*j<=m;j++){
                next=min(next,dp[m-j*j]+1);
            }
            dp.push_back(next);
        }
        
        return dp[n];
    }
    
    int numSquares1(int n) {
        if(isSquare(n)){
            return 1;
        }
        while((n&3)==0){
            n>>=2;
        }
        if((n&7)==7){
            return 4;
        }
        int maxS=(int)sqrt(n);
        for(int i=1;i<=maxS;i++){
            if(isSquare(n-i*i)){
                return 2;
            }
        }
        
        return 3;
    }
    
    int numSquares(int n) {
        if(n<=0){
            return 0;
        }
        vector<int>  factors;
        vector<int>  dots(n,0);
        int maxS=(int)sqrt(n);
        for(int i=1;i<=maxS;i++){
            factors.push_back(i*i);
            dots[i*i-1]=1;
        }
        if(factors.back()==n){
            return 1;
        }
        
        queue<int>  helper;
        for(auto  f:factors){
            helper.push(f);
        }
        int times=1;
        while(!helper.empty()){
            int m=helper.size();
            times++;
            for(int i=0;i<m;i++){
                int tmp=helper.front();
                for(auto f:factors){
                    if(tmp+f==n){
                        return times;
                    }else if(tmp+f<n && dots[tmp+f-1]==0){
                        dots[tmp+f-1]=times;
                        helper.push(tmp+f);
                    }else if(tmp+f>n){
                        break;
                    }
                }
                helper.pop();
            }
        }
        
        return 0;
        
    }};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.numSquares(13);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
