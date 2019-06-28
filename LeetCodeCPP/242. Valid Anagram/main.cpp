//
//  main.cpp
//  242. Valid Anagram
//
//  Created by admin on 2019/6/28.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int charactors[26]={0};
        for(int i=0;i<s.length();i++){
            int cal_index=s[i]-'a';
            charactors[cal_index]+=1;
        }
        
        for(int i=0;i<t.length();i++){
            int cal_index=t[i]-'a';
            charactors[cal_index]-=1;
        }
        
        for(int i=0;i<26;i++){
            if(charactors[i]!=0){
                return false;
            }
        }
        return  true;
        
        
    }
};
int main(int argc, const char * argv[]) {
    string   s = "anagram",t = "nagaram";
    Solution so=Solution();
    bool ret=so.isAnagram(s, t);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
