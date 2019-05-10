//
//  main.cpp
//  150. Evaluate Reverse Polish Notation
//
//  Created by admin on 2019/5/10.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
private:
    bool isNumber(string s){
        int m=s.size();
        if(m==1){
            if(s[0]>='0' && s[0]<='9'){
                return true;
            }
        }else if(s[1]>='0' && s[1]<='9'){
            return true;
        }
        return false;
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> helper;
        
        for(string s:tokens){
            if(isNumber(s)){
                helper.push(stoi(s));
            }else{
                int num2=helper.top();
                helper.pop();
                int num1=helper.top();
                helper.pop();
                if(s=="+"){
                    helper.push(num1+num2);
                }else if(s=="-"){
                    helper.push(num1-num2);
                }else if(s=="*"){
                    helper.push(num1*num2);
                }else if(s=="/"){
                    helper.push(num1/num2);
                }
            }
        }
        return helper.top();
    }
};
int main(int argc, const char * argv[]) {
    vector<string> input={"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    Solution so=Solution();
    int ret=so.evalRPN(input);
    cout<<"The ret is :"<<ret<<endl;
    return 0;
}
