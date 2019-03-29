//
//  main.cpp
//  73. Set Matrix Zeroes
//
//  Created by admin on 2019/3/29.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int col0=1;
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                col0=0;
            }
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=matrix[0][j]=0;
                }
            }
        }
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>0;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
            if(col0==0){
                matrix[i][0]=0;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>>  input={{1,1,1},{1,0,1},{1,1,1}};
    Solution so=Solution();
    so.setZeroes(input);
    for (auto item:input) {
        for(auto i:item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    return 0;
}
