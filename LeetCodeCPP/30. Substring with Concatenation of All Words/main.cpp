//
//  main.cpp
//  30. Substring with Concatenation of All Words
//
//  Created by admin on 2019/3/6.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> findSubstring1(string s, vector<string>& words) {
        int k=s.size(),m=words.size();
        if(m==0){
            return {};
        }
        int n=words[0].size();
        if(k<m*n){
            return {};
        }
        unordered_map<string,int> helper;
        for(int i=0;i<m;i++){
            helper[words[i]]++;
        }
        vector<int> ret;
        for(int i=0;i<=k-m*n;i++){
            unordered_map<string,int> tmp;
            int j=0;
            for(;j<m;j++){
                string sub=s.substr(i+j*n,n);
                if(helper[sub]==0){
                    break;
                }
                tmp[sub]++;
                if(tmp[sub]>helper[sub]){
                    break;
                }
            }
            if(j==m){
                ret.push_back(i);
            }
        }
        
        return ret;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int k=s.size(),m=words.size();
        if(m==0){
            return {};
        }
        int n=words[0].size();
        if(k<m*n){
            return {};
        }
        unordered_map<string,int> helper;
        for(int i=0;i<m;i++){
            helper[words[i]]++;
        }
        vector<int> ret;
        for(int i=0;i<n;i++){
            int left=i,count=0;
            unordered_map<string,int> tmp;
            for(int j=i;j<=k-n;j+=n){
                string sub=s.substr(j,n);
                if(helper[sub]>0){
                    tmp[sub]++;
                    count++;
                    while(tmp[sub]>helper[sub]){
                        string sub1=s.substr(left,n);
                        tmp[sub1]--;
                        count--;
                        left+=n;
                    }
                    if(count==m){
                        ret.push_back(left);
                        string sub1=s.substr(left,n);
                        tmp[sub1]--;
                        left+=n;
                        count--;
                    }
                }else{
                    tmp.clear();
                    left=j+n;
                    count=0;
                }
                
            }
            
            
        }
        
        
        return ret;
    }
    
};

// "barfoofoobarthefoobarman"
// ["bar","foo","the"]

int main(int argc, const char * argv[]) {
    string input1="barfoofoobarthefoobarman";
    vector<string> input2={"bar","foo","the"};
    Solution so=Solution();
    vector<int> ret=so.findSubstring(input1, input2);
    
    cout<<"The result is:"<<endl;
    for(auto i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
