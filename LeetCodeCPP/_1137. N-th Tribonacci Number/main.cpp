//
//  main.cpp
//  _1137. N-th Tribonacci Number
//
//  Created by admin on 2019/7/29.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int tribonacci1(int n) {
        if(n<=0){
            return 0;
        }else if(n<=2){
            return 1;
        }
        vector<int> helper(n+1,0);
        helper[1]=1;
        helper[2]=1;
        for(int i=3;i<=n;i++){
            helper[i]=helper[i-1]+helper[i-2]+helper[i-3];
        }
        return  helper[n];
    }
    
    int tribonacci(int n) {
        if(n<2){
            return n;
        }
        int a=0,b=1,c=1;
        
        while(n-->2){
            int tmp=c;
            c=a+b+c;
            a=b;
            b=tmp;
        }
        
        return  c;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int  ret=so.tribonacci(20);
    cout<<"The  ret is:"<<ret<<endl;
    return 0;
}
