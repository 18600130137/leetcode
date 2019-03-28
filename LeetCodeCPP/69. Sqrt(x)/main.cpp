//
//  main.cpp
//  69. Sqrt(x)
//
//  Created by admin on 2019/3/28.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x<=1){
            return x;
        }
        int left=0,right=x;
        while(true){
            int mid=left+(right-left)/2;
            if(mid>x/mid){
                right=mid-1;
            }else{
                if(mid+1>x/(mid+1)){
                    return mid;
                }
                left=mid+1;
            }
        }
        
        
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.mySqrt(7);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
