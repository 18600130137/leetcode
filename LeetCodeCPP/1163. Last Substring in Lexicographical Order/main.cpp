//
//  main.cpp
//  1163. Last Substring in Lexicographical Order
//
//  Created by admin on 2019/8/19.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string lastSubstring(string s) {
        int m=s.size();
        int idx=0,step=0;
        for(int i=1;i<m;i++){
            for(step=0;step+i<m;step++){
                if(s[idx+step]==s[i+step]) continue;
                idx=s[idx+step]<s[i+step]?i:idx;
                break;
            }
            if(step+i==m){
                break;
            }
        }
        return s.substr(idx);
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    string ret=so.lastSubstring("leetcode");
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
