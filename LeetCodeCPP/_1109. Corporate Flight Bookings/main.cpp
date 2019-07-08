//
//  main.cpp
//  _1109. Corporate Flight Bookings
//
//  Created by admin on 2019/7/8.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ret(n+1,0);
        
        for(auto  b:bookings){
            ret[b[0]-1]+=b[2];
            ret[b[1]]-=b[2];
        }
        for(int i=1;i<n;i++){
            ret[i]+=ret[i-1];
        }
        return {ret.begin(),ret.end()-1};
        
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>> input={{1,2,10},{2,3,20},{2,5,25}};
    Solution so=Solution();
    vector<int> ret=so.corpFlightBookings(input, 5);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
