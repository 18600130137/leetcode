//
//  main.cpp
//  _1072. Flip Columns For Maximum Number of Equal Rows
//
//  Created by admin on 2019/6/3.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        unordered_map<string,int> helper;
        for(int i=0;i<m;i++){
            string tmp="";
            for(int j=0;j<n;j++){
                tmp+=to_string(matrix[i][0]^matrix[i][j]);
            }
            helper[tmp]++;
        }
        int ret=0;
        for(auto item:helper){
            ret=max(ret,item.second);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> input={{0,0,0},{0,0,1},{1,1,0}};
    Solution so=Solution();
    int ret=so.maxEqualRowsAfterFlips(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
