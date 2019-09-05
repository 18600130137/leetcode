//
//  main.cpp
//  _1177. Can Make Palindrome from Substring
//
//  Created by admin on 2019/9/5.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

class Solution {
    
public:
    vector<bool> canMakePaliQueries1(string s, vector<vector<int>>& queries) {
        int m=s.size();
        int  n=queries.size();
        vector<vector<bool>>   helper(m+1,vector<bool>(26,false));
        
        for(int i=0;i<m;i++){
            helper[i+1].assign(helper[i].begin(),helper[i].end());
            helper[i+1][s[i]-'a']=helper[i+1][s[i]-'a']^true;
        }
        vector<bool> ret;
        for(auto  q:queries){
            int sum=0;
            for(int i=0;i<26;i++){
                sum+=(helper[q[1]+1][i]^helper[q[0]][i]);
            }
            
            ret.push_back(sum/2<=q[2]);
            
        }
        return ret;
    }
    
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int mask = 0;
        vector<int> ps(1,0);
        for (char c : s)
            ps.push_back(mask ^= 1 << (c - 'a'));
        
        vector<bool> r;
        for (auto &q : queries) {
            int odds =bitset<32>(ps[q[1] + 1] ^ ps[q[0]]).count();
            r.push_back(q[2]>= odds/2);
        }
        return r;
    }
};


int main(int argc, const char * argv[]) {
    string input1="abcda";
    vector<vector<int>> input2={{3,3,0},{1,2,0},{0,3,1},{0,3,2},{0,4,1}};
    Solution so=Solution();
    vector<bool> ret=so.canMakePaliQueries(input1, input2);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
