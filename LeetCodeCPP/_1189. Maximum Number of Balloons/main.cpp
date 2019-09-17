//
//  main.cpp
//  _1189. Maximum Number of Balloons
//
//  Created by admin on 2019/9/16.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string  base="balloon";
        vector<int>  helper1(26,0),helper2(26,0);
        for(auto  t:text){
            helper1[t-'a']++;
        }
        for(auto b:base){
            helper2[b-'a']++;
        }
        int minCount=INT_MAX;
        for(int i=0;i<26;i++){
            if(helper2[i]){
                minCount=min(minCount,helper1[i]/helper2[i]);
            }
        }
        
        return minCount;
    }
};


int main(int argc, const char * argv[]) {
    string  input="loonbalxballpoon";
    Solution so=Solution();
    int ret=so.maxNumberOfBalloons(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
