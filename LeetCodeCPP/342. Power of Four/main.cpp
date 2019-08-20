//
//  main.cpp
//  342. Power of Four
//
//  Created by admin on 2019/8/20.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num>0 && (num&(num-1))==0 && ((num-1)%3==0);
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    bool ret=so.isPowerOfFour(16);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
