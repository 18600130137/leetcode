//
//  main.cpp
//  240. Search a 2D Matrix II
//
//  Created by admin on 2019/6/27.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int  m=matrix.size();
        if(m==0){
            return false;
        }
        int n=matrix[0].size();
        if(n==0){
            return false;
        }
        int row=0,col=n-1;
        while(row<m && col>=0){
            if(matrix[row][col]==target){
                return true;
            }else{
                matrix[row][col]>target?col--:row++;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> input={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    Solution so=Solution();
    bool ret=so.searchMatrix(input,5);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
