//
//  main.cpp
//  343. Integer Break
//
//  Created by admin on 2019/8/20.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int integerBreak1(int n) {
        int maxMuti=0;
        for(int i=2;i<=n;i++){
            if(n%i==0){
                int next=(int)pow(n/i,i);
                if(next>=maxMuti){
                    maxMuti=next;
                }else{
                    break;
                }
            }else{
                int next=(int)(pow(n/i,i-n%i)*pow(n/i+1,n%i));
                if(next>=maxMuti){
                    maxMuti=next;
                }else{
                    break;
                }
            }
            //cout<<i<<" "<<maxMuti<<endl;
        }
        return maxMuti;
    }
    
    int integerBreak(int n) {
        if(n==2){
            return 1;
        }else if(n==3){
            return 2;
        }
        int div=n/3;
        int remainder=n%3;
        if(remainder==1){
            remainder=4;
            div--;
        }else if(remainder==0){
            remainder=1;
        }
        return pow(3,div)*remainder;
        
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.integerBreak(58);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
