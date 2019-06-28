//
//  main.cpp
//  258. Add Digits
//
//  Created by admin on 2019/6/28.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int addDigits1(int num) {
        if(num<10){
            return num;
        }
        int sum=0;
        while(num){
            sum+=num%10;
            num/=10;
        }
        return addDigits(sum);
    }
    
    int addDigits(int num) {
        
        return 1+(num-1)%9;
    }
};


int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.addDigits(38);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
