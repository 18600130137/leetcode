//
//  main.cpp
//  65. Valid Number
//
//  Created by admin on 2019/3/27.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    
    string  trim(string s){
        if(s.empty()){
            return s;
        }
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ")+1);
        return s;
    }
    
    bool  isValid(char  cs){
        return cs=='+' || cs=='-' || cs=='e' || cs=='E' ||cs=='.' || (cs>='0' && cs<='9');
    }
    
    
    bool isNumber(string s) {
        if(s.empty()){
            return  false;
        }
        s=trim(s);
        int s_len=s.length();
        if(s_len==0){
            return  false;
        }
        // flags
        int signCount = 0;
        bool hasE = false;
        bool hasNum = false;
        bool hasPoint = false;
        for(int i=0;i<s_len;i++){
            char c= s[i];
            if(!isValid(c)){
                return false;
            }
            
            if(c>='0' && c<='9'){
                hasNum=true;
            }
            
            if(c=='e' || c=='E'){
                if(hasE || !hasNum){
                    return false;
                }
                if(i==s_len-1){
                    return false;
                }
                hasE=true;
            }
            if(c=='.'){
                if(hasPoint || hasE){
                    return false;
                }
                if(i==s_len-1 && !hasNum){
                    return false;
                }
                hasPoint=true;
            }
            if(c=='+' || c=='-'){
                if(signCount>=2){
                    return false;
                }
                if(i==s_len-1){
                    return false;
                }
                if(i>0 && !hasE){
                    return false;
                }
                signCount+=1;
            }
            
            
            
        }
        
        return true;
    }
    
    
};

int main(int argc, const char * argv[]) {
    string input="2e10";
    Solution so=Solution();
    bool ret=so.isNumber(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
