//
//  main.cpp
//  _1092. Shortest Common Supersequence
//
//  Created by admin on 2019/6/17.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    string  maxCommon(string str1,string str2){
        int m=str1.size(),n=str2.size();
        vector<vector<string>>  dp(m+1,vector<string>(n+1,""));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(str1[i]==str2[j]){
                    dp[i+1][j+1]=dp[i][j]+str1[i];
                }else{
                    dp[i+1][j+1]=dp[i+1][j].size()>dp[i][j+1].size()?dp[i+1][j]:dp[i][j+1];
                }
            }
        }
        return dp[m][n];
    }
    
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string common=maxCommon(str1,str2);
        //cout<<"The max common is:"<<common<<endl;
        int i=0,j=0;
        stringstream ss;
        for(auto c:common){
            while(str1[i]!=c){
                ss<<str1[i];
                i++;
            }
            while(str2[j]!=c){
                ss<<str2[j];
                j++;
            }
            ss<<c;
            i++;
            j++;
        }
        ss<<str1.substr(i);
        ss<<str2.substr(j);
        return ss.str();
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    string sc=so.shortestCommonSupersequence("abac","cabc");
    cout<<"The result is:"<<sc<<endl;
    return 0;
}
