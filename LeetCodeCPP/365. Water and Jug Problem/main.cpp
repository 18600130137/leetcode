//
//  main.cpp
//  365. Water and Jug Problem
//
//  Created by admin on 2019/9/12.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
private:
    int  GCD(int x,int y){
        while(y!=0){
            int tmp=y;
            y=x%y;
            x=tmp;
        }
        return x;
    }
    
    
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x+y<z){
            return false;
        }
        if(x==z || y==z || x+y==z){
            return true;
        }
        return z%GCD(x,y)==0;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    bool  ret=so.canMeasureWater(3,8, 4);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
