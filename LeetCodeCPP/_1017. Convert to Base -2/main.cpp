//
//  main.cpp
//  _1017. Convert to Base -2
//
//  Created by admin on 2019/4/1.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string baseNeg2(int N) {
        string ret="";
        while(N){
            ret=to_string(N&1)+ret;
            N=-(N>>1);
        }
        return ret==""?"0":ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    string ret=so.baseNeg2(3);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
