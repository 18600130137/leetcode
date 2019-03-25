//
//  main.cpp
//  _1023. Binary String With Substrings Representing 1 To N
//
//  Created by admin on 2019/3/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool queryString(string S, int N) {
        for(int i=N;i>N/2;i--){
            string bstr=bitset<32>(i).to_string();
            if(S.find(bstr.substr(bstr.find("1")))==string::npos){
                return false;
            }
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    bool ret=so.queryString("0110",3);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
