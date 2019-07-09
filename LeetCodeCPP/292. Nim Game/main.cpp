//
//  main.cpp
//  292. Nim Game
//
//  Created by admin on 2019/7/9.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n%4!=0;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    bool ret=so.canWinNim(27);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
