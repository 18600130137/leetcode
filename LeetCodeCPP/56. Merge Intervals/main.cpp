//
//  main.cpp
//  56. Merge Intervals
//
//  Created by admin on 2019/3/22.
//  Copyright © 2019年 liu. All rights reserved.
//

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
private:
    static bool   compare(Interval i1,Interval i2){
        return i1.start<i2.start;
    }
    
public:
    vector<Interval> merge1(vector<Interval>& intervals) {
        int m=intervals.size();
        if(m<=1){
            return intervals;
        }
        
        sort(intervals.begin(),intervals.end(),compare);
        int left=intervals[m-1].start,right=intervals[m-1].end;
        vector<int> bag;
        bag.push_back(m-1);
        for(int i=m-2;i>=0;i--){
            if(intervals[i].end>=left){
                bag.push_back(i);
                left=intervals[i].start;
                right=max(right,intervals[i].end);
                int back=bag[0]+1;
                while(back<m && right>=intervals[back].start){
                    bag.insert(bag.begin(),back);
                    right=max(right,intervals[back].end);
                    back++;
                }
                
                
            }else{
                if(bag.size()>1){
                    intervals[i+1]=Interval(left,right);
                    //cout<<intervals.size()<<" "<<i+1<<" "<<bag[0]+1<<endl;
                    intervals.erase(intervals.begin()+i+2,intervals.begin()+min(bag[0]+1,(int)intervals.size()));
                }
                bag.clear();
                bag.push_back(i);
                left=intervals[i].start;
                right=intervals[i].end;
            }
        }
        
        
        if(bag.size()>1){
            intervals[0]=Interval(left,right);
            intervals.erase(intervals.begin()+1,intervals.begin()+min(bag[0]+1,(int)intervals.size()));
        }
        
        return  intervals;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        int m=intervals.size();
        if(m<=1){
            return intervals;
        }
        
        sort(intervals.begin(),intervals.end(),compare);
        vector<Interval> ret;
        ret.push_back(intervals[0]);
        for(int i=1;i<m;i++){
            if(intervals[i].start<=ret[ret.size()-1].end){
                ret[ret.size()-1].end=max(ret[ret.size()-1].end,intervals[i].end);
            }else{
                ret.push_back(intervals[i]);
            }
        }
        
        
        return  ret;
    }
};


int main(int argc, const char * argv[]) {
    vector<Interval> input={{5,5},{1,3},{3,5},{4,6},{1,1},{3,3},{5,6},{3,3},{2,4},{0,0}};
    vector<Interval> input1={{2,3},{0,1},{1,2},{3,4},{4,5},{1,1},{0,1},{4,6},{5,7},{1,1},{3,5}};
    Solution so=Solution();
    vector<Interval> ret=so.merge(input1);
    for(auto item:ret){
        cout<<item.start<<","<<item.end<<" ";
    }
    cout<<endl;
    return 0;
}
