//
//  main.cpp
//  132. Palindrome Partitioning II
//
//  Created by admin on 2019/4/26.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int m=s.size();
        vector<int> helper(m+1);
        for(int i=0;i<=m;i++){
            helper[i]=i-1;
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;i-j>=0 && i+j<m && s[i-j]==s[i+j];j++){
                helper[i+j+1]=min(helper[i+j+1],helper[i-j]+1);
            }
            for(int j=1;i-j+1>=0 && i+j<m && s[i-j+1]==s[i+j];j++){
                helper[i+j+1]=min(helper[i+j+1],helper[i-j+1]+1);
            }
        }
        
        return helper[m];
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.minCut("aabcacbdasdds"); //4
    cout<<"The result is:"<<ret<<endl;
    return 0;
}
