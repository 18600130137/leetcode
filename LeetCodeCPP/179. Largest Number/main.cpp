//
//  main.cpp
//  179. Largest Number
//
//  Created by admin on 2019/5/28.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string> helper;
        for(auto n:nums){
            helper.push_back(to_string(n));
        }
        
        
        sort(helper.begin(),helper.end(),[](string n1,string n2){
            return n1+n2>n2+n1;
        });
        stringstream ss;
        for(auto h:helper){
            ss<<h;
        }
        string ret=ss.str();
        while(ret.size()>1 && ret[0]=='0'){
            ret.erase(0,1);
        }
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Solution so=Solution();
    string ret=so.largestNumber(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
