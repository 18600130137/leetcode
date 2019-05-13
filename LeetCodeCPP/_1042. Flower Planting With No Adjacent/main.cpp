//
//  main.cpp
//  _1042. Flower Planting With No Adjacent
//
//  Created by admin on 2019/5/13.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>>   helper(N);
        for(auto p:paths){
            helper[p[0]-1].push_back(p[1]-1);
            helper[p[1]-1].push_back(p[0]-1);
        }
        vector<int>  ret(N,0);
        for(int i=0;i<N;i++){
            vector<bool> status(5,false);
            for(auto j:helper[i]){
                status[ret[j]]=true;
            }
            for(int j=1;j<=4;j++){
                if(!status[j]){
                    ret[i]=j;
                    break;
                }
            }
            
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> input={{1,2},{3,4}};
    Solution so=Solution();
    vector<int> ret=so.gardenNoAdj(4, input);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
