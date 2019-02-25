//
//  main.cpp
//  9. Palindrome Number
//
//  Created by admin on 2019/2/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long newNum=0;
        int x_=x;
        while(x!=0){
            newNum=newNum*10+x%10;
            x/=10;
        }
        return x_==newNum;
    }
};

int main(int argc, const char * argv[]) {
    int  input1=121;
    Solution so=Solution();
    int ret=so.isPalindrome(input1);
    cout<<"Ret is:"<<ret<<endl;
    return 0;
}
