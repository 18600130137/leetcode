//
//  main.cpp
//  166. Fraction to Recurring Decimal
//
//  Created by admin on 2019/5/22.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

//用余数记录循环小数开始位置
class Solution {
public:
    string fractionToDecimal(int n, int d) {
        if(n==0){
            return "0";
        }
        string ret=(n>0 ^ d>0)? "-":"";
        long long n1=abs((long long)n);
        long long d1=abs((long long)d);
        
        
        ret+=to_string(n1/d1);
        if(n1%d1==0){
            return ret;
        }
        ret+='.';
        unordered_map<long long,int>  helper;
        for(long long r=n1%d1;r;r%=d1){
            if(helper.count(r)){
                ret.insert(helper[r],1,'(');
                ret.push_back(')');
                // for(auto item:helper){
                //     cout<<item.first<<" "<<item.second<<endl;
                // }
                return ret;
            }
            helper[r]=ret.size();
            r*=10;
            ret+=to_string(r/d1);
        }
        
        return ret;
        
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    string ret=so.fractionToDecimal(10, 3);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
