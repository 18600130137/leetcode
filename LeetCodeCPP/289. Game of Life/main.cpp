//
//  main.cpp
//  289. Game of Life
//
//  Created by admin on 2019/7/9.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int countAround(vector<vector<int>>& board,int x,int y,int m,int n){
        int count=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==0 && j==0)  continue;
                int sx=x+i,sy=y+j;
                if(sx>=0 && sx<m && sy>=0 && sy<n && (board[sx][sy]==1||board[sx][sy]==-1)){
                    count++;
                }
                
            }
        }
        return count;
        
    }
    
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        if(m==0){
            return;
        }
        int n=board[0].size();
        if(n==0){
            return;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    int count=countAround(board,i,j,m,n);
                    if(count<2){
                        board[i][j]=-1;
                    }else if(count<4){
                        //do nothing
                    }else{
                        board[i][j]=-1;
                    }
                }else{
                    int count=countAround(board,i,j,m,n);
                    if(count==3){
                        board[i][j]=2;
                    }
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==-1){
                    board[i][j]=0;
                }else if(board[i][j]==2){
                    board[i][j]=1;
                }
            }
        }
        
    }
};

int main(int argc, const char * argv[]){
    vector<vector<int>> input={{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    Solution so=Solution();
    so.gameOfLife(input);
    for(auto item:input){
        for(auto i:item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
