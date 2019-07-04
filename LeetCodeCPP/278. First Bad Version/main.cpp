//
//  main.cpp
//  278. First Bad Version
//
//  Created by admin on 2019/7/4.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;


class Solution {
private:
    int  mBadStart=0;
    
    bool isBadVersion(int version){
        if(version>=mBadStart){
            return true;
        }
        return false;
    }
    
public:
    Solution(int badStart){
        mBadStart=badStart;
    }
    
    int firstBadVersion(int n) {
        if(n==1){
            return 1;
        }
        int left=1,right=n;
        while(left<right){
            int mid=left+(right-left)/2;
            if(!isBadVersion(mid)){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        return left;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution(17);
    int ret=so.firstBadVersion(29);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
