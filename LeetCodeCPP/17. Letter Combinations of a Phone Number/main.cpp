//
//  main.cpp
//  17. Letter Combinations of a Phone Number
//
//  Created by admin on 2019/2/27.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int m=digits.size();
        if(m==0){
            return {};
        }
        
        unordered_map<int,string> helper={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        vector<string> ret;
        ret.push_back("");
        for(int i=0;i<m;i++){
            vector<string> tmp;
            for(int j=0;j<ret.size();j++){
                for(int k=0;k<helper[digits[i]-'0'].size();k++){
                    tmp.push_back(ret[j]+helper[digits[i]-'0'][k]);
                }
            }
            ret=tmp;
        }
        
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    string input="238";
    Solution so=Solution();
    vector<string> ret=so.letterCombinations(input);
    for(auto item:ret){
        cout<<item<<",";
    }
    cout<<endl;
    return 0;
}
