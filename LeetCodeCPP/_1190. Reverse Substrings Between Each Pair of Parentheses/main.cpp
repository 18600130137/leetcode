//
//  main.cpp
//  _1190. Reverse Substrings Between Each Pair of Parentheses
//
//  Created by admin on 2019/9/16.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(auto  c:s){
            if(c==')'){
                queue<char> tmp;
                while(!st.empty() && st.top()!='('){
                    tmp.push(st.top());
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
                while(!tmp.empty()){
                    st.push(tmp.front());
                    tmp.pop();
                }
            }else{
                st.push(c);
            }
        }
        stringstream ss;
        while(!st.empty()){
            ss<<st.top();
            st.pop();
        }
        string ret=ss.str();
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    string ret=so.reverseParentheses("a(bcdefghijkl(mno)p)q");
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
