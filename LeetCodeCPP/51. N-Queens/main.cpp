//
//  main.cpp
//  51. N-Queens
//
//  Created by admin on 2019/3/20.
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
    void NQueens(vector<vector<string>> &ret,vector<int> &search,int row,int n){
        if(row==n){
            vector<string> tmp(n,string(n,'.'));
            for(int i=0;i<n;i++){
                tmp[i][search[i]]='Q';
            }
            ret.push_back(tmp);
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
            NQueens(ret,search,row+1,n);
        }
    }
    
    void NQueens1(vector<vector<string>> &ret,vector<int> &search,int row,int n,vector<int> &helper1,vector<int> &helper2,vector<int> &helper3){
        if(row==n){
            vector<string> tmp(n,string(n,'.'));
            for(int i=0;i<n;i++){
                tmp[i][search[i]]='Q';
            }
            ret.push_back(tmp);
            return;
        }
        for(int i=0;i<n;i++){
            if(helper1[i] && helper2[row+i] && helper3[row-i+n-1]){
                helper1[i]=0;
                helper2[row+i]=0;
                helper3[row-i+n-1]=0;
                search[row]=i;
                NQueens1(ret,search,row+1,n,helper1,helper2,helper3);
                helper1[i]=1;
                helper2[row+i]=1;
                helper3[row-i+n-1]=1;
            }
        }
    }


    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<int> search(n,0);
        NQueens(ret,search,0,n);
        return ret;
    }

    vector<vector<string>> solveNQueens1(int n) {
        vector<vector<string>> ret;
        vector<int> search(n,0);
        vector<int> helper1(n,1);
        vector<int> helper2(2*n,1);
        vector<int> helper3(2*n,1);
        NQueens1(ret,search,0,n,helper1,helper2,helper3);
        return ret;
    }
        
};
void  testSet(){
    set<int>  A;
    A.insert(4);
    A.insert(3);
    A.insert(3);
    A.insert(2);
    A.erase(3);
    for(auto i:A){
        cout<<i<<" ";
    }
    cout<<endl;
}


int main(int argc, const char * argv[]) {
//    testSet();
    Solution so=Solution();
    vector<vector<string>> ret=so.solveNQueens1(4);
    for(auto item:ret){
        for(string s:item){
            cout<<s<<"  "<<endl;
        }
        cout<<endl;
    }
    return 0;
}
