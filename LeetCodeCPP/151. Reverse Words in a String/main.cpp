//
//  main.cpp
//  151. Reverse Words in a String
//
//  Created by admin on 2019/5/10.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords1(string s) {
        int m=s.size();
        stringstream ss;
        string tmp="";
        for(int i=m-1;i>=0;i--){
            if(s[i]==' '){
                if(tmp!=""){
                    ss<<tmp+" ";
                    tmp="";
                }
            }else{
                tmp=s[i]+tmp;
            }
        }
        if(tmp!=""){
            ss<<tmp;
        }
        string ret=ss.str();
        ret.erase(ret.find_last_not_of(" ") + 1);
        return ret;
    }
    
    string reverseWords(string s) {
        int m=s.size();
        int storeIndex=0;
        reverse(s.begin(),s.end());
        for(int i=0;i<m;i++){
            if(s[i]!=' '){
                if(storeIndex!=0){
                    s[storeIndex++]=' ';
                }
                int j=i;
                while(j<m && s[j]!=' '){
                    s[storeIndex++]=s[j++];
                }
                reverse(s.begin()+storeIndex-(j-i),s.begin()+storeIndex);
                i=j;
            }
        }
        
        
        return s.erase(storeIndex);
    }
};

int main(int argc, const char * argv[]) {
    string input="the sky is blue";
    Solution so=Solution();
    string ret=so.reverseWords(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
