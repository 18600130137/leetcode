//
//  main.cpp
//  313. Super Ugly Number
//
//  Created by admin on 2019/7/23.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        int m=primes.size();
        vector<int>  rem(n,INT_MAX);
        rem[0]=1;
        vector<int>  index(m,0);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                rem[i]=min(rem[i],rem[index[j]]*primes[j]);
            }
            
            for(int j=0;j<m;j++){
                if(rem[index[j]]*primes[j]<=rem[i]){
                    index[j]++;
                }
            }
        }
        // for(auto  r:rem){
        //     cout<<r<<" ";
        // }
        
        return rem[n-1];
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<int>input={2,7,13,19};
    int ret=so.nthSuperUglyNumber(12,input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
