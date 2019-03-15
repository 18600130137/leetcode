//
//  main.cpp
//  44. Wildcard Matching
//
//  Created by admin on 2019/3/15.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        int i=0,j=0,match=0,startId=-1;
        while(i<m){
            if(j<n && (s[i]==p[j] || p[j]=='?')){
                i++;
                j++;
            }else if(j<n && p[j]=='*'){
                match=i;
                startId=j;
                j++;
            }else if(startId!=-1){
                match++;
                i=match;
                j=startId+1;
            }else{
                return false;
            }
        }
        while(j<n && p[j]=='*'){
            j++;
        }
        
        return j==n;
    }
};

int main(int argc, const char * argv[]) {
    string input1="adceb";
    string input2="*a*b";
    Solution so=Solution();
    int ret=so.isMatch(input1, input2);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
