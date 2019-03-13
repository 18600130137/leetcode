//
//  main.cpp
//  40. Combination Sum II
//
//  Created by admin on 2019/3/13.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    
private:
    void search(vector<int>& candidates,vector<vector<int>> &ret,vector<int>  &box,int target,int begin){
        if(target==0){
            ret.push_back(box);
            return;
        }
        int m=candidates.size();
        for(int i=begin;i<m;i++){
            if(i>begin && candidates[i]==candidates[i-1]){
                continue;
            }
            if(target-candidates[i]>=0){
                box.push_back(candidates[i]);
                search(candidates,ret,box,target-candidates[i],i+1);
                box.pop_back();
            }else{
                return;
            }
            
        }
    }
    
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>  ret;
        vector<int>  box;
        search(candidates,ret,box,target,0);
        return ret;
    }
    
};



int main(int argc, const char * argv[]) {
    vector<int>  input={10,1,2,7,6,1,5};
    Solution so=Solution();
    vector<vector<int>> ret=so.combinationSum2(input, 8);
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
