//
//  main.cpp
//  202. Happy Number
//
//  Created by admin on 2019/6/6.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
private:
    int cal_next(int num){
        int nextNum=0;
        while(num!=0){
            int split=num%10;
            nextNum+=split*split;
            num/=10;
        }
        return nextNum;
    }
    
public:
    bool isHappy(int n) {
        while(n!=1){
            n=cal_next(n);
            if(n==4){
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    bool isHappy=so.isHappy(19);
    cout<<"It is happy number:"<<isHappy<<endl;
    return 0;
}
