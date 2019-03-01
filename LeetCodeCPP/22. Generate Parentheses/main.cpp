//
//  main.cpp
//  22. Generate Parentheses
//
//  Created by admin on 2019/3/1.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    void parenthesisHelper(vector<string> &ret,string curr,int l,int r,int n){
        if(l==n && r==n && curr.size()==n*2){
            ret.push_back(curr);
            return;
        }
        if(l<n){
            parenthesisHelper(ret,curr+"(",l+1,r,n);
        }
        if(r<l){
            parenthesisHelper(ret,curr+")",l,r+1,n);
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        parenthesisHelper(ret,"",0,0,n);
        
        return ret;
        
    }
    
    vector<string> generateParenthesis2(int n) {
        vector<vector<string>> helper(n+1);
        helper[0]={""};
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                for(auto s1:helper[j]){
                    for(auto s2:helper[i-1-j]){
                        helper[i].push_back("("+s1+")"+s2);
                    }
                }
            }
        }
        for(auto item:helper){
            for(auto s:item){
                cout<<s<<" ";
            }
            cout<<endl;
        }
        
        return helper[n];
        
    }};


int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<string> ret=so.generateParenthesis2(3);
    cout<<endl;
    for(string s:ret){
        cout<<s<<" ";
    }
    cout<<endl;
    return 0;
}
