//
//  main.cpp
//  _1140. Stone Game II
//
//  Created by admin on 2019/7/29.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int helper(vector<int>& sum,int index,int M,vector<vector<int>>  &rem,int m){
        if(index>=m) return 0;
        if(index+2*M>=m){
            return sum[index];
        }
        if(rem[index][M]) return rem[index][M];
        int nextMin=INT_MAX;
        for(int i=1;i<=2*M;i++){
            nextMin=min(nextMin,helper(sum,index+i,max(i,M),rem,m));
        }
        rem[index][M]=sum[index]-nextMin;
        return rem[index][M];
    }
    
public:
    int stoneGameII(vector<int>& piles) {
        int m=piles.size();
        if(m==0){
            return 0;
        }
        vector<vector<int>>  rem(m,vector<int>(m,0));
        for(int i=m-2;i>=0;i--){
            piles[i]+=piles[i+1];
        }
        
        return helper(piles,0,1,rem,m);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={2,7,9,4,4};
    Solution so=Solution();
    int ret=so.stoneGameII(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
