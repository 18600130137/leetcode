//
//  main.cpp
//  233. Number of Digit One
//
//  Created by admin on 2019/6/26.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int  cal_d(int n){
        int d=0;
        while(n){
            d++;
            n/=10;
        }
        return d;
    }
    
    int  helper(int n,vector<long long> &count1,vector<long long> &num1,vector<long long> &num2,int d){
        if(n<=0){
            return 0;
        }
        
        
        if(n>=10){
            int  addInt=count1[d-2]*(n/(num2[d-1]/2));
            int  addOne=(n<num2[d-1])?(n-(num2[d-1]/2)+1):(num2[d-1]/2);
            int next_n=n%(num2[d-1]/2);
            int next_d=cal_d(next_n);
            return addInt+addOne+helper(next_n,count1,num1,num2,next_d);
        }else{
            return n>0;
        }
    }
    
    
public:
    int countDigitOne1(int n) {
        if(n<=0){
            return 0;
        }
        
        int d=cal_d(n);
        vector<long long> count1(d);
        vector<long long> num1(d);
        vector<long long> num2(d);
        count1[0]=1;
        num1[0]=9;
        num2[0]=2;
        long long start=10;
        for(int i=1;i<d;i++){
            count1[i]=start+10*count1[i-1];
            num1[i]=num1[i-1]+start*9;
            num2[i]=num2[i-1]*10;
            start*=10;
        }
        
        if(n==num1.back()){
            return count1.back();
        }
        
        return helper(n,count1,num1,num2,d);
    }
    
    int countDigitOne(int n) {
        int ones = 0;
        long long add1=0;
        long long add2=01;
        long long m=1;
        for (m = 1; m <= n; m *= 10){
            cout<<"n and m:"<<n<<" "<<m<<" "<<endl;
            add1=(n/m + 8)/ 10 * m;
            add2=(n/m % 10 == 1) * (n%m + 1);
            cout<<"add=="<<add1<<" "<<add2<<endl;
            ones += (add1+add2);
        }
        
        return ones;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.countDigitOne(111);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
