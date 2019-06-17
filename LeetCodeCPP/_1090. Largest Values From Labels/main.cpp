//
//  main.cpp
//  _1090. Largest Values From Labels
//
//  Created by admin on 2019/6/17.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        int  m=values.size();
        vector<pair<int,int>>  helper;
        for(int i=0;i<m;i++){
            helper.push_back(make_pair(values[i],labels[i]));
        }
        sort(helper.begin(),helper.end(),[](pair<int,int> p1,pair<int,int> p2){
            return p1.first>p2.first;
        });
        unordered_map<int,int> record;
        int ret=0;
        int count=0;
        for(auto  item:helper){
            if(record[item.second]+1>use_limit){
                continue;
            }else{
                count++;
                if(count>num_wanted){
                    break;
                }
                ret+=item.first;
                record[item.second]++;
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<int> input1={5,4,3,2,1};
    vector<int> input2={1,1,2,2,3};
    int ret=so.largestValsFromLabels(input1, input2, 3, 1);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
