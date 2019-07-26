//
//  main.cpp
//  319. Bulb Switcher
//
//  Created by admin on 2019/7/26.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};


int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.bulbSwitch(5);
    cout<<"The ret is "<<ret<<endl;
    return 0;
}
