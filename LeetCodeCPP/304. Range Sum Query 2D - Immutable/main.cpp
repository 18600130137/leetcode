//
//  main.cpp
//  304. Range Sum Query 2D - Immutable
//
//  Created by admin on 2019/7/12.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> mc;  //matrixCumulative
    int m=0,n=0;
    int  a(int i,int j){
        return i>=0&&j>=0?mc[i][j]:0;
    }
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        mc =matrix;
        m=mc.size();
        if(m==0){
            return;
        }
        n=mc[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mc[i][j]+=a(i-1,j)+a(i,j-1)-a(i-1,j-1);
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(m==0 || n==0){
            return -1;
        }
        
        return mc[row2][col2]-a(row2,col1-1)-a(row1-1,col2)+a(row1-1,col1-1);
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>> input={{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
    NumMatrix* obj = new NumMatrix(input);
    int ret=obj->sumRegion(1, 2, 2, 4);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
