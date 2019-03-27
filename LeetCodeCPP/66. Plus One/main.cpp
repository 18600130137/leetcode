//
//  main.cpp
//  66. Plus One
//
//  Created by admin on 2019/3/27.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne1(vector<int>& digits) {
        int  size=digits.size();
        int carry=1;
        for(int i=size-1;i>=0;i--){
            digits[i]+=carry;
            if(digits[i]>9){
                digits[i]=0;
                carry=1;
            }else{
                carry=0;
                break;
            }
        }
        if(carry==1){
            digits.insert(digits.begin(),1);
        }
        return  digits;
        
    }
    
    vector<int> plusOne(vector<int>& digits) {
        int  m=digits.size();
        int i=m-1;
        digits[i]+=1;
        while(i>0 && digits[i]>9){
            digits[i-1]+=1;
            digits[i]%=10;
            i--;
        }
        if(digits[0]>9){
            digits[0]%=10;
            digits.insert(digits.begin(),1);
        }
        
        return digits;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={9,9,9};
    Solution so=Solution();
    vector<int> ret=so.plusOne(input);
    for (auto r:ret) {
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
