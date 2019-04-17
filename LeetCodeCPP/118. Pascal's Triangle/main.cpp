//
//  main.cpp
//  118. Pascal's Triangle
//
//  Created by admin on 2019/4/17.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for(int i=1;i<=numRows;i++){
            vector<int> tmp(i,1);
            for(int j=1;j<i-1;j++){
                tmp[j]=ret[i-2][j-1]+ret[i-2][j];
            }
            ret[i-1]=tmp;
        }
        return  ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution  so=Solution();
    vector<vector<int>> ret=so.generate(5);
    for(auto item:ret){
        for(auto i:item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
