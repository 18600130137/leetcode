//
//  main.cpp
//  49. Group Anagrams
//
//  Created by admin on 2019/3/19.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
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
    long   getKey(string  s){
        long result=1;
        for(char c:s){
            int n=c-'a'+1;
            result=result*(n*n+n+41)%INT_MAX;
        }
        return result;
    }
    
public:
    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        unordered_map<string,vector<string>> helper;
        int m=strs.size();
        for(int i=0;i<m;i++){
            string tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            if(helper.count(tmp)>0){
                helper[tmp].push_back(strs[i]);
            }else{
                vector<string>  v={strs[i]};
                helper[tmp]=v;
            }
        }
        vector<vector<string>> ret;
        for(auto item:helper){
            ret.push_back(item.second);
        }
        return ret;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<long,int> helper;
        vector<vector<string>>  ret;
        int m=strs.size();
        for(int i=0;i<m;i++){
            int key=getKey(strs[i]);
            if(helper.count(key)>0){
                ret[helper[key]].push_back(strs[i]);
            }else{
                vector<string> tmp={strs[i]};
                ret.push_back(tmp);
                helper[key]=ret.size()-1;
            }
        }
        
        return ret;
    }
    
    
    
    
    
};
//["cab","tin","pew","duh","may","ill","buy","bar","max","doc"]

int main(int argc, const char * argv[]) {
    vector<string> input={"cab","tin","pew","duh","may","ill","buy","bar","max","doc"};
    Solution so=Solution();
    vector<vector<string>> ret=so.groupAnagrams(input);
    for(auto item:ret){
        for (auto i:item) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
