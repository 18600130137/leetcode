//
//  main.cpp
//  187. Repeated DNA Sequences
//
//  Created by admin on 2019/5/30.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences1(string s) {
        unordered_map<string,int> helper;
        int m=s.size();
        if(m<10){
            return {};
        }
        for(int i=0;i<=m-10;i++){
            helper[s.substr(i,10)]++;
        }
        vector<string> ret;
        for(auto item:helper){
            if(item.second>1){
                ret.push_back(item.first);
            }
        }
        return ret;
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> helper1,helper2;
        int m=s.size();
        if(m<10){
            return {};
        }
        for(int i=0;i<=m-10;i++){
            string sub=s.substr(i,10);
            if(helper1.count(sub)){
                helper2.insert(sub);
            }else{
                helper1.insert(sub);
            }
            
            
        }
        vector<string> ret(helper2.begin(),helper2.end());
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<string> ret=so.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for(auto s:ret){
        cout<<s<<" ";
    }
    cout<<endl;
    return 0;
}
