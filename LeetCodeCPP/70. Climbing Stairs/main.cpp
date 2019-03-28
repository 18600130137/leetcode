//
//  main.cpp
//  70. Climbing Stairs
//
//  Created by admin on 2019/3/28.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        int * dp=new int[2];
        dp[0]=1;
        dp[1]=2;
        for(int i=3;i<=n;i++){
            int tmp=dp[0]+dp[1];
            dp[0]=dp[1];
            dp[1]=tmp;
        }
        
        return dp[1];
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.climbStairs(5);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
