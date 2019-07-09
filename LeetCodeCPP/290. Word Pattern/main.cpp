//
//  main.cpp
//  290. Word Pattern
//
//  Created by admin on 2019/7/9.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int m=pattern.size();
        istringstream  iss(str);
        int i=0;
        unordered_map<char,int> h1;
        unordered_map<string,int> h2;
        for(string word;iss>>word;i++){
            //cout<<"Each word:"<<word<<endl;
            if(i==m || h1[pattern[i]]!=h2[word]){
                return false;
            }
            h1[pattern[i]]=h2[word]=i+1;
        }
        return i==m;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    bool ret=so.wordPattern("abba","dog cat cat dog");
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
