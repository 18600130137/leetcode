//
//  main.cpp
//  190. Reverse Bits
//
//  Created by admin on 2019/6/4.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        uint32_t looper=0x00000001;
        for(int i=0;i<32;i++){
            if((n&looper)!=0){
                result|=(1<<(31-i));
            }
            looper<<=1;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    uint32_t ret=so.reverseBits(43261596);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
