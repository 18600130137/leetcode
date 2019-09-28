//
//  main.cpp
//  375. Guess Number Higher or Lower II
//
//  Created by admin on 2019/9/27.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int DP(int start,int end,vector<vector<int>>   &mem){
        if(start>=end){
            return 0;
        }
        if(mem[start][end]){
            return mem[start][end];
        }
        int localMin=INT_MAX;
        for(int i=start;i<=end;i++){
            int cost=i+max(DP(start,i-1,mem),DP(i+1,end,mem));
            localMin=min(localMin,cost);
        }
        mem[start][end]=localMin;
        return localMin;
    }
    
    
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>   mem(n+1,vector<int>(n+1,0));
        return DP(1,n,mem);
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.getMoneyAmount(100);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
