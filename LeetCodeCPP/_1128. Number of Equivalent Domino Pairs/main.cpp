//
//  main.cpp
//  _1128. Number of Equivalent Domino Pairs
//
//  Created by admin on 2019/7/22.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int>  helper;
        int ret=0;
        for(auto  dom:dominoes){
            ret+=helper[max(dom[0],dom[1])*10+min(dom[0],dom[1])]++;
        }
        
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<vector<int>> input={{1,2},{2,1},{3,4},{5,6}};
    int ret=so.numEquivDominoPairs(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
