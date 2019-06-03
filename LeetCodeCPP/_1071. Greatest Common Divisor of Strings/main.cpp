//
//  main.cpp
//  _1071. Greatest Common Divisor of Strings
//
//  Created by admin on 2019/6/3.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.size()<str2.size()){
            return gcdOfStrings(str2,str1);
        }else if(str2.size()==0){
            return str1;
        }else{
            string sub1=str1.substr(0,str2.size());
            if(sub1!=str2){
                return "";
            }
            string sub2=str1.substr(str2.size());
            return gcdOfStrings(sub2,str2);
        }
        
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    string ret=so.gcdOfStrings("ABC","ABCABC");
    cout<<"The max gcd is:"<<ret<<endl;
    return 0;
}
