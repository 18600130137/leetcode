//
//  main.cpp
//  336. Palindrome Pairs
//
//  Created by admin on 2019/8/15.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
private:
    bool  isPalindrome(string st,int l,int r){
        while(l<r){
            if(st[l++]!=st[r--]){
                return false;
            }
        }
        return true;
    }
    
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int m=words.size();
        unordered_map<string,int>  index_saver;
        set<int> len_saver;
        for(int i=0;i<m;i++){
            index_saver[words[i]]=i;
            len_saver.insert(words[i].size());
        }
        vector<vector<int>> ret;
        for(int i=0;i<m;i++){
            string t=words[i];
            reverse(t.begin(),t.end());
            if(index_saver.count(t) && index_saver[t]!=i){
                ret.push_back({i,index_saver[t]});
            }
            auto lenIter=len_saver.find(t.size());
            int len=t.size();
            for(auto iter=len_saver.begin();iter!=lenIter;iter++){
                int d=*iter;
                if(isPalindrome(t,0,len-d-1) && index_saver.count(t.substr(len-d))){
                    ret.push_back({i,index_saver[t.substr(len-d)]});
                }
                if(isPalindrome(t,d,len-1) && index_saver.count(t.substr(0,d))){
                    ret.push_back({index_saver[t.substr(0,d)],i});
                }
            }
        }
        
        return ret;
        
    }
};


int main(int argc, const char * argv[]) {
    vector<string> input={"a","abc","aba",""};
    Solution so=Solution();
    vector<vector<int>>  ret= so.palindromePairs(input);
    for(auto item:ret){
        for(auto i:item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
