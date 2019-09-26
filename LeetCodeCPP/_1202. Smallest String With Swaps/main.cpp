//
//  main.cpp
//  _1202. Smallest String With Swaps
//
//  Created by admin on 2019/9/26.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>>   adjMap;
    vector<bool>   visited;
    vector<int>   localIndex;
    string   localStr="";
    
    void  dfs(string &s,int idx){
        visited[idx]=true;
        localIndex.push_back(idx);
        localStr+=s[idx];
        for(auto  id:adjMap[idx]){
            if(!visited[id]){
                dfs(s,id);
            }
        }
    }
    
    
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        adjMap.resize(n);
        visited.resize(n,false);
        for(auto  p:pairs){
            adjMap[p[0]].push_back(p[1]);
            adjMap[p[1]].push_back(p[0]);
        }
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(s,i);
                sort(localIndex.begin(),localIndex.end());
                sort(localStr.begin(),localStr.end());
                for(int j=0;j<localIndex.size();j++){
                    s[localIndex[j]]=localStr[j];
                }
                localStr="";
                localIndex.clear();
            }
        }
        
        return s;
        
    }
};
int main(int argc, const char * argv[]) {
    string input1="dcab";
    vector<vector<int>> input2={{0,3},{1,2}};
    Solution so=Solution();
    string ret=so.smallestStringWithSwaps(input1, input2);
    cout<<"The smallest string is:"<<ret<<endl;
    return 0;
}
