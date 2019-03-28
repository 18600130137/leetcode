//
//  main.cpp
//  71. Simplify Path
//
//  Created by admin on 2019/3/28.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include<string>
#include<stack>
#include <sstream>
using namespace std;

class Solution {
public:
    string simplifyPath1(string path) {
        int  path_len=path.length();
        stack<string> st;
        for(int i=0;i<path_len;){
            while(i<path_len && path[i]=='/'){
                i++;
            }
            string tmp="";
            while(i<path_len && path[i]!='/'){
                tmp+=path[i];
                i++;
            }
            if(tmp==".." && !st.empty()){
                st.pop();
            }
            if(tmp!="" && tmp!="." && tmp!=".."){
                st.push(tmp);
            }
            
        }
        if(st.empty()){
            return "/";
        }
        string ret="";
        while(!st.empty()){
            ret="/"+st.top()+ret;
            st.pop();
        }
        
        return ret;
    }
    
    
    
    string simplifyPath(string path) {
        int  m=path.size();
        stack<string> st;
        int i=0;
        while(i<m){
            while(i<m && path[i]=='/'){
                i++;
            }
            stringstream s;
            while(i<m && path[i]!='/'){
                s<<path[i];
                i++;
            }
            string tmp=s.str();
            if(tmp==".." && !st.empty()){
                st.pop();
            }
            if(tmp!="" && tmp!=".." && tmp!="."){
                st.push(tmp);
            }
        }
        
        if(st.empty()){
            return "/";
        }
        string ret="";
        while(!st.empty()){
            ret="/"+st.top()+ret;
            st.pop();
        }
        
        return ret;
    }
    
    
};
int main(int argc, const char * argv[]) {
    string input="/a//b////c/d//././/..";
    Solution so=Solution();
    string ret=so.simplifyPath(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
