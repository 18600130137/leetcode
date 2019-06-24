//
//  main.cpp
//  _1096. Brace Expansion II
//
//  Created by admin on 2019/6/24.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

class Solution {
private:
    
    set<string>  merger(set<string> s1,set<string> s2){
        if(s2.empty()){
            return s1;
        }
        if(s1.empty()){
            return s2;
        }
        set<string> ret;
        for(auto ss1:s1){
            for(auto ss2:s2){
                ret.insert(ss1+ss2);
            }
        }
        return ret;
        
    }
    
    
    set<string> parse(const char*& p, const char* end) {
        set<string> words;
        
        while (p < end) {
            set<string> new_words;
            
            if (isalpha(*p)) {
                string word;
                while (p < end && isalpha(*p)) {
                    word += *p;
                    ++p;
                }
                new_words = {word};
            } else if (*p == '{') {
                ++p;
                while (p < end && *p != '}') {
                    auto subs = parse(p, end);
                    new_words.insert(subs.begin(),subs.end());
                    if (p < end && *p == ',') {
                        ++p;
                    }
                }
                //assert(*p == '}');
                ++p;
            } else {
                break;
            }
            
            words = merger(words, new_words);
        }
        return words;
    }
    
public:
    vector<string> braceExpansionII(string ex) {
        const char* p = ex.c_str();
        auto* end = p + ex.size();
        set<string> words = parse(p, end);
        return vector<string>(words.begin(), words.end());
    }
    
    
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<string> ret=so.braceExpansionII("{a,b}{c{d,e}}");
    cout<<"The ret is:"<<endl;
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
