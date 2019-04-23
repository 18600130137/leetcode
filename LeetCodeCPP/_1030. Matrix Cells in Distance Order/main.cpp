//
//  main.cpp
//  _1030. Matrix Cells in Distance Order
//
//  Created by admin on 2019/4/23.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
private:
    bool  isValue(int x,int y,int R, int C,unordered_set<string> &visited){
        if(x>=0 && x<R && y>=0 && y<C && visited.find(to_string(x)+" "+to_string(y))==visited.end()){
            return true;
        }
        return false;
    }
    
public:
    vector<vector<int>> allCellsDistOrder1(int R, int C, int r0, int c0) {
        vector<vector<int>> ret;
        unordered_set<string> visited;
        queue<vector<int>> helper;
        vector<int> start={r0,c0};
        helper.push(start);
        ret.push_back(start);
        visited.insert(to_string(r0)+" "+to_string(c0));
        vector<vector<int>> surrounds={{-1,0},{1,0},{0,-1},{0,1}};
        while(!helper.empty()){
            vector<int> f=helper.front();
            helper.pop();
            for(auto item:surrounds){
                int x=f[0]+item[0],y=f[1]+item[1];
                if(isValue(x,y,R,C,visited)){
                    visited.insert(to_string(x)+" "+to_string(y));
                    ret.push_back({x,y});
                    helper.push({x,y});
                }
            }
            
        }
        
        return ret;
    }
    
    
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<vector<int>>> helper(R+C+1);
        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                int dis=abs(i-r0)+abs(j-c0);
                helper[dis].push_back({i,j});
            }
        }
        vector<vector<int>> ret;
        for(auto item:helper){
            for(auto i:item){
                ret.push_back(i);
            }
        }
        
        
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<vector<int>> ret= so.allCellsDistOrder1(2, 2, 0, 1);
    for (auto item:ret) {
        for(auto i:item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
