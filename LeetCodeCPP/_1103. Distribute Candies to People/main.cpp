//
//  main.cpp
//  _1103. Distribute Candies to People
//
//  Created by admin on 2019/7/1.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>  ret(num_people,0);
        for(int i=0;candies>0;i++){
            ret[i%num_people]+=candies>(i+1)?i+1:candies;
            candies-=(i+1);
        }
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<int> ret=so.distributeCandies(7, 4);
    for(auto i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
