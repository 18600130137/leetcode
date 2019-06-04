//
//  main.cpp
//  191. Number of 1 Bits
//
//  Created by admin on 2019/6/4.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t looper=0x00000001;
        int count=0;
        for(int i=0;i<32;i++){
            if(n&looper){
                count++;
            }
            looper<<=1;
        }
        return count;
    }
    
    int hammingWeight1(uint32_t n) {
        int ans=0;
        while(n>0){
            n=n&(n-1);
            ans++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.hammingWeight(11);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
