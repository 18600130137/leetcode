//
//  main.cpp
//  _1155. Number of Dice Rolls With Target Sum
//
//  Created by admin on 2019/8/13.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
private:
    const int MODEL=1000000007;
    int mem[31][1001] ={0};
    
public:
    int numRollsToTarget(int d, int f, int target) {
        if(d==0 || target<=0) return d==target;
        if(mem[d][target]){
            return mem[d][target]-1;
        }
        int combine=0;
        for(int i=1;i<=f;i++){
            combine=(combine+numRollsToTarget(d-1,f,target-i))%MODEL;
        }
        mem[d][target]=combine+1;
        return combine;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.numRollsToTarget(30, 30, 500);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
