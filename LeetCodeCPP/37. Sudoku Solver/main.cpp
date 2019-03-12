//
//  main.cpp
//  37. Sudoku Solver
//
//  Created by admin on 2019/3/12.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
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
    bool  isValid(vector<vector<char>>& board,int i,int j,int k){
        for(int m=0;m<9;m++){
            if(board[i][m]==k){
                return false;
            }
            if(board[m][j]==k){
                return false;
            }
            int x=i/3*3+m/3;
            int y=j/3*3+m%3;
            if(board[x][y]==k){
                return false;
            }
            
        }
        return true;
    }
    
    set<char>  getOtherSet(vector<vector<char>>& board,int i,int j){
        set<char> helper;
        for(int m=0;m<9;m++){
            helper.insert(board[i][m]);
            helper.insert(board[m][j]);
            int x=i/3*3+m/3;
            int y=j/3*3+m%3;
            helper.insert(board[x][y]);
        }
        return helper;
    }
    
    
    
    
    bool  solve1(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(isValid(board,i,j,k)){
                            board[i][j]=k;
                            if(solve1(board)){
                                return true;
                            }
                            board[i][j]='.';
                        }
                        
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool  solve2(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    set<char> otherSet=getOtherSet(board,i,j);
                    if(otherSet.size()==0){
                        return false;
                    }
                    for(char k='1';k<='9';k++){
                        if(otherSet.count(k)==0){
                            board[i][j]=k;
                            if(solve2(board)){
                                return true;
                            }
                            board[i][j]='.';
                        }
                        
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    
    bool  solve(vector<vector<char>>& board,int i,int j){
        for(;i<9;i++,j=0){
            for(;j<9;j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(isValid(board,i,j,k)){
                            board[i][j]=k;
                            int x=0,y=0;
                            if(j+1>=9){
                                x=i+1;
                                y=0;
                            }else{
                                x=i;
                                y=j+1;
                            }
                            if(solve(board,x,y)){
                                return true;
                            }
                            board[i][j]='.';
                        }
                        
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};


int main(int argc, const char * argv[]) {
    vector<vector<char>> input={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    
    Solution so=Solution();
    so.solveSudoku(input);
    for(int i=0;i<input.size();i++){
        for(int j=0;j<input[0].size();j++){
            cout<<input[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
