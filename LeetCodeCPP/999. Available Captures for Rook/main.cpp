//
//  main.cpp
//  999. Available Captures for Rook
//
//  Created by admin on 2019/2/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int m=8,canEat=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='R'){
                    vector<vector<int>> surrends={{-1,0},{1,0},{0,-1},{0,1}};
                    for(auto  s:surrends){
                        int i_=i,j_=j;
                        while(i_+s[0]>=0 && i_+s[0]<m && j_+s[1]>=0 && j_+s[1]<m && board[i_+s[0]][j_+s[1]]=='.'){
                            i_+=s[0];
                            j_+=s[1];
                        }
                        if(i_+s[0]>=0 && i_+s[0]<m && j_+s[1]>=0 && j_+s[1]<m && board[i_+s[0]][j_+s[1]]=='p'){
                            canEat++;
                        }
                    }
                    return canEat;
                    
                }
            }
        }
        
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<char>> input1={{'.','.','.','.','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'p','p','.','R','.','p','B','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','B','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','.','.','.','.','.'}};
    Solution so=Solution();
    int ret=so.numRookCaptures(input1);
    cout<<"The ret is :"<<ret<<endl;
    
    return 0;
}
