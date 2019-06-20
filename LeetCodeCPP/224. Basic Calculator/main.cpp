//
//  main.cpp
//  224. Basic Calculator
//
//  Created by admin on 2019/6/20.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> helper;
        int sign=1;
        int ret=0;
        int num=0;
        helper.push(sign);
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c>='0' && c<='9'){
                num=num*10+(c-'0');
            }else if(c=='+' || c=='-'){
                ret+=sign*num;
                num=0;
                sign=helper.top()*(c=='+'?1:-1);
            }else if(c=='('){
                helper.push(sign);
            }else if(c==')'){
                helper.pop();
            }
        }
        ret+=num*sign;
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    string input="(1+(4+5+2)-3)+(6+8)";
    Solution so=Solution();
    int ret=so.calculate(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
