//
//  main.cpp
//  1208. Get Equal Substrings Within Budget
//
//  Created by admin on 2019/10/10.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int  find(vector<int> helper2,int i,int l,int r,int maxCost){
        while(l<r){
            int mid=l+(r-l)/2;
            if(helper2[i]-helper2[mid]<=maxCost){
                r=mid;
            }else if(helper2[i]-helper2[mid]>maxCost){
                l=mid+1;
            }
            
        }
        return i-l;
    }
    
public:
    int equalSubstring(string s, string t,int maxCost) {
        int m=s.size();
        if(m==0){
            return 0;
        }
        vector<int> helper1(m,0);
        for(int i=0;i<m;i++){
            helper1[i]=abs(s[i]-t[i]);
        }
        vector<int> helper2(m+1,0);
        for(int i=1;i<m+1;i++){
            helper2[i]=helper2[i-1]+helper1[i-1];
        }
        int ret=0;
        for(int i=m;i>=1;i--){
            if(helper2[i]-helper2[i-1]<=maxCost){
                int local=find(helper2,i,0,i-1,maxCost);
                ret=max(ret,local);
            }
        }
        
        return ret;
        
    }
    
    int equalSubstring1(string s, string t,int maxCost) {
        int m=s.size();
        if(m==0){
            return 0;
        }
        vector<int> helper1(m,0);
        for(int i=0;i<m;i++){
            helper1[i]=abs(s[i]-t[i]);
        }
        int i=0,j=0,ret=0,acc=0;
        while(i<m){
            while(j<m && acc+helper1[j]<=maxCost){
                acc+=helper1[j];
                j++;
            }
            ret=max(ret,j-i);
            acc-=helper1[i];
            i++;
        }
        
        return ret;
        
    }};

int main(int argc, const char * argv[]) {
    string s = "abcd", t = "bcdf";
    int maxCost = 3;
    Solution so=Solution();
    int ret=so.equalSubstring(s, t, maxCost);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
