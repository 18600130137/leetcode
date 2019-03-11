//
//  main.cpp
//  36. Valid Sudoku
//
//  Created by admin on 2019/3/11.
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
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            set<char>  row;
            set<char>  col;
            set<char>  sub;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(row.count(board[i][j])>0){
                        return false;
                    }else{
                        row.insert(board[i][j]);
                    }
                }
                if(board[j][i]!='.'){
                    if(col.count(board[j][i])>0){
                        return false;
                    }else{
                        col.insert(board[j][i]);
                    }
                }
                int sub_row=i/3*3+j/3;
                int sub_col=i%3*3+j%3;
                if(board[sub_row][sub_col]!='.'){
                    if(sub.count(board[sub_row][sub_col])>0){
                        return false;
                    }else{
                        sub.insert(board[sub_row][sub_col]);
                    }
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<char>> input={{'.','.','.','.','5','.','.','1','.'},{'.','4','.','3','.','.','.','.','.'},{'.','.','.','.','.','3','.','.','1'},{'8','.','.','.','.','.','.','2','.'},{'.','.','2','.','7','.','.','.','.'},{'.','1','5','.','.','.','.','.','.'},{'.','.','.','.','.','2','.','.','.'},{'.','2','.','9','.','.','.','.','.'},{'.','.','4','.','.','.','.','.','.'}};
    Solution so=Solution();
    bool ret=so.isValidSudoku(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
