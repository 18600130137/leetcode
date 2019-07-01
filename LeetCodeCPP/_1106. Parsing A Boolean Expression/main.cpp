//
//  main.cpp
//  _1106. Parsing A Boolean Expression
//
//  Created by admin on 2019/7/1.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    bool  f(string &exp,int &i){
        char c=exp[i];
        if(c=='t'){
            i++;
            return true;
        }else if(c=='f'){
            i++;
            return false;
        }else if(c=='!'){
            return f_not(exp,i);
        }else if(c=='&'){
            return f_and(exp,i);
        }else if(c=='|'){
            return f_or(exp,i);
        }else{
            return false;   //走不了
        }
    }
    
    bool f_not(string &exp,int &i){
        i+=2;
        bool ret=f(exp,i);
        i++;
        return !ret;
    }
    
    
    bool f_and(string &exp,int &i){
        i+=2;
        bool ret=true;
        ret&=f(exp,i);
        while(exp[i]!=')'){
            i++;
            ret&=f(exp,i);
        }
        i++;
        return ret;
    }
    
    bool f_or(string &exp,int &i){
        i+=2;
        bool ret=false;
        ret|=f(exp,i);
        while(exp[i]!=')'){
            i++;
            ret|=f(exp,i);
        }
        i++;
        return ret;
    }
    
    
public:
    bool parseBoolExpr(string exp) {
        int index=0;
        return f(exp,index);
    }
};
int main(int argc, const char * argv[]) {
    string input="|(&(t,f,t),!(t))";
    Solution so=Solution();
    bool ret=so.parseBoolExpr(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
