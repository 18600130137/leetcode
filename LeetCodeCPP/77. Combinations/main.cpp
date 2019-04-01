//
//  main.cpp
//  77. Combinations
//
//  Created by admin on 2019/4/1.
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
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int>  v(k,0);
        int i=0;
        while(i>=0){
            v[i]++;
            if(v[i]>n){
                i--;
            }else if(i==k-1){
                ret.push_back(v);
            }else{
                i++;
                v[i]=v[i-1];
            }
        }
        return ret;
        
    }
    
    
    vector<int> per;
    vector< vector<int> > ans;
    vector< vector<int> > combine1(int n, int k) {
        ans.clear();
        per.resize(k);
        generateCombine(n,k,1);
        return ans;
    }
    void generateCombine(int n, int k, int start) {
        if (k==0)
        {
            ans.push_back(per);
            return ;
        }
        for(int i=start;i<=n;i++)
        {
            per[start-1] = i;
            generateCombine(n,k-1,i+1);
        }
    }
    
    
};



int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<vector<int>> ret=so.combine(4, 2);
    for(auto item:ret){
        for(auto i:item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
