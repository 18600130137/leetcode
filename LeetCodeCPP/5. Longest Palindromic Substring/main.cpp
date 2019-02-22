//
//  main.cpp
//  5. Longest Palindromic Substring
//
//  Created by admin on 2019/2/22.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>

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
     string longestPalindrome1(string s) {
         int m=s.size();
         string ret="";
         for(int i=0;i<m;i++){
             int odd_core=0;
             while(i-odd_core>=0 && i+odd_core<m && s[i-odd_core]==s[i+odd_core]){
                 if(2*odd_core+1>ret.size()){
                     ret=s.substr(i-odd_core,2*odd_core+1);
                 }
                 odd_core++;
             }
              int even_core=0;
             if(i+1<m && s[i+1]==s[i]){
                 while(i-even_core>=0 && i+1+even_core<m && s[i-even_core]==s[i+1+even_core]){
                     if(2*even_core+2>ret.size()){
                         ret=s.substr(i-even_core,2*even_core+2);
                     }
                     even_core++;
                 }
             }
         }

         return ret;
     }
    
    string longestPalindrome(string s) {
        int m=s.size();
        string ret="";
        int start=0,max_len=0;
        for(int i=0;i<m;){
            if(m-i<=max_len/2){
                break;
            }
            int l=i,r=i;
            while(r+1<m && s[r+1]==s[r]){
                r++;
            }
            i=r+1;
            
            while(l-1>=0 && r+1<m && s[l-1]==s[r+1]){
                l--;
                r++;
            }
            int cal_len=r-l+1;
            if(cal_len>max_len){
                max_len=cal_len;
                start=l;
            }
        }
        
        return s.substr(start,max_len);
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    string in="babad";
    string ret=so.longestPalindrome(in);
    cout<<"ret====="<<ret<<endl;
    return 0;
}
