//
//  main.cpp
//  14. Longest Common Prefix
//
//  Created by admin on 2019/2/26.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int m=strs.size();
        if(m==0){
            return "";
        }else if(m==1){
            return strs[0];
        }
        int i=0;
        for(;i<INT_MAX;i++){
            bool  breakInner=false;
            for(int j=1;j<m;j++){
                if(strs[j-1].size()<=i || strs[j].size()<=i || strs[j-1][i]!=strs[j][i]){
                    breakInner=true;
                    break;
                }
            }
            if(breakInner){
                break;
            }
        }
        return strs[0].substr(0,i);
    }
};

using namespace std;

int main(int argc, const char * argv[]) {
    vector<string> input={"flower","flow","flight"};
    Solution so=Solution();
    string ret=so.longestCommonPrefix(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
