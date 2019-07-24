//
//  main.cpp
//  316. Remove Duplicate Letters
//
//  Created by admin on 2019/7/24.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    string delChar(char * str, char ch)
    {
        int i, j;
        if (str == NULL)
        {
            return NULL;
        }
        
        for (i = j = 0; str[i] != '\0'; i++)
        {
            if (str[i] != ch)
            {
                str[j] = str[i];
                j++;
            }
        }
        
        str[j] = '\0';
        
        return str;
    }
    
public:
    string removeDuplicateLetters1(string s) {
        int m=s.size();
        vector<int>  count(26,0);
        vector<bool>  visited(26,false);
        for(auto s1:s){
            count[s1-'a']++;
        }
        string ret="";
        for(auto s2:s){
            count[s2-'a']--;
            if(visited[s2-'a']){
                continue;
            }
            while(!ret.empty() && s2<ret.back() && count[ret.back()-'a']){
                visited[ret.back()-'a']=false;
                ret.pop_back();
            }
            ret+=s2;
            visited[s2-'a']=true;
        }
        
        
        return ret;
    }
    
    
    string removeDuplicateLetters(string s) {
        //cout<<"s===="<<s<<endl;
        int m=s.size();
        if(m==0){
            return "";
        }
        
        vector<int>  count(26,0);
        for(auto s1:s){
            count[s1-'a']++;
        }
        int pos=0;
        for(int i=0;i<m;i++){
            if(s[i]<s[pos]){
                pos=i;
            }
            if(--count[s[i]-'a']==0){
                break;
            }
        }
        char sPos=s[pos];
        s=s.substr(pos+1);
        string nextStr=delChar(const_cast<char*>(s.c_str()),sPos);
        //cout<<"next str==="<<sPos<<" "<<nextStr<<endl;
        
        return sPos+removeDuplicateLetters(nextStr);
    }};


int main(int argc, const char * argv[]) {
    string input="cbacdcbc";
    Solution so=Solution();
    string ret=so.removeDuplicateLetters(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
