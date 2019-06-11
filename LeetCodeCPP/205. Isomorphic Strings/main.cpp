//
//  main.cpp
//  205. Isomorphic Strings
//
//  Created by admin on 2019/6/11.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int  len=s.length();
        vector<int>  table_s(256,-1),table_t(256,-1);
        for(int i=0;i<len;i++){
            if(table_s[s[i]]!=table_t[t[i]])  return false;
            table_s[s[i]]=table_t[t[i]]=i;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution  so=Solution();
    int ret=so.isIsomorphic("egg","add");
    cout<<"The ret is:"<<ret<<endl;	
    return 0;
}
