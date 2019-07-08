//
//  main.cpp
//  _1108. Defanging an IP Address
//
//  Created by admin on 2019/7/8.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        int m=address.size();
        stringstream ss;
        for(int i=0;i<m;i++){
            if(address[i]=='.'){
                ss<<"[.]";
            }else{
                ss<<address[i];
            }
        }
        return ss.str();
    }
};
int main(int argc, const char * argv[]) {
    string input="1.1.1.1";
    Solution so=Solution();
    string ret=so.defangIPaddr(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
