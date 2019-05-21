//
//  main.cpp
//  _1048. Longest String Chain
//
//  Created by admin on 2019/5/21.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int>  dp;
        sort(words.begin(),words.end(),[](string w1,string w2){
            return w1.size()<w2.size();
        });
        for(int i=0;i<words.size();i++){
            int maxTerm=1;
            for(int j=0;j<words[i].size();j++){
                string tmp=words[i];
                tmp.erase(tmp.begin()+j,tmp.begin()+j+1);
                //cout<<"tmp==="<<tmp<<"==="<<dp.count(tmp)<<endl;
                if(dp.count(tmp)){
                    //cout<<"fist=="<<dp[tmp]<<endl;
                    maxTerm=max(maxTerm,dp[tmp]+1);
                }else{
                    //cout<<"second=="<<endl;
                    maxTerm=max(maxTerm,1);
                }
                //cout<<"maxTerm==="<<maxTerm<<endl;
            }
            //cout<<words[i]<<"=="<<maxTerm<<endl<<endl;
            dp[words[i]]=maxTerm;
        }
        
        int maxRet=0;
        for(auto item:dp){
            maxRet=max(maxRet,item.second);
        }
        return maxRet;
    }
};

int main(int argc, const char * argv[]) {
    vector<string> input={"a","b","ba","bca","bda","bdca"};
    Solution so=Solution();
    int ret=so.longestStrChain(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
