//
//  main.cpp
//  32. Longest Valid Parentheses
//
//  Created by admin on 2019/3/7.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
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
    //O(2n)
    int longestValidParentheses1(string s) {
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
    
    //O(n)  dp solution
    int longestValidParentheses(string s) {
        stack<int>  helper;
        int m=s.size();
        vector<int>  longest(m,0);
        int ret=0;
        for(int i=1;i<m;i++){
            if(s[i]==')' && i-longest[i-1]-1>=0 && s[ i-longest[i-1]-1]=='('){
                longest[i]=longest[i-1]+2+(i-longest[i-1]-2>=0?longest[i-longest[i-1]-2]:0);
                ret=max(ret,longest[i]);
            }
        }
        return ret;
    }
};
//"()(()"
int main(int argc, const char * argv[]) {
    string input="((()()";
    Solution so=Solution();
    int ret=so.longestValidParentheses(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
