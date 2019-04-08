//
//  main.cpp
//  96. Unique Binary Search Trees
//
//  Created by admin on 2019/4/8.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n<1){
            return 0;
        }
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        
        return dp[n];
        
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.numTrees(3);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
