//
//  main.cpp
//  171. Excel Sheet Column Number
//
//  Created by admin on 2019/5/23.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int titleToNumber(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            sum=sum*26+(s[i]-'A'+1);
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.titleToNumber("ABC");
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
