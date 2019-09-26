//
//  main.cpp
//  371. Sum of Two Integers
//
//  Created by admin on 2019/9/19.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
public:
    int getSum(int a, int b) {
        while(b!=0){
            int c = a^b;
            b = (unsigned int)(a&b)<<1;
            cout<<a<<" "<<b<<endl;
            a = c;
        }
        return a;
    }
};


int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.getSum(-1, 1);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
