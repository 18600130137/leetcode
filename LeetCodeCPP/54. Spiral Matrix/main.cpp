//
//  main.cpp
//  54. Spiral Matrix
//
//  Created by admin on 2019/3/21.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0){
            return {};
        }
        int n=matrix[0].size();
        if(n==0){
            return {};
        }
        vector <int> ret;
        int layer=(min(m,n)+1)/2;
        for(int i=0;i<layer;i++){
            if(i==m-1-i){
                for(int j=i;j<=n-1-i;j++){
                    ret.push_back(matrix[i][j]);
                }
            }else if(i==n-1-i){
                for(int j=i;j<=m-1-i;j++){
                    ret.push_back(matrix[j][i]);
                }
            }else{
                for(int j=i;j<n-1-i;j++){
                    ret.push_back(matrix[i][j]);
                }
                for(int j=i;j<m-1-i;j++){
                    ret.push_back(matrix[j][n-i-1]);
                }
                for(int j=n-1-i;j>i;j--){
                    ret.push_back(matrix[m-1-i][j]);
                }
                for(int j=m-1-i;j>i;j--){
                    ret.push_back(matrix[j][i]);
                }
            }
        }
        return ret;
        
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>> input={{1,2,3},{5,6,7},{9,10,11}};
    Solution so=Solution();
    vector<int> ret=so.spiralOrder(input);
    for(auto item:ret){
        cout<<item<<" ";
    }
    cout<<endl;
    return 0;
}
