//
//  main.cpp
//  _1094. Car Pooling
//
//  Created by admin on 2019/6/24.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> helper(1001,0);
        for(auto item:trips){
            helper[item[1]]+=-item[0];
            helper[item[2]]+=item[0];
        }
        
        for(auto i:helper){
            if(i!=0){
                capacity+=i;
                if(capacity<0){
                    return false;
                }
            }
        }
        return true;
        
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>>  input={{2,1,5},{3,3,7}};
    Solution so=Solution();
    bool ret=so.carPooling(input, 4);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
