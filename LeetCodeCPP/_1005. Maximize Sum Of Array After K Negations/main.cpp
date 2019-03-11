//
//  main.cpp
//  _1005. Maximize Sum Of Array After K Negations
//
//  Created by admin on 2019/3/11.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        int m=A.size();
        for(int i=0;i<m && K>0 && A[i]<0;i++,K--){
            A[i]=-A[i];
        }
        
        return accumulate(A.begin(),A.end(),0)-(K%2)* *min_element(A.begin(),A.end())*2;
        
        
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input={4,2,3};
    Solution so=Solution();
    int ret=so.largestSumAfterKNegations(input, 1);
    cout<<"The ret is:"<<ret<<endl;
    
    return 0;
}
