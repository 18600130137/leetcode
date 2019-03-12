//
//  main.cpp
//  38. Count and Say
//
//  Created by admin on 2019/3/12.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n<=0){
            return "";
        }
        string last="1";
        for(int i=2;i<=n;i++){
            int count=1;
            int j=0;
            stringstream current;
            while(j<last.size()-1){
                if(last[j+1]==last[j]){
                    count++;
                }else{
                    current<<count<<last[j];
                    count=1;
                }
                j++;
            }
            current<<count<<last[j];
            last=current.str();;
            
        }
        return last;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    string ret=so.countAndSay(3);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
