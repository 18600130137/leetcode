//
//  main.cpp
//  _1040. Moving Stones Until Consecutive II
//
//  Created by admin on 2019/5/6.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& S) {
        sort(S.begin(),S.end());
        int n=S.size();
        int i=0,low=n;
        int high=max(S[n-1]-S[1]-n+2,S[n-2]-S[0]-n+2);
        
        for(int j=0;j<n;j++){
            while(S[j]-S[i]>=n) i++;
            if(j-i+1==n-1 && S[j]-S[i]==n-2){
                low=min(low,2);
            }else{
                low=min(low,n-(j-i+1));
            }
        }
        
        return {low,high};
    }
};


int main(int argc, const char * argv[]) {
    vector<int>  input={6,5,4,3,10};
    Solution so=Solution();
    vector<int> ret=so.numMovesStonesII(input);
    cout<<"The min ret is:"<<ret[0]<<"  The max ret is:"<<ret[1]<<endl;
    return 0;
}
