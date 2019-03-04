//
//  main.cpp
//  _1000. Minimum Cost to Merge Stones
//
//  Created by admin on 2019/3/4.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include<iomanip>
#include <vector>
using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int K)
    {
        int m=(int)stones.size();
        if((m-1)%(K-1)) return -1;
        
        vector<int> sum(m+1,0);
        for(int i=0;i<m;i++){
            sum[i+1]=sum[i]+stones[i];
        }
        vector<vector<int>>  dp(m+1,vector<int>(m,0));
        for(int l=K;l<=m;l++){
            for(int i=0;i<=m-l;i++){
                dp[l][i]=99999;
                for(int k=1;k<l;k+=K-1){
                    dp[l][i]=min(dp[l][i],dp[k][i]+dp[l-k][i+k]);
                }
                
                if((l-1)%(K-1)==0){
                    dp[l][i]+=sum[i+l]-sum[i];
                }
            }
        }
        
        return dp[m][0];
        
        
        
    }
};


int main(int argc, const char * argv[]) {
    vector<int>  input={3,2,4,1};
    Solution so=Solution();
    int all_step=so.mergeStones(input,2);
    cout<<"All_step===="<<all_step<<endl;
    return 0;
}
