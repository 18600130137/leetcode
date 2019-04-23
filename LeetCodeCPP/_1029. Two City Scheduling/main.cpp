//
//  main.cpp
//  _1029. Two City Scheduling _1029. Two City Scheduling _1029. Two City Scheduling 1029. Two City Scheduling 1029. Two City Scheduling _1029. Two City Scheduling
//
//  Created by admin on 2019/4/23.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int twoCitySchedCost1(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](vector<int> &a,vector<int> &b){
            return (a[1]-a[0])>(b[1]-b[0]);
        });
        int  m=costs.size();
        int ret=0;
        for(int i=0;i<m/2;i++){
            ret+=costs[i][0]+costs[i+m/2][1];
        }
        return ret;
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int  m=costs.size();
        nth_element(costs.begin(),costs.begin()+m/2,costs.end(),[](vector<int> &a,vector<int> &b){
            return (a[1]-a[0])>(b[1]-b[0]);
        });
        //         for(auto item:costs){
        //             cout<<item[0]<<" "<<item[1]<<endl;
        //         }
        
        
        int ret=0;
        for(int i=0;i<m/2;i++){
            ret+=costs[i][0]+costs[i+m/2][1];
        }
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>>  input={{10,20},{30,200},{400,50},{30,20}};
    Solution so=Solution();
    int minCost=so.twoCitySchedCost(input);
    cout<<"The minite cost is:"<<minCost<<endl;
    return 0;
}
