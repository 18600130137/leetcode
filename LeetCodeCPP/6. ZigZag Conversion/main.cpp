//
//  main.cpp
//  6. ZigZag Conversion
//
//  Created by admin on 2019/2/22.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:  //36
    string convert1(string s, int numRows) {
        int m=s.size();
        if(numRows==1 || numRows>=m){
            return s;
        }
        string ret="";
        int base_step=(numRows-1)*2;
        for(int i=0;i<numRows;i++){
            int step=base_step;
            if(i!=0 && i!=numRows-1){
                step=i*2;
            }
            
            int offset=0;
            while(i+offset<m){
                ret+=s[i+offset];
                if(step!=base_step){
                    step=base_step-step;
                }
                offset+=step;
            }
            
        }
        return ret;
    }
    
    string convert(string s, int numRows) {
         int m=s.size();
         if(numRows==1 || numRows>=m){
             return s;
         }
         vector<string> helper(numRows,"");
         int rowIndex=0,way=1;
         for(int i=0;i<m;i++){
             helper[rowIndex]+=s[i];
             if(rowIndex==0){
                 way=1;
             }else if(rowIndex==numRows-1){
                 way=-1;
             }
             rowIndex+=way;
         }
         string ret="";
         for(auto s:helper){
             ret+=s;
         }

         return ret;
     }
};



int main(int argc, const char * argv[]) {
    Solution so=Solution();
    string s="PAYPALISHIRING";
    int row=4;
    string ret=so.convert(s, row);
    cout<<"The  ret is:"<<ret<<endl;
    return 0;
}
