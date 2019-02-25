//
//  main.cpp
//  8. String to Integer (atoi)
//
//  Created by admin on 2019/2/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int m=str.size(),i=0;
        while(i<m && str[i]==' '){
            i++;
        }
        int flag=1;
        if(i<m && str[i]=='-'){
            flag=-1;
            i++;
        }else if(i<m && str[i]=='+'){
            flag=1;
            i++;
        }
        long ret=0;
        while(i<m && isdigit(str[i])){
            ret=ret*10+(str[i]-'0');
            long newNum=ret*flag;
            i++;
            if(newNum>INT_MAX){
                return INT_MAX;
            }else if(newNum<INT_MIN){
                return INT_MIN;
            }
        }
        
        return ret*flag;
    }
};

int main(int argc, const char * argv[]) {
    string input1="4193 with words";
    Solution so=Solution();
    int ret=so.myAtoi(input1);
    cout<<"The ret is:"<<ret<<endl;
    
    return 0;
}
