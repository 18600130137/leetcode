//
//  main.cpp
//  174. Dungeon Game
//
//  Created by admin on 2019/5/24.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int r=d.size();
        int c=d[0].size();
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                if(i==r-1 && j==c-1){
                    d[i][j]=min(d[i][j],0);
                }else if(i==r-1){
                    d[i][j]=min(d[i][j]+d[i][j+1],0);
                }else if(j==c-1){
                    d[i][j]=min(d[i][j]+d[i+1][j],0);
                }else{
                    int select=max(d[i][j]+d[i+1][j],d[i][j]+d[i][j+1]);
                    d[i][j]=min(select,0);
                }
            }
        }
        return 1-d[0][0];
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> input={{-2,-3,3},{-5,-10,1},{10,30,-5}};
    Solution so=Solution();
    int ret=so.calculateMinimumHP(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
