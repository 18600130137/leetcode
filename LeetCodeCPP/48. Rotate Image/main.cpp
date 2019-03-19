//
//  main.cpp
//  48. Rotate Image
//
//  Created by admin on 2019/3/19.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int layer=m/2;
        for(int i=0;i<layer;i++){
            for(int j=i;j<m-1-i;j++){
                //cout<<i<<" "<<j<<endl;
                int tmp=matrix[i][j];
                matrix[i][j]=matrix[m-1-j][i];
                matrix[m-1-j][i]=matrix[m-1-i][m-1-j];
                matrix[m-1-i][m-1-j]=matrix[j][m-1-i];
                matrix[j][m-1-i]=tmp;
            }
        }
    }
};
//[[ 5, 1, 9,11],[ 2, 4, 8,10],[13, 3, 6, 7],[15,14,12,16]]


int main(int argc, const char * argv[]) {
    vector<vector<int>> input={{ 5, 1, 9,11},{2, 4, 8,10},{13, 3, 6, 7},{15,14,12,16}};
    Solution so=Solution();
    so.rotate(input);
    for(auto item:input){
        for(auto i:item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
