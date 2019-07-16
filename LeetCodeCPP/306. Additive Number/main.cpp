//
//  main.cpp
//  306. Additive Number
//
//  Created by admin on 2019/7/16.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    bool  check(string num1,string num2,string num3){
        string next=add(num1,num2);
        if(next==num3){
            return true;
        }
        
        if(next.size()>num3.size() || next!=num3.substr(0,next.size())){
            return false;
        }
        
        
        return check(num2,next,num3.substr(next.size()));
    }
    
    
    string  add(string  num1,string num2){
        int i=num1.size()-1,j=num2.size()-1,carry=0;
        string ret;
        while(i>=0 || j>=0){
            int tmp=(i>=0?(num1[i--]-'0'):0)+(j>=0?(num2[j--]-'0'):0)+carry;
            ret.push_back(tmp%10+'0');
            carry=tmp/10;
        }
        if(carry){
            ret.push_back(carry+'0');
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
    
    
public:
    bool isAdditiveNumber(string num) {
        int m=num.size();
        for(int i=1;i<=m/2;i++){
            if(num[0]=='0' && i>1){
                return false;
            }
            string num1=num.substr(0,i);
            for(int j=1;max(j,i)<=m-i-j;j++){
                if(num[i]=='0' && j>1){
                    break;
                }
                string num2=num.substr(i,j);
                string num3=num.substr(i+j);
                if(check(num1,num2,num3)){
                    return true;
                }
            }
            
            
        }
        return false;
    }
};
    
    



int main(int argc, const char * argv[]) {
    Solution so=Solution();
    string input="112358";
    bool ret= so.isAdditiveNumber(input);
    cout<<"Is  a  Value string:"<<ret<<endl;
    cout<<ret<<endl;
    
    return 0;
}
