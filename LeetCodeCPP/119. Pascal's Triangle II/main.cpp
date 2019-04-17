//
//  main.cpp
//  119. Pascal's Triangle II
//
//  Created by admin on 2019/4/17.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>  ret(rowIndex+1,0);
        ret[0]=1;
        
        for(int i=1;i<=rowIndex;i++){
            for(int j=i;j>0;j--){
                ret[j]+=ret[j-1];
            }
        }
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<int> ret=so.getRow(4);
    for(auto i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
