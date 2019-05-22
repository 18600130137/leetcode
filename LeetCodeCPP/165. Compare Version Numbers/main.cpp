//
//  main.cpp
//  165. Compare Version Numbers
//
//  Created by admin on 2019/5/22.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string v1, string v2) {
        int m=v1.size(),n=v2.size();
        int i=0,j=0;
        while(i<m || j<n){
            int num1=0,num2=0;
            while(i<m && v1[i]!='.'){
                num1=num1*10+(v1[i]-'0');
                i++;
            }
            while(j<n && v2[j]!='.'){
                num2=num2*10+(v2[j]-'0');
                j++;
            }
            if(num1>num2){
                return 1;
            }else if(num1<num2){
                return -1;
            }
            i++;
            j++;
        }
        
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    string input1="1.01";
    string input2="1.001";
    Solution so=Solution();
    int ret=so.compareVersion(input1, input2);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
