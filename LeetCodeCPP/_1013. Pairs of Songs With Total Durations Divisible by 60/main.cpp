//
//  main.cpp
//  _1013. Pairs of Songs With Total Durations Divisible by 60
//
//  Created by admin on 2019/3/18.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int numPairsDivisibleBy60_1(vector<int>& time) {
        unordered_map<int,int> helper;
        int ret=0;
        for(int i=0;i<time.size();i++){
            ret+=helper[(60-time[i]%60)%60];
            helper[time[i]%60]++;
        }
        return ret;
    }
    
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> helper(60);
        int ret=0;
        for(int i=0;i<time.size();i++){
            ret+=helper[(60-time[i]%60)%60];
            helper[time[i]%60]++;
        }
        return ret;
    }
};



int main(int argc, const char * argv[]) {
    vector<int> myInput={30,20,150,100,40};
    Solution so=Solution();
    int ret=so.numPairsDivisibleBy60(myInput);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
