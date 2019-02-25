//
//  main.cpp
//  10. Regular Expression Matching
//
//  Created by admin on 2019/2/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
     bool isMatch1(string s, string p) {
         int m=p.size();
         if(m==0){
             return s.empty();
         }
         if(m==1){
             return s.size()==1 && (p=="." || s==p);
         }
         if(p[1]!='*'){
             if(s.empty()){
                 return false;
             }
             return (p[0]=='.' || p[0]==s[0]) && isMatch(s.substr(1),p.substr(1));
         }


         while(s.size()>0  && (p[0]=='.' || p[0]==s[0])){
             if(isMatch(s,p.substr(2)))return true;
             s=s.substr(1);
         }

         return isMatch(s,p.substr(2));
        }
    

    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<bool>>  helper(m+1,vector<bool>(n+1,false));
        helper[0][0]=true;
        for(int i=0;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]=='*'){
                    helper[i][j]=helper[i][j-2] || (i&& helper[i-1][j] &&(p[j-2]=='.' || p[j-2]==s[i-1]));
                }else{
                    helper[i][j]=i&& helper[i-1][j-1] &&(p[j-1]=='.' || p[j-1]==s[i-1]);
                }
                
            }
        }
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<helper[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return  helper[m][n];
        
    }
};

int main(int argc, const char * argv[]) {
    string s = "mississippi";
    string p = "mis*is*p*.";
//    string s = "aab";
//    string p = "c*a*b";
    Solution so=Solution();
    bool  ret=so.isMatch(s,p);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
