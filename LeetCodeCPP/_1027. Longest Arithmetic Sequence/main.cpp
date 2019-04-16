//
//  main.cpp
//  _1027. Longest Arithmetic Sequence
//
//  Created by admin on 2019/4/16.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int,unordered_map<int,int>> helper;
        int m=A.size();
        int ret=2;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                int diff=A[j]-A[i];
                helper[diff][j]=max(helper[diff][j],helper[diff][i]+1);
                ret=max(ret,helper[diff][j]+1);
            }
        }
        
        return ret;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input={3,6,9,12};
    Solution so=Solution();
    int ret=so.longestArithSeqLength(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
