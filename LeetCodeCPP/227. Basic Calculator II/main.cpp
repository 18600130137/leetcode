//
//  main.cpp
//  227. Basic Calculator II
//
//  Created by admin on 2019/6/21.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int num=0;
        char sign='+';
        stack<int> helper;
        int s_len=s.size();
        for(int i=0;i<s_len;i++){
            char c=s[i];
            if(c>='0' && c<='9'){
                num=num*10+(c-'0');
            }
            if(c=='+' || c=='-' || c=='*' || c=='/' || i==s_len-1){
                if(sign=='+'){
                    helper.push(num);
                }else if(sign=='-'){
                    helper.push(-num);
                }else if(sign=='*'){
                    int top=helper.top();
                    helper.pop();
                    helper.push(top*num);
                }else if(sign=='/'){
                    int top=helper.top();
                    helper.pop();
                    helper.push(top/num);
                }
                num=0;
                sign=c;
            }
        }
        int ret=0;
        while(!helper.empty()){
            ret+=helper.top();
            helper.pop();
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    string  input="3+2*2";
    Solution so=Solution();
    int ret=so.calculate(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
