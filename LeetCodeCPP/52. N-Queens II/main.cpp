//
//  main.cpp
//  52. N-Queens II
//
//  Created by admin on 2019/3/21.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
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
    void NQueens(int &count,vector<int> &search,int row,int n){
        if(row==n){
            count++;
            return;
        }
        for(int i=0;i<n;i++){
            if(row>0){
                bool isWrong=false;
                for(int j=0;j<row;j++){
                    if(i==search[j] || abs(i-search[j])==row-j){
                        isWrong=true;
                        break;
                    }
                }
                if(isWrong){
                    continue;
                }
            }
            search[row]=i;
            NQueens(count,search,row+1,n);
        }
    }
    
    
    
public:
    int totalNQueens(int n) {
        int count=0;
        vector<int> search(n,0);
        NQueens(count,search,0,n);
        return count;
    }
};




int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.totalNQueens(8);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
