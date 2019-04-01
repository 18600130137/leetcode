//
//  main.cpp
//  _1020. Number of Enclaves
//
//  Created by admin on 2019/4/1.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
private:
    vector<vector<int>>  surround={{-1,0},{1,0},{0,-1},{0,1}};
    
    bool isValue(vector<vector<int>>& A,int ni,int nj,int m,int n){
        if(ni>=0 && ni<m && nj>=0 && nj<n && A[ni][nj]==1){
            return true;
        }
        return false;
    }
    
    void dyeing(vector<vector<int>>& A,int i,int j,int m,int n){
        queue<pair<int,int>> helper;
        helper.push(make_pair(i,j));
        while(!helper.empty()){
            pair<int,int> front=helper.front();
            helper.pop();
            for(auto item:surround){
                if(isValue(A,front.first+item[0],front.second+item[1],m,n)){
                    A[front.first+item[0]][front.second+item[1]]=0;                                                  helper.push(make_pair(front.first+item[0],front.second+item[1]));
                }
            }
        }
    }
    
    
public:
    int numEnclaves(vector<vector<int>>& A) {
        int m=A.size();
        int n=A[0].size();
        for(int i=0;i<m;i++){
            if(A[i][0]==1){
                A[i][0]=0;
                dyeing(A,i,0,m,n);
            }
            if(A[i][n-1]==1){
                A[i][n-1]=0;
                dyeing(A,i,n-1,m,n);
            }
        }
        
        for(int i=1;i<n-1;i++){
            if(A[0][i]==1){
                A[0][i]=0;
                dyeing(A,0,i,m,n);
            }
            
            if(A[m-1][i]==1){
                A[m-1][i]=0;
                dyeing(A,m-1,i,m,n);
            }
        }
        
        int ret=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(A[i][j]==1){
                    ret++;
                }
            }
        }
        return ret;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> input={{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    Solution so=Solution();
    int ret=so.numEnclaves(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
