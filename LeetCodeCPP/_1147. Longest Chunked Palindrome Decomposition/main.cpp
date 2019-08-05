//
//  main.cpp
//  _1147. Longest Chunked Palindrome Decomposition
//
//  Created by admin on 2019/8/5.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int longestDecomposition1(string text) {
        int m=text.size();
        for(int i=0;i<m/2;i++){
            if(text.substr(0,i+1)==text.substr(m-i-1)){
                return 2+longestDecomposition(text.substr(i+1,m-2*(i+1)));
            }
        }
        return m==0?0:1;
        
    }
    
    int longestDecomposition(string text) {
        int m=text.size();
        string left="",right="";
        int ret=0;
        for(int i=0;i<m;i++){
            left+=text[i];
            right=text[m-1-i]+right;
            if(left==right){
                ret+=1;
                left="";
                right="";
            }
        }
        return ret;
        
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.longestDecomposition("ghiabcdefhelloadamhelloabcdefghi");
    cout<<"The ret  is:"<<ret<<endl;
    return 0;
}
