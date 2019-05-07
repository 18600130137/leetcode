//
//  main.cpp
//  140. Word Break II
//
//  Created by admin on 2019/5/7.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
    unordered_map<string,vector<string>>  mem;
    
    bool startsWith(string s, string sub){
        return s.find(sub)==0;
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(mem.count(s)){
            return mem[s];
        }
        vector<string> res;
        if(s.size()==0){
            res.push_back("");
            return res;
        }
        int m=s.size();
        for(auto w:wordDict){
            if(startsWith(s,w)){
                vector<string> subList=wordBreak(s.substr(w.size()),wordDict);
                for(auto sub:subList){
                    res.push_back(w+(sub==""?"":" ")+sub);
                }
            }
            
        }
        mem[s]=res;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    string input1="catsanddog";
    vector<string> input2={"cat","cats","and","sand","dog"};
    Solution so=Solution();
    vector<string> ret=so.wordBreak(input1, input2);
    for(auto  r:ret){
        cout<<r<<endl;
    }
    cout<<endl;
    return 0;
}
