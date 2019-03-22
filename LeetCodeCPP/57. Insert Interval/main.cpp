//
//  main.cpp
//  57. Insert Interval
//
//  Created by admin on 2019/3/22.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int m=intervals.size();
        if(m==0){
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<Interval> ret;
        bool  mergered=false;
        for(int i=0;i<m;i++){
            if(mergered || intervals[i].end<newInterval.start)
                ret.push_back(intervals[i]);
            else if(intervals[i].start>newInterval.end){
                if(!mergered){
                    ret.push_back(newInterval);
                    mergered=true;;
                }
                ret.push_back(intervals[i]);
            }else {
                newInterval.start=min(newInterval.start,intervals[i].start);
                newInterval.end=max(newInterval.end,intervals[i].end);
            }
        }
        if(!mergered){
            ret.push_back(newInterval);
        }
        return ret;
        
        
    }
};

int main(int argc, const char * argv[]) {
    vector<Interval> input1={{1,3},{6,9}};
    Interval  input2={2,5};
    Solution so=Solution();
    vector<Interval> ret=so.insert(input1, input2);
    for(auto  item:ret){
        cout<<item.start<<","<<item.end<<" ";
    }
    cout<<endl;
    return 0;
}
