//
//  main.cpp
//  62. Unique Paths
//
//  Created by admin on 2019/3/26.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>  dp(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[j]+=dp[j-1];
            }
        }
        return dp[n-1];
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.uniquePaths(3, 7);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
