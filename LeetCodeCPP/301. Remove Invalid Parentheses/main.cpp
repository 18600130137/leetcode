//
//  main.cpp
//  301. Remove Invalid Parentheses
//
//  Created by admin on 2019/7/11.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
private:
    bool  isValid(string s){
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
            }else if(s[i]==')'){
                count--;
            }
            if(count<0){
                return false;
            }
        }
        return count==0;
    }
    
    void  remove(string s,int last_i,int last_j,vector<char> brackets,vector<string> &ans){
        int count=0;
        for(int i=last_i;i<s.size();i++){
            if(s[i]==brackets[0]){
                count++;
            }else if(s[i]==brackets[1]){
                count--;
            }
            if(count>=0){
                continue;
            }
            for(int j=last_j;j<=i;j++){
                if(s[j]==brackets[1] &&(j==last_j || s[j]!=s[j-1])){
                    remove(s.substr(0,j)+s.substr(j+1),i,j,brackets,ans);
                }
            }
            return;
        }
        string rev=string(s.rbegin(),s.rend());
        if(brackets[0]=='('){
            remove(rev,0,0,{')','('},ans);
        }else{
            ans.push_back(rev);
        }
        
        
    }
    
    
public:
    vector<string> removeInvalidParentheses1(string s) {
        unordered_set<string>  visited;
        visited.insert(s);
        queue<string> helper;
        helper.push(s);
        vector<string> ret;
        bool isFound=false;
        while(!helper.empty()){
            string front=helper.front();
            helper.pop();
            if(isValid(front)){
                ret.push_back(front);
                isFound=true;
            }
            if(isFound){
                continue;
            }
            for(int i=0;i<front.size();i++){
                if(front[i]!='(' && front[i]!=')'){
                    continue;
                }
                string newStr=front.substr(0,i)+front.substr(i+1);
                if(!visited.count(newStr)){
                    helper.push(newStr);
                    visited.insert(newStr);
                }
                
            }
            
        }
        
        return ret;
    }
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        remove(s,0,0,{'(',')'},ans);
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    string input="()())()";
    Solution so=Solution();
    vector<string> ret=so.removeInvalidParentheses(input);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
