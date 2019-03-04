//
//  main.cpp
//  _1004. Max Consecutive Ones III
//
//  Created by admin on 2019/3/4.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int m=A.size();
        int max_len=0;
        int j=0;
        for(int i=0;i<m;i++){
            K-=A[i]==0;
            while(K<0){
                K+=A[j++]==0;
            }
            max_len=max(max_len,i-j+1);
        }
        return max_len;
    }
};


int main(int argc, const char * argv[]) {
    vector<int>  input={1,1,1,0,0,0,1,1,1,1,0};
    Solution so=Solution();
    int ret=so.longestOnes(input, 2);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
