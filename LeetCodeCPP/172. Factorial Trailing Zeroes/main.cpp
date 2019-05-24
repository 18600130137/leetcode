//
//  main.cpp
//  172. Factorial Trailing Zeroes
//
//  Created by admin on 2019/5/24.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        return n<5 ?0:n/5+trailingZeroes(n/5);
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.trailingZeroes(1000);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
