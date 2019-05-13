//
//  main.cpp
//  _1041. Robot Bounded In Circle
//
//  Created by admin on 2019/5/13.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0,y=0,start=0;
        vector<vector<int>> way={{0,1},{1,0},{0,-1},{-1,0}};
        for(auto c:instructions){
            if(c=='R'){
                start=(start+1)%4;
            }else if(c=='L'){
                start=(start+3)%4;
            }else if(c=='G'){
                x+=way[start][0];
                y+=way[start][1];
            }
        }
        return x==0 && y==0 || start>0;
    }
};


int main(int argc, const char * argv[]) {
    Solution so=Solution();
    bool ret=so.isRobotBounded("GL");
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
