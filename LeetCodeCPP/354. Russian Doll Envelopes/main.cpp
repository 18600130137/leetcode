//
//  main.cpp
//  354. Russian Doll Envelopes
//
//  Created by admin on 2019/8/23.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    
    
    
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int m=envelopes.size();
        if(m<2){
            return m;
        }
        
        sort(envelopes.begin(),envelopes.end(),[](vector<int> &e1,vector<int> &e2){
            if(e1[0]<e2[0]){
                return true;
            }else if(e1[0]==e2[0] && e1[1]<=e2[1]){
                return true;
            }else{
                return false;
            }
        });
        int res=0;
        vector<int>  dp(m,1);
        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
                
            }
            res=max(res,dp[i]);
        }
        
        
        return res;
    }
    
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<vector<int>> input={{5,4},{6,4},{6,7},{2,3}};
    int  ret=so.maxEnvelopes(input);
    cout<<"The ret sequence is:"<<ret<<endl;
    return 0;
}
