//
//  main.cpp
//  _1006. Clumsy Factorial
//
//  Created by admin on 2019/3/11.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int clumsy(int N) {
        if(N==1){
            return 1;
        }else if(N==2){
            return 2;
        }else if(N==3){
            return 6;
        }else if(N==4){
            return 7;
        }
        if(N%4==1 || N%4==2){
            return N+2;
        }else if(N%4==3){
            return N-1;
        }else{
            return N+1;
        }
        
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.clumsy(8);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
