//
//  main.cpp
//  1209. Remove All Adjacent Duplicates in String II
//
//  Created by admin on 2019/10/12.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicates1(string s, int k) {
        vector<pair<char,int>>  helper;
        for(auto   c:s){
            if(!helper.empty() && helper.back().first==c){
                if(++helper.back().second==k){
                    helper.pop_back();
                }
            }else{
                helper.push_back(make_pair(c,1));
            }
        }
        string ret="";
        for(auto item:helper){
            int count=item.second;
            while(count-->0){
                ret+=item.first;
            }
            
        }
        
        return ret;
    }
    
    string removeDuplicates(string s, int k) {
        int m=s.size();
        vector<int>  count(m);
        int i=0;
        for(int j=0;j<m;i++,j++){
            s[i]=s[j];
            count[i]=i>0&&s[i-1]==s[j]?count[i-1]+1:1;
            if(count[i]==k){
                i-=k;
            }
        }
        
        return s.substr(0,i);
    }
};
int main(int argc, const char * argv[]) {
    string input1="pbbcggttciiippooaais";
    int  input2=2;
    Solution so=Solution();
    string ret=so.removeDuplicates(input1, input2);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
