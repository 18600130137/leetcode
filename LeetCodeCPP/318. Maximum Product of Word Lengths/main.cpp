//
//  main.cpp
//  318. Maximum Product of Word Lengths
//
//  Created by admin on 2019/7/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int m=words.size();
        vector<int>  helper(m,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<words[i].size();j++){
                helper[i]|=(1<<(words[i][j]-'a'));
            }
        }
        
        int maxP=0;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                if((helper[i] & helper[j])==0&& words[i].size()*words[j].size()>maxP ){
                    maxP=words[i].size()*words[j].size();
                }
            }
        }
        return maxP;
    }
};
int main(int argc, const char * argv[]) {
    vector<string> input={"abcw","baz","foo","bar","xtfn","abcdef"};
    Solution so=Solution();
    int ret=so.maxProduct(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
