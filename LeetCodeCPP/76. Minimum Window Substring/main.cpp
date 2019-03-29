//
//  main.cpp
//  76. Minimum Window Substring
//
//  Created by admin on 2019/3/29.
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
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        if(m==0 || n==0 || m<n){
            return "";
        }
        vector<int>   map(128,0);
        for(int i=0;i<n;i++){
            map[t[i]]++;
        }
        int slow=0,fast=slow,min_len=INT_MAX,head=0;
        string ret="";
        while(fast<m){
            if(map[s[fast++]]-->0){
                n--;
            }
            while(n==0){
                if(min_len>fast-slow){
                    min_len=fast-slow;
                    head=slow;
                }
                if(map[s[slow++]]++==0){
                    n++;
                }
            }
        }
        
        return min_len==INT_MAX?"":s.substr(head,min_len);
        
    }
};


int main(int argc, const char * argv[]) {
    string input1="ADOBECODEBANC";
    string input2="ABC";
    Solution so=Solution();
    string ret=so.minWindow(input1, input2);
    cout<<"The ret is:"<<ret<<endl;
    
    return 0;
}
