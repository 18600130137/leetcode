//
//  main.cpp
//  79. Word Search
//
//  Created by admin on 2019/4/1.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>>  surround={{-1,0},{1,0},{0,-1},{0,1}};
    
    bool isValue(vector<vector<char>>& board,char target,int ni,int nj,int m,int n){
        if(ni>=0 && ni<m && nj>=0 && nj<n && board[ni][nj]==target){
            return true;
        }
        return false;
    }
    
    bool searched(vector<vector<char>>& board, string word,int idx,int i,int j,int m,int n){
        if(idx==word.size()){
            return true;
        }
        
        
        for(auto item:surround){
            if(isValue(board,word[idx],i+item[0],j+item[1],m,n)){
                //cout<<board[i+item[0]][j+item[1]]<<endl;
                board[i+item[0]][j+item[1]]^=255;
                //cout<<"new==="<<board[i+item[0]][j+item[1]]<<endl;
                if(searched(board,word,idx+1,i+item[0],j+item[1],m,n)){
                    return true;
                }else{
                    board[i+item[0]][j+item[1]]^=255;
                }
            }
        }
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    board[i][j]^=255;
                    if(searched(board,word,1,i,j,m,n)){
                        return true;
                    }else{
                        board[i][j]^=255;
                    }
                    
                }
            }
        }
        return false;
    }
};

// [["a","a"]]
// "aaa"

int main(int argc, const char * argv[]) {
    vector<vector<char>> input1={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string input2="ABCCED";
    Solution so=Solution();
    bool ret=so.exist(input1, input2);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
