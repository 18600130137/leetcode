//
//  main.cpp
//  _1047. Remove All Adjacent Duplicates In String
//
//  Created by admin on 2019/5/21.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        string ret="";
        for(auto s:S){
            if(ret.size() && ret.back()==s){
                ret.pop_back();
            }else{
                ret.push_back(s);
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    string input="abbaca";
    Solution so=Solution();
    string ret=so.removeDuplicates(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
