//
//  main.cpp
//  67. Add Binary
//
//  Created by admin on 2019/3/27.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int  char2int(char num){
        return  num-'0';
    }
    
    
    string addBinary1(string a, string b) {
        int a_len=a.length();
        int b_len=b.length();
        stringstream s;
        int carry=0;
        int pos=0;
        
        while(pos<a_len || pos<b_len){
            int a_v=0;
            int b_v=0;
            if(pos<a_len){
                a_v=char2int(a[a_len-1-pos]);
            }
            if(pos<b_len){
                b_v=char2int(b[b_len-1-pos]);
            }
            int sum=carry+a_v+b_v;
            if(sum>1){
                carry=1;
            }else{
                carry=0;
            }
            s<<sum%2;
            pos++;
        }
        if(carry==1){
            s<<1;
        }
        string res=s.str();
        std::reverse(res.begin(),res.end());
        return   res;
    }
    
    string addBinary(string a, string b) {
        if(a.size()<b.size()){
            swap(a,b);
        }
        int m=a.size(),n=b.size();
        int i=m-1,j=n-1;
        while(i>=0){
            if(j>=0){
                a[i]+=(b[j]=='1');
                j--;
            }
            if(a[i]>'1'){
                a[i]-=2;
                if(i>0){
                    a[i-1]+=1;
                }else{
                    a='1'+a;
                }
            }
            i--;
        }
        return a;
    }
    
    
};

int main(int argc, const char * argv[]) {
    string input1="1111";
    string input2="1";
    Solution so=Solution();
    string ret=so.addBinary(input1, input2);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
