//
//  main.cpp
//  _1037. Valid Boomerang
//
//  Created by admin on 2019/5/6.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    float calSlope(vector<int> p1,vector<int> p2){
        if(p1[0]==p2[0] && p1[1]==p2[1]){
            return -101;
        }
        
        
        if(p2[1]-p1[1]==0){
            return 101;
        }else{
            return (p2[0]-p1[0])*1.0/(p2[1]-p1[1]);
        }
        
    }
    
public:
    bool isBoomerang1(vector<vector<int>>& points) {
        float slope1=calSlope(points[0],points[1]);
        float slope2=calSlope(points[0],points[2]);
        
        return slope1!=-101 && slope2!=-101 && slope1!=slope2;
    }
    
    bool isBoomerang(vector<vector<int>>& points) {
        return (points[0][1]-points[1][1])*(points[0][0]-points[2][0])!=(points[0][1]-points[2][1])*(points[0][0]-points[1][0]);
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> input={{1,1},{2,3},{3,2}};
    Solution so=Solution();
    bool ret=so.isBoomerang(input);
    cout<<"The list is bommerang:"<<ret<<endl;
    return 0;
}
