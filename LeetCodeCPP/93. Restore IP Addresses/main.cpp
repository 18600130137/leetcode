//
//  main.cpp
//  93. Restore IP Addresses
//
//  Created by admin on 2019/4/8.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int m=s.size();
        vector<string>  ret;
        for(int a=1;a<=3;a++)
            for(int b=1;b<=3;b++)
                for(int c=1;c<=3;c++)
                    for(int d=1;d<=3;d++)
                        if(a+b+c+d==m){
                            int A=stoi(s.substr(0,a));
                            int B=stoi(s.substr(a,b));
                            int C=stoi(s.substr(a+b,c));
                            int D=stoi(s.substr(a+b+c,d));
                            if(A<=255 && B <=255 && C<=255 && D<=255){
                                string target=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D);
                                if(target.size()==m+3){
                                    ret.push_back(target);
                                }
                            }
                        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    string input="25525511135";
    Solution so=Solution();
    vector<string> ret=so.restoreIpAddresses(input);
    for(auto s:ret){
        cout<<s<<endl;
    }
    cout<<endl;
    return 0;
}
