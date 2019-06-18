//
//  main.cpp
//  218. The Skyline Problem
//
//  Created by admin on 2019/6/18.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ret,height;
        int pre=0,cur=0;
        
        
        for(auto v:buildings){
            height.push_back({v[0],-v[2]});
            height.push_back({v[1],v[2]});
        }
        
        sort(height.begin(),height.end(),[](vector<int> v1,vector<int> v2){
            if(v1[0]==v2[0]){
                return v1[1]<=v2[1];
            } else{
                return v1[0]<v2[0];
            }
        });
        
        
        
        multiset<int> helper;
        helper.insert(0);
        for(auto  h:height){
            if(h[1]<0){
                helper.insert(-h[1]);
            }else{
                helper.erase(helper.find(h[1]));
            }
            cur=*helper.rbegin();
            if(pre!=cur){
                ret.push_back({h[0],cur});
                pre=cur;
            }
        }
        
        
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> input={{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    
    //vector<vector<int>> input2={{0,2147483647,2147483647}};
    Solution so=Solution();
    vector<vector<int>> ret=so.getSkyline(input);
    
    for(auto r:ret){
        cout<<"("<<r[0]<<","<<r[1]<<")"<<" ";
    }
    cout<<endl;
    return 0;
}
