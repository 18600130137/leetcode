//
//  main.cpp
//  _1003. Check If Word Is Valid After Substitutions
//
//  Created by admin on 2019/3/4.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string S) {
        int index=(int)S.find("abc");
        if(index==string::npos){
            return S.size()==0;
        }
        return isValid(S.substr(0,index)+S.substr(index+3));
    }
};


int main(int argc, const char * argv[]) {
    string input="abccba";
    string input1="abcabcababcc";
    Solution so=Solution();
    bool  ret= so.isValid(input1);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
