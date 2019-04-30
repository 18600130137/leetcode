//
//  main.cpp
//  _1036. Escape a Large Maze
//
//  Created by admin on 2019/4/28.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
private:
    int Edge=1000000;
    
    bool isValue(int x,int y,unordered_set<string> &blocked_set){
        if(x>=0 && x<Edge && y>=0 && y<Edge && blocked_set.find(to_string(x)+" "+to_string(y))==blocked_set.end()){
            return true;
        }
        return false;
    }
    
    int  check(vector<vector<int>> blocked, vector<int>& source, vector<int>& target){
        unordered_set<string> blocked_set;
        for(auto item:blocked){
            blocked_set.insert(to_string(item[0])+" "+to_string(item[1]));
        }
        queue<vector<int>> helper;
        helper.push(source);
        blocked_set.insert(to_string(source[0])+" "+to_string(source[1]));
        vector<vector<int>>  surround={{-1,0},{1,0},{0,-1},{0,1}};
        int level=0;
        while(!helper.empty()){
            int S=helper.size();
            for(int i=0;i<S;i++){
                vector<int> f=helper.front();
                helper.pop();
                for(auto su:surround){
                    int x=f[0]+su[0],y=f[1]+su[1];
                    if(x==target[0] && y==target[1]){
                        return 1;
                    }
                    if(isValue(x,y,blocked_set)){
                        blocked_set.insert(to_string(x)+" "+to_string(y));
                        helper.push({x,y});
                    }
                }
            }
            level++;
            if(level>=blocked.size()){
                return -1;
            }
            
        }
        
        return 0;
    }
    
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if(blocked.size()==0){
            return true;
        }
        return check(blocked,source,target)!=0;
        int check1=check(blocked,source,target);
        if(check1==1){
            return true;
        }else if(check1==0){
            return false;
        }else{
            return check(blocked,target,source)!=-1;
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> block={{0,1},{1,0}};
    vector<int> start={0,0};
    vector<int>  end={0,2};
    Solution so=Solution();
    bool ret=so.isEscapePossible(block,start, end);
    std::cout << "The ret is:"<<ret<<endl;
    return 0;
}
