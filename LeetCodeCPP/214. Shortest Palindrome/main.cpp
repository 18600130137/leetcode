//
//  main.cpp
//  214. Shortest Palindrome
//
//  Created by admin on 2019/6/14.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> genNext(string trick){
        int m=trick.size();
        vector<int> next(m,0);
        int index=0;
        for(int i=1;i<m;i++){
            if(trick[index]==trick[i]){
                next[i]=next[i-1]+1;
                index++;
            }else{
                index=next[i-1];
                while(index>0 && trick[index]!=trick[i]){
                    index=next[index-1];
                }
                if(trick[index]==trick[i]){
                    index++;
                }
                next[i]=index;
            }
        }
        return next;
    }
    
public:
    string shortestPalindrome1(string s) {
        string rev(s);
        reverse(rev.begin(),rev.end());
        string trick=s+"#"+rev;
        vector<int> next=genNext(trick);
        string addLeft=s.substr(next.back());
        reverse(addLeft.begin(),addLeft.end());
        
        return addLeft+s;
    }
    
    string shortestPalindrome(string s) {  //剥洋葱
        int m=s.size();
        int j=0;
        for(int i=m-1;i>=0;i--){
            if(s[i]==s[j]){
                j++;
            }
        }
        //cout<<"j==="<<j<<endl;
        if(j==m){
            return s;
        }
        string rightCut=s.substr(j);
        string addLeft(rightCut);
        reverse(addLeft.begin(),addLeft.end());
        return addLeft+shortestPalindrome(s.substr(0,j))+rightCut;
    }};

int main(int argc, const char * argv[]) {
    string input="aacecaaa";
    Solution so=Solution();
    string ret=so.shortestPalindrome(input);
    cout<<ret<<endl;
    return 0;
}
