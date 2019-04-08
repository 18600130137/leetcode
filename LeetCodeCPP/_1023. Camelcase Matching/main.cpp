//
//  main.cpp
//  _1023. Camelcase Matching
//
//  Created by admin on 2019/4/8.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    bool isMatch(string q,string p){
        int m=q.size();
        int n=p.size();
        int j=0;
        for(int i=0;i<m;i++){
            if(j<n && q[i]==p[j]){
                j++;
            }else if(q[i]>='A' && q[i]<='Z'){
                return false;
            }
        }
        return j==n;
    }
    
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>  ret;
        for(auto s:queries){
            ret.push_back(isMatch(s,pattern));
        }
        
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    vector<string> input1={"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    Solution so=Solution();
    vector<bool> ret=so.camelMatch(input1,"FB");
    for(auto b:ret){
        cout<<b<<" ";
    }
    cout<<endl;
    return 0;
}
