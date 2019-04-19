//
//  main.cpp
//  131. Palindrome Partitioning
//
//  Created by admin on 2019/4/19.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    bool isPalindrome(string sub,int l,int r){
        if(l==r){
            return true;
        }
        while(l<r){
            if(sub[l]!=sub[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    
    void helper(string s,vector<vector<string>> &ret,vector<string>  &current,int start){
        if(start>=s.size()){
            ret.push_back(current);
        }
        for(int i=start;i<s.size();i++){
            if(isPalindrome(s,start,i)){
                current.push_back(s.substr(start,i-start+1));
                helper(s,ret,current,i+1);
                current.pop_back();
            }
        }
        
        
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string>  current;
        helper(s,ret,current,0);
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    string input="aab";
    Solution so=Solution();
    vector<vector<string>> ret=so.partition(input);
    for(auto item:ret){
        for(auto i:item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
