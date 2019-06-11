//
//  main.cpp
//  _1081. Smallest Subsequence of Distinct Characters
//
//  Created by admin on 2019/6/11.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string text) {
        vector<int> helper1(26,0),helper2(26,false);
        for(auto c:text){
            helper1[c-'a']++;
        }
        string ret="";
        for(auto c:text){
            if(helper2[c-'a']){
                helper1[c-'a']--;
                continue;
            }
            while(ret.size()>0 && ret.back()>c && helper1[ret.back()-'a']>0){
                helper2[ret.back()-'a']=false;
                ret.pop_back();
            }
            ret.push_back(c);
            helper1[c-'a']--;
            helper2[c-'a']=true;
            
        }
        
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    string ret=so.smallestSubsequence("cdadabcc");
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
