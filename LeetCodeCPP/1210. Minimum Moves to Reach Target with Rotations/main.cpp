//
//  main.cpp
//  1210. Minimum Moves to Reach Target with Rotations
//
//  Created by admin on 2019/10/16.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include  <queue>
#include <unordered_set>
using namespace std;

class Solution {
private:
    string  vector2str(vector<vector<int>>  &snake){
        return to_string(snake[0][0])+"$"+to_string(snake[0][1])+"$"+to_string(snake[1][0])+"$"+to_string(snake[1][1]);
    }
    
    
    bool  isVisited(unordered_set<string>  &visited,vector<vector<int>> &snake){
        return visited.count(vector2str(snake))>0;
    }
    
    bool   canRotate(vector<vector<int>>& grid,int i,int j,int n){
        return  i<n-1 && j<n-1 && (grid[i+1][j]&1)==0 && (grid[i][j+1]&1)==0 && (grid[i+1][j+1]&1)==0;
    }
    
    bool canDown(vector<vector<int>>& grid,int i,int j,int isVertical,int n){
        if(isVertical){
            return i<n-2  && (grid[i+2][j]&1)==0;
        }else{
            return i<n-1 && (grid[i+1][j]&1)==0 && (grid[i+1][j+1]&1)==0;
        }
    }
    
    bool canRight(vector<vector<int>>& grid,int i,int j,int isVertical,int n){
        if(isVertical){
            return j<n-1 && (grid[i][j+1]&1)==0 && (grid[i+1][j+1]&1)==0;
        }else{
            return j<n-2 && (grid[i][j+2]&1)==0;
        }
    }
public:
    int minimumMoves1(vector<vector<int>>& grid) {
        
        vector<vector<int>> start(2);
        start[0]={0,0};
        start[1]={0,1};
        int n=grid.size();
        queue<vector<vector<int>>>  q;
        q.push(start);
        int step=0;
        unordered_set<string>  visited;
        visited.insert(vector2str(start));
        while(!q.empty()){
            int ss=q.size();
            for(int i=0;i<ss;i++){
                vector<vector<int>> snake=q.front();
                q.pop();
                // cout<<snake[0][0]<<","<<snake[0][1]<<"  "<<snake[1][0]<<","<<snake[1][1]<<",step=="<<step<<endl;
                if(snake[0][0]==n-1 && snake[1][0]==n-1 && snake[0][1]==n-2 && snake[1][1]==n-1){
                    return step;
                }
                if(snake[0][0]-snake[1][0]==0){  //水平
                    if(snake[0][0]+1<n && grid[snake[0][0]+1][snake[0][1]]!=1 && grid[snake[0][0]+1][snake[0][1]+1]!=1){
                        vector<vector<int>> newStep={snake[0],{snake[0][0]+1,snake[0][1]}};
                        if(!isVisited(visited,newStep)){
                            visited.insert(vector2str(newStep));
                            q.push(newStep);
                        }
                        
                        
                        
                        vector<vector<int>> newStep1={{snake[0][0]+1,snake[0][1]},{snake[1][0]+1,snake[1][1]}};
                        if(!isVisited(visited,newStep1)){
                            visited.insert(vector2str(newStep1));
                            q.push(newStep1);
                        }
                    }
                    if(snake[0][1]+2<n && grid[snake[0][0]][snake[0][1]+2]!=1){
                        vector<vector<int>> newStep={snake[1],{snake[0][0],snake[0][1]+2}};
                        if(!isVisited(visited,newStep)){
                            visited.insert(vector2str(newStep));
                            q.push(newStep);
                        }
                    }
                }else{  //垂直
                    if(snake[0][1]+1<n && grid[snake[0][0]][snake[0][1]+1]!=1 && grid[snake[0][0]+1][snake[0][1]+1]!=1){
                        vector<vector<int>> newStep={snake[0],{snake[0][0],snake[0][1]+1}};
                        if(!isVisited(visited,newStep)){
                            visited.insert(vector2str(newStep));
                            q.push(newStep);
                        }
                        vector<vector<int>>  newStep1={{snake[0][0],snake[0][1]+1},{snake[1][0],snake[1][1]+1}};
                        if(!isVisited(visited,newStep1)){
                            visited.insert(vector2str(newStep1));
                            q.push(newStep1);
                        }
                    }
                    
                    if(snake[0][0]+2<n && grid[snake[0][0]+2][snake[0][1]]!=1){
                        vector<vector<int>> newStep={snake[1],{snake[0][0]+2,snake[0][1]}};
                        if(!isVisited(visited,newStep)){
                            visited.insert(vector2str(newStep));
                            q.push(newStep);
                        }
                    }
                    
                }
            }
            if(!q.empty()){
                step++;
            }
            
        }
        
        return -1;
    }
    
    int minimumMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<vector<int>>  my_q;
        my_q.push({0,0,0});
        int step=0;
        while(!my_q.empty()){
            int size=my_q.size();
            for(int i=0;i<size;i++){
                vector<int> snake=my_q.front();
                my_q.pop();
                if(snake[0]==n-1 && snake[1]==n-2){
                    return step;
                }
                if((grid[snake[0]][snake[1]] & (snake[2]? 2:4))==0){
                    grid[snake[0]][snake[1]]|=snake[2]? 2:4;
                    if(canRotate(grid,snake[0],snake[1],n)){
                            my_q.push({snake[0],snake[1],snake[2]==0?1:0});
                    }
                    if(canDown(grid,snake[0],snake[1],snake[2],n)){
                        my_q.push({snake[0]+1,snake[1],snake[2]});
                    }
                    if(canRight(grid,snake[0],snake[1],snake[2],n)){
                        my_q.push({snake[0],snake[1]+1,snake[2]});
                    }
                }
        }
        if(!my_q.empty()){
            step++;
        }
    }
    
    return -1;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>>  input={{0,0,0,0,0,1},
                             {1,1,0,0,1,0},
                             {0,0,0,0,1,1},
                             {0,0,1,0,1,0},
                             {0,1,1,0,0,0},
                             {0,1,1,0,0,0}};
    
    Solution so=Solution();
    int step=so.minimumMoves(input);
    cout<<"The min step is:"<<step<<endl;
    return 0;
}
