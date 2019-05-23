//
//  main.cpp
//  168. Excel Sheet Column Title
//
//  Created by admin on 2019/5/23.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        while(n!=0){
            if(n%26!=0){
                ret=(char)('A'+(n%26-1))+ret;
            }else{
                ret='Z'+ret;
                n--;
            }
            n/=26;
        }
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    string ret=so.convertToTitle(701);
    cout<<"The result is:"<<ret<<endl;
    return 0;
}
