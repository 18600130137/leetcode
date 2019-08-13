//
//  main.cpp
//  _1156. Swap For Longest Repeated Character Substring
//
//  Created by admin on 2019/8/13.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxRepOpt1(string text) {
        int m=text.size();
        if(m==0){
            return 0;
        }
        vector<vector<int>> helper(26);
        for(int i=0;i<m;i++){
            helper[text[i]-'a'].push_back(i);
        }
        int ret=1;
        
        for(int i=0;i<26;i++){
            int local_max=0,count=1,cnt=0;
            for(int j=1;j<helper[i].size();j++){
                if(helper[i][j]==helper[i][j-1]+1){
                    count++;
                }else{
                    cnt=helper[i][j]==helper[i][j-1]+2?count:0;
                    count=1;
                }
                local_max=max(local_max,cnt+count);
            }
            ret=max(ret,local_max+(helper[i].size()>local_max?1:0));
        }
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.maxRepOpt1("aaabaaa");
    cout<<"The max swap length is:"<<ret<<endl;
    return 0;
}
