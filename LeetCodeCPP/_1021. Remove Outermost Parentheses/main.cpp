//
//  main.cpp
//  _1021. Remove Outermost Parentheses
//
//  Created by admin on 2019/4/8.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        int left=0;
        string ret="";
        int m=S.size();
        for(int i=0;i<m;i++){
            if(S[i]=='('){
                if(left>0){
                    ret+=S[i];
                }
                left++;
            }else{
                left--;
                if(left>0){
                    ret+=S[i];
                }
            }
        }
        return ret;
        
    }
};
int main(int argc, const char * argv[]) {
    string input="(()())(())";
    Solution so=Solution();
    string ret=so.removeOuterParentheses(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
