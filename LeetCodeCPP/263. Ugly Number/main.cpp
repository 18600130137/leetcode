//
//  main.cpp
//  263. Ugly Number
//
//  Created by admin on 2019/7/2.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num<1){
            return false;
        }
        for(int i:{2,3,5}){
            while(num%i==0){
                num=num/i;
            }
        }
        return num==1;
        
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    bool ret=so.isUgly(8);
    cout<<"8  is a  ugly number:"<<ret<<endl;
    return 0;
}
