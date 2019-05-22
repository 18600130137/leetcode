//
//  main.cpp
//  _1049. Last Stone Weight II
//
//  Created by admin on 2019/5/22.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        bitset<1501> helper={1};
        int sum=0;
        for(auto s:stones){
            sum+=s;
            for(int i=1500;i>=s;i--){
                helper[i]=helper[i]+helper[i-s];
            }
        }
        
        for(int i=sum/2;i>=0;i--){
            if(helper[i]){
                return sum-2*i;
            }
        }
        
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={3,1,34,21,23,12};
    Solution so=Solution();
    int ret=so.lastStoneWeightII(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
