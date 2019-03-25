//
//  main.cpp
//  59. Spiral Matrix II
//
//  Created by admin on 2019/3/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>//输出控制必备的头文件
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n,vector<int>(n,0));
        int left=0,right=n-1,top=0,bottom=n-1,index=1;
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){
                ret[top][i]=index++;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ret[i][right]=index++;
            }
            right--;
            for(int i=right;i>=left;i--){
                ret[bottom][i]=index++;
            }
            bottom--;
            for(int i=bottom;i>=top;i--){
                ret[i][left]=index++;
            }
            left++;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    int n=8;
    Solution so=Solution();
    vector<vector<int>> ret=so.generateMatrix(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(2)<<ret[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
