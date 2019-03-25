//
//  main.cpp
//  _1021. Best Sightseeing Pair
//
//  Created by admin on 2019/3/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
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
    int maxScoreSightseeingPair(vector<int>& A) {
        int maxScore=0,cur=0;
        for(int  a:A){
            maxScore=max(maxScore,cur+a);
            cur=max(cur,a)-1;
        }
        
        return maxScore;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int>  input={8,1,5,2,6};
    Solution so=Solution();
    int ret=so.maxScoreSightseeingPair(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
