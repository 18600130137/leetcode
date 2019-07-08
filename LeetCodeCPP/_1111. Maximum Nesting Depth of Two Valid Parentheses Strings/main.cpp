//
//  main.cpp
//  _1111. Maximum Nesting Depth of Two Valid Parentheses Strings
//
//  Created by admin on 2019/7/8.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int m=seq.size(),depth=0,cur=0;
        for(int i=0;i<m;i++){
            depth=max(depth,cur+=(seq[i]=='('?1:-1));
        }
        vector<int> ret(m,0);
        for(int i=0;i<m;i++){
            if(seq[i]=='(' &&++cur>depth/2){
                ret[i]=1;
            }else if(seq[i]==')' && cur-->depth/2){
                ret[i]=1;
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    string input="()(())()";
    vector<int> ret=so.maxDepthAfterSplit(input);
    for(auto  i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
