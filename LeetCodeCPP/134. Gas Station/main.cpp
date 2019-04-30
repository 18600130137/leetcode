//
//  main.cpp
//  134. Gas Station
//
//  Created by admin on 2019/4/29.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
        int m=gas.size();
        for(int i=0;i<m;i++){
            int gasTank=0;
            int j=0;
            for(;j<=m;j++){
                int index=(i+j)%m;
                gasTank+=gas[index]-cost[index];
                //cout<<i<<" "<<j<<" "<<index<<" "<<gasTank<<endl;
                if(gasTank<0){
                    break;
                }
            }
            if(j==m+1){
                return i;
            }
        }
        return -1;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int m=gas.size();
        int start=0,bank=0,total=0;
        for(int i=0;i<m;i++){
            bank+=gas[i]-cost[i];
            if(bank<0){
                start=i+1;
                total+=bank;
                bank=0;
            }
            
        }
        return (total+bank)<0?-1:start;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input1={1,2,3,4,5};
    vector<int> input2={3,4,5,1,2};
    Solution so=Solution();
    int ret=so.canCompleteCircuit(input1,input2);
    cout<<"The start gas station index is:"<<ret<<endl;
    return 0;
}
