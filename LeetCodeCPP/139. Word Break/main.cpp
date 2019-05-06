//
//  main.cpp
//  139. Word Break
//
//  Created by admin on 2019/5/6.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int m=s.size();
        unordered_set<string> helper;
        for(auto s:wordDict){
            helper.insert(s);
        }
        vector<bool> dp(m+1,false);
        dp[0]=true;
        for(int i=1;i<=m;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j] && helper.find(s.substr(j,i-j))!=helper.end()){
                    dp[i]=true;
                    break;
                }
                
            }
        }
        
        return dp[m];
    }
};

int main(int argc, const char * argv[]) {
    string input1="leetcode";
    vector<string> input2={"leet","code"};
    Solution so=Solution();
    bool ret=so.wordBreak(input1, input2);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
