//
//  main.cpp
//  _1002. Find Common Characters
//
//  Created by admin on 2019/3/4.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int>  helper(26,101);
        
        for(int i=0;i<A.size();i++){
            vector<int> tmp(26,0);
            for(int j=0;j<A[i].size();j++){
                tmp[A[i][j]-'a']++;
            }
            for(int k=0;k<26;k++){
                helper[k]=min(helper[k],tmp[k]);
            }
        }
        vector<string> ret;
        for(int i=0;i<26;i++){
            while(helper[i]){
                ret.push_back(string(1,'a'+i));
                helper[i]--;
            }
        }
        
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    vector<string>  input={"bella","label","roller"};
    Solution so=Solution();
    vector<string> ret=so.commonChars(input);
    cout<<"The result is:";
    for (auto item:ret) {
        cout<<item<<" ";
    }
    cout<<endl;
    return 0;
}
