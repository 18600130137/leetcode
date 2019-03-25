//
//  main.cpp
//  58. Length of Last Word
//
//  Created by admin on 2019/3/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int m=s.size();
        int len=0;
        for(int i=m-1;i>=0;i--){
            if(s[i]==' '){
                if(len==0){
                    continue;
                }else{
                    break;
                }
            }else{
                len++;
            }
        }
        return len;
    }
};


int main(int argc, const char * argv[]) {
    string input="Hellor  world!";
    Solution so=Solution();
    int ret=so.lengthOfLastWord(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
