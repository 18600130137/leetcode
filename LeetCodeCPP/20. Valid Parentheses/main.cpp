//
//  main.cpp
//  20. Valid Parentheses
//
//  Created by admin on 2019/2/28.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int m=s.size();
        if(m%2==1){
            return false;
        }
        stack<char> helper1;
        unordered_map<char,char> helper2={{')','('},{']','['},{'}','{'}};
        int i=0;
        for(;i<m;i++){
            char c=s[i];
            if(c=='(' || c=='[' || c=='{'){
                helper1.push(c);
            }else if(helper1.empty()){
                break;
            }else{
                char t=helper1.top();
                if(t==helper2[c]){
                    helper1.pop();
                }else{
                    break;
                }
            }
        }
        return helper1.empty() && (i==m);
    }
};


int main(int argc, const char * argv[]) {
    string input="]{";
//    string input2="([)]";
    Solution so=Solution();
    bool ret=so.isValid(input);
    cout << "isValid==="<<ret<<endl;
    return 0;
}
