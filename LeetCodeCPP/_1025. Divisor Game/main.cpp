//
//  main.cpp
//  _1025. Divisor Game
//
//  Created by admin on 2019/4/16.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
        return N%2==0;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    bool ret=so.divisorGame(8);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
