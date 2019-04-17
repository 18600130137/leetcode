//
//  main.cpp
//  120. Triangle
//
//  Created by admin on 2019/4/17.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        
        return triangle[0][0];
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>> input={{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution so=Solution();
    int ret=so.minimumTotal(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
