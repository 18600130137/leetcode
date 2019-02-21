//
//  main.cpp
//  3. Longest Substring Without Repeating Characters
//
//  Created by admin on 2019/2/21.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
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
     int lengthOfLongestSubstring1(string s) {
         int m=s.size();
         if(m<=1){
             return m;
         }
         int maxLen=0,last=-1;
         unordered_map<int,int>  helper;
         for(int i=0;i<m;i++){
             if(helper.count(s[i])>0){
                 last=max(last,helper[s[i]]+1);
             }
             maxLen=max(maxLen,i-last);
             helper[s[i]]=i;
         }
         return maxLen;
     }

      int lengthOfLongestSubstring2(string s) {
         int m=s.size();
         if(m<=1){
             return m;
         }
         int maxLen=0,last=0;
         vector<int>  helper(256,-1);
         for(int i=0;i<m;i++){
             if(helper[s[i]]+1>last){
                 last=helper[s[i]]+1;
             }
             maxLen=max(maxLen,i-last+1);
             helper[s[i]]=i;
         }
         return maxLen;
     }
    
    
    int lengthOfLongestSubstring(string s) {
        int m=s.size();
        if(m<=1){
            return m;
        }
        int maxLen=0,last=0;
        int  helper[256];
        memset(helper,-1,sizeof(helper));
        for(int i=0;i<m;i++){
            if(helper[s[i]]+1>last){
                last=helper[s[i]]+1;
            }
            maxLen=max(maxLen,i-last+1);
            helper[s[i]]=i;
        }
        return maxLen;
    }
};



int main(int argc, const char * argv[]) {
    string  test1="abcabcbb";
    Solution so=Solution();
    int ret=so.lengthOfLongestSubstring(test1);
    cout<<"The max diff substring is "<<ret<<endl;
    return 0;
}
