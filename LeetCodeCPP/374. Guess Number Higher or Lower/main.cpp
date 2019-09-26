//
//  main.cpp
//  374. Guess Number Higher or Lower
//
//  Created by admin on 2019/9/24.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

int target;

int guess(int num){
    if(num==target){
        return 0;
    }else if (num<target){
        return 1;
    }else{
        return -1;
    }
}

class Solution {
public:
    int guessNumber(int n) {
        int low=1,high=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            int back=guess(mid);
            if(back==0){
                return mid;
            }else if(back==-1){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
int main(int argc, const char * argv[]) {
    int n=100;
    target=33;
    Solution so=Solution();
    int ret=so.guessNumber(100);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
