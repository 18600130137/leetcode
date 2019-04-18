//
//  main.cpp
//  125. Valid Palindrome
//
//  Created by admin on 2019/4/18.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    bool  isAlphanumeric(char item){
        return item>='a' && item<='z' || item>='0' && item<='9' || item>='A' && item<='Z';
    }
    
    char  toLower(char item){
        if(item>='A' && item<='Z'){
            return item+32;
        }
        return item;
    }
    
public:
   
    bool isPalindrome(string s) {
        string ret="";
        int s_len=s.length();
        int  start=0,end=s_len-1;
        while(start<=end){
            if(!isAlphanumeric(s[start])){
                start++;
            }else if(!isAlphanumeric(s[end])){
                end--;
            }else{
                if(toLower(s[start])!=toLower(s[end])){
                    return false;
                }
                start++;
                end--;
            }
        }
        
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    bool ret=so.isPalindrome("A man, a plan, a canal: Panama");
    cout<<"Is  a Plindrome:"<<ret<<endl;
    return 0;
}
