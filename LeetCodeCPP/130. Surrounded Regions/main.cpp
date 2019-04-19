//
//  main.cpp
//  130. Surrounded Regions
//
//  Created by admin on 2019/4/19.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    void check(vector<vector<char>>& board,int x,int y,int m,int n){
        if(board[x][y]=='O'){
            board[x][y]='1';
            if(x>1){
                check(board,x-1,y,m,n);
            }
            if(x<m-1){
                check(board,x+1,y,m,n);
            }
            if(y>1){
                check(board,x,y-1,m,n);
            }
            if(y<n-1){
                check(board,x,y+1,m,n);
            }
        }
        
    }
    
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0 || board[0].size()==0){
            return;
        }
        int m=board.size(),n=board[0].size();
        if(m<=2 || n<=2){
            return;
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                board[i][0]='1';
                check(board,i,1,m,n);
            }
            if(board[i][n-1]=='O'){
                board[i][n-1]='1';
                check(board,i,n-2,m,n);
            }
        }
        
        for(int i=1;i<n-1;i++){
            if(board[0][i]=='O'){
                board[0][i]='1';
                check(board,1,i,m,n);
            }
            if(board[m-1][i]=='O'){
                board[m-1][i]='1';
                check(board,m-2,i,m,n);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='1'){
                    board[i][j]='O';
                }
            }
        }
    }
    
    
};

int main(int argc, const char * argv[]) {
    vector<vector<char>> input={{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    Solution so=Solution();
    so.solve(input);
    for(auto item:input){
        for(auto s:item){
            cout<<s<<" ";
        }
        cout<<endl;
    }
    return 0;
}
