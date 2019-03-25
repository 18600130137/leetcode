//
//  main.cpp
//  _1022. Smallest Integer Divisible by K
//
//  Created by admin on 2019/3/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K%2==0 ||K%5==0){
            return -1;
        }
        
        int r=0;
        for(int N=1;N<=K;N++){
            r=r*10+1;
            r=r%K;
            if(r==0){
                return N;
            }
            
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.smallestRepunitDivByK(7);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
