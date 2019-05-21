//
//  main.cpp
//  _1046. Last Stone Weight
//
//  Created by admin on 2019/5/21.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>  helper;
        for(auto s:stones){
            helper.push(s);
        }
        while(helper.size()>1){
            int num1=helper.top();
            helper.pop();
            int num2=helper.top();
            helper.pop();
            helper.push(num1-num2);
        }
        
        return helper.top();
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={2,7,4,1,8,1};
    Solution so=Solution();
    int lastWeight=so.lastStoneWeight(input);
    cout<<"The last weight is:"<<lastWeight<<endl;
    return 0;
}
