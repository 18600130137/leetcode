//
//  main.cpp
//  32. Longest Valid Parentheses
//
//  Created by admin on 2019/3/7.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>  helper;
        int m=s.size();
        int longest=0;
        for(int i=0;i<m;i++){
            if(s[i]=='('){
                helper.push(i);
            }else if(!helper.empty()){
                int top=helper.top();
                if(s[top]=='('){
                    helper.pop();
                }else{
                    helper.push(i);
                }
                
            }else{
                helper.push(i);
            }
        }
        if(helper.empty()){
            longest=m;
        }else{
            int a=m,b=0;
            while(!helper.empty()){
                int b=helper.top();
                helper.pop();
                longest=max(longest,a-b-1);
                a=b;
            }
            longest=max(longest,a);
        }
        return longest;
    }
};

int main(int argc, const char * argv[]) {
    string input="((()()";
    Solution so=Solution();
    int ret=so.longestValidParentheses(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
