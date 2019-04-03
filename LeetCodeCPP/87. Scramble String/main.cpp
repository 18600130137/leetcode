//
//  main.cpp
//  87. Scramble String
//
//  Created by admin on 2019/4/3.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
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
    bool isScramble(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        if(m!=n){
            return false;
        }
        if(s1==s2){
            return true;
        }
        vector<int>  map(26,0);
        for(int i=0;i<m;i++){
            map[s1[i]-'a']++;
            map[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(map[i]!=0){
                return false;
            }
        }
        
        for(int i=1;i<=m-1;i++){
            bool comb1=isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i));
            if(comb1){
                return true;
            }
            bool comb2=isScramble(s1.substr(0,i),s2.substr(m-i)) && isScramble(s1.substr(i),s2.substr(0,m-i));
            if(comb2){
                return true;
            }
            
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    bool ret=so.isScramble("great", "rgeat");
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
