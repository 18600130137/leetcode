//
//  main.cpp
//  43. Multiply Strings
//
//  Created by admin on 2019/3/14.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0"){
            return "0";
        }
        
        int m=num1.size(),n=num2.size();
        vector<int>  helper(m+n,0);
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                helper[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
                helper[i+j]+=helper[i+j+1]/10;
                helper[i+j+1]=helper[i+j+1]%10;
            }
        }
        stringstream ss;
        bool start=false;
        for(int i=0;i<helper.size();i++){
            if(!start && helper[i]==0){
                continue;
            }else{
                start=true;
                ss<<helper[i];
            }
            
        }
        
        return ss.str();
    }
};

int main(int argc, const char * argv[]) {
    string inpu1="123";
    string inpu2="456";
    Solution so=Solution();
    string ret=so.multiply(inpu1, inpu2);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
