//
//  main.cpp
//  231. Power of Two
//
//  Created by admin on 2019/6/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo1(int n) {
        int begin=1;
        if(n<begin){
            return false;
        }else if(n==begin){
            return true;
        }else{
            while(n>begin){
                begin<<=1;
                if(begin<0){
                    break;
                }
                if(begin==n){
                    return true;
                }
            }
            return false;
        }
    }
    
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        return !(n&(n-1));
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    bool ret=so.isPowerOfTwo(1024);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
