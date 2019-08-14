//
//  main.cpp
//  335. Self Crossing
//
//  Created by admin on 2019/8/14.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int m=x.size();
        if(m<4){
            return false;
        }
        
        for(int i=3;i<m;i++){
            if(x[i]>=x[i-2] && x[i-1]<=x[i-3]) return true;
            if(i>=4){
                if(x[i-1]==x[i-3] && x[i-2]<=x[i]+x[i-4]) return true;
            }
            if(i>=5){
                if(x[i-2]>=x[i-4] && x[i]>=x[i-2]-x[i-4] && x[i-1]>=x[i-3]-x[i-5] && x[i-1]<=x[i-3]) return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={2,1,1,2};
    Solution so=Solution();
    bool ret=so.isSelfCrossing(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
