//
//  main.cpp
//  28. Implement strStr()
//
//  Created by admin on 2019/3/5.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
private:
    vector<int> genNext(string needle,int n){
        vector<int> next(n,0);
        next[0]=-1;
        int i=0,j=-1;
        while(i<n-1){
            if(j==-1 || needle[i]==needle[j]){
                i++;
                j++;
                next[i]=j;
            }else{
                j=next[j];
            }
        }
        return next;
    }
    
public:
     int strStr1(string haystack, string needle) {
         int m=(int)haystack.size();
         int n=(int)needle.size();
         if(n==0){
             return 0;
         }
         for(int i=0;i<m-n+1;i++){
             if(haystack[i]==needle[0]){
                 int count=0;
                 for(int j=0;j<n;j++){
                     if(haystack[i+j]==needle[j]){
                         count++;
                     }else{
                         break;
                     }
                 }
                 if(count==n){
                     return i;
                 }
             }
         }
         return -1;
     }
    
    
    int strStr2(string haystack, string needle) {
        int m=(int)haystack.size();
        int n=(int)haystack.size();
        if(n==0){
            return 0;
        }
        
        vector<int> next=genNext(needle,n);
        int i=0,j=0;
        while(i<m && j<n){
            if(j==-1 || haystack[i]==needle[j]){
                i++;
                j++;
            }else{
                j=next[j];
            }
        }
        if(j==n){
            return i-j;
        }else{
            return -1;
        }
        
        
    }
};


int main(int argc, const char * argv[]) {
    string i1="Hello";
    string i2="ll";
    Solution so=Solution();
    int ret=so.strStr2(i1, i2);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
