//
//  main.cpp
//  241. Different Ways to Add Parentheses
//
//  Created by admin on 2019/6/28.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int m=input.size();
        vector<int> ret;
        for(int i=0;i<m;i++){
            char c=input[i];
            if(c=='+' || c=='-' || c=='*'){
                string part1=input.substr(0,i);
                string part2=input.substr(i+1);
                vector<int> ret1=diffWaysToCompute(part1);
                vector<int> ret2=diffWaysToCompute(part2);
                for(auto r1:ret1){
                    for(auto r2:ret2){
                        int cal=-1;
                        if(c=='+'){
                            cal=r1+r2;
                        }else if(c=='-'){
                            cal=r1-r2;
                        }else if(c=='*'){
                            cal=r1*r2;
                        }
                        ret.push_back(cal);
                    }
                }
            }
            
        }
        if(ret.empty()){
            ret.push_back(stoi(input));
        }
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    string input="2-1-1";
    Solution so=Solution();
    vector<int> ret=so.diffWaysToCompute(input);
    for(auto i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
