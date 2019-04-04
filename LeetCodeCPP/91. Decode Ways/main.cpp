//
//  main.cpp
//  91. Decode Ways
//
//  Created by admin on 2019/4/4.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int m=s.size();
        if(m==0){
            return 0;
        }
        vector<int> helper(m+1,0);
        helper[m]=1;
        helper[m-1]=(s[m-1]=='0'?0:1);
        for(int i=m-2;i>=0;i--){
            if(s[i]=='0'){
                continue;
            }
            if(stoi(s.substr(i,2))<=26){
                helper[i]=helper[i+1]+helper[i+2];
            }else{
                helper[i]=helper[i+1];
            }
        }
        
        return helper[0];
    }
};


int main(int argc, const char * argv[]) {
    string input="226";
    Solution so=Solution();
    int ret=so.numDecodings(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
