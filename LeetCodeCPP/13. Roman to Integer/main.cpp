//
//  main.cpp
//  13. Roman to Integer
//
//  Created by admin on 2019/2/26.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
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
    int romanToInt(string s) {
        unordered_map<char,int> helper={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int m=s.size();
        int ret=0;
        for(int i=0;i<m;i++){
            if(i+1<m && helper[s[i+1]]>helper[s[i]]){
                ret+=helper[s[i+1]]-helper[s[i]];
                i++;
            }else{
                ret+=helper[s[i]];
            }
            
        }
        
        return ret;
    }
};



int main(int argc, const char * argv[]) {
    Solution so=Solution();
    int ret=so.romanToInt("MCMXCIV");
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
