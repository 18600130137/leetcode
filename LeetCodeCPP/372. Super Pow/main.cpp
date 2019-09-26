//
//  main.cpp
//  372. Super Pow
//
//  Created by admin on 2019/9/19.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int base=1337;
    int pow(int a,int k){
        a=a%base;
        int ret=1;
        for(int i=0;i<k;i++){
            ret=(ret*a)%base;
        }
        return ret;
    }
    
public:
    int superPow(int a, vector<int>& b) {
        if(b.empty()){
            return 1;
        }
        int lastNum=b.back();
        b.pop_back();
        return pow(superPow(a,b),10)*pow(a,lastNum)%base;
        
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<int> input={2,0};
    int ret=so.superPow(2,input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
