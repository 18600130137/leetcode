//
//  main.cpp
//  _1043. Partition Array for Maximum Sum
//
//  Created by admin on 2019/5/13.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int m=A.size();
        vector<int> dp(m,0);
        for(int i=0;i<m;i++){
            int imax=0;
            for(int k=1;k<=K && i-k+1>=0;k++){
                imax=max(imax,A[i-k+1]);
                dp[i]=max(dp[i],(i-k>=0?dp[i-k]:0)+imax*k);
            }
        }
        return dp[m-1];
        
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={1,15,7,9,2,5,10};
    Solution so=Solution();
    int ret=so.maxSumAfterPartitioning(input, 3);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
