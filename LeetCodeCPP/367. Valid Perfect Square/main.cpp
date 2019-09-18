//
//  main.cpp
//  367. Valid Perfect Square
//
//  Created by admin on 2019/9/18.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1){
            return true;
        }
        long long low=0,high=num/2;
        while(low<=high){
            auto mid=low+(high-low)/2;
            auto target=mid*mid;
            if(target==num){
                return true;
            }
            if(target>num){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    int input=16;
    Solution so=Solution();
    bool ret=so.isPerfectSquare(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
