//
//  main.cpp
//  216. Combination Sum III
//
//  Created by admin on 2019/6/18.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void  dfs(int start,int k,int n,vector<vector<int>> &nums,vector<int> &cur){
        if(start>9 || k==0){
            return;
        }
        for(int i=start;i<=9;i++){
            n-=i;
            if(n<=0){
                if(n==0 && k==1){
                    cur.push_back(i);
                    nums.push_back(cur);
                    cur.pop_back();
                }
                break;
            }else{
                cur.push_back(i);
                dfs(i+1,k-1,n,nums,cur);
                cur.pop_back();
            }
            n+=i;
        }
    }
    
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> nums;
        vector<int> cur;
        dfs(1,k,n,nums,cur);
        return nums;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<vector<int>> ret=so.combinationSum3(3, 9);
    for(auto r:ret){
        for(auto i:r){
            cout<<i<<" ";
        }
        cout<<endl;~
    }
    return 0;
}
