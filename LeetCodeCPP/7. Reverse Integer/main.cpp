//
//  main.cpp
//  7. Reverse Integer
//
//  Created by admin on 2019/2/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long ret=0;
        while(x!=0){
            ret=ret*10+x%10;
            x/=10;
        }
        if(ret<INT_MIN || ret>INT_MAX){
            return 0;
        }else{
            return ret;
        }
    }
};

int main(int argc, const char * argv[]) {
    int input=-123;
    Solution so=Solution();
    int ret=so.reverse(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
