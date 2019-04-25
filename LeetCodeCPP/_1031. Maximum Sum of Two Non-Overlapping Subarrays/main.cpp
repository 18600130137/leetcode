//
//  main.cpp
//  _1031. Maximum Sum of Two Non-Overlapping Subarrays
//
//  Created by admin on 2019/4/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int m=A.size();
        for(int i=1;i<m;i++){
            A[i]+=A[i-1];
        }
        int ret=A[L+M-1],maxL=A[L-1],maxM=A[M-1];
        for(int i=L+M;i<m;i++){
            maxL=max(maxL,A[i-M]-A[i-L-M]);
            maxM=max(maxM,A[i-L]-A[i-L-M]);
            ret=max(ret,max(maxL+A[i]-A[i-M],maxM+A[i]-A[i-L]));
        }
        
        
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>  input={0,6,5,2,2,5,1,9,4};
    Solution so=Solution();
    int ret=so.maxSumTwoNoOverlap(input, 1, 2);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
