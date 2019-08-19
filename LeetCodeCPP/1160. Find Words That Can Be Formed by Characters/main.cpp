//
//  main.cpp
//  1160. Find Words That Can Be Formed by Characters
//
//  Created by admin on 2019/8/19.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> helper(26,0);
        for(auto c:chars){
            helper[c-'a']++;
        }
        int ret=0;
        for(auto  w:words){
            vector<int> temp(helper);
            bool val=true;
            for(int i=0;i<w.size();i++){
                if(--temp[w[i]-'a']<0){
                    val=false;
                    break;
                }
            }
            if(val){
                ret+=w.size();
            }
        }
        
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    vector<string> input1={"cat","bt","hat","tree"};
    string input2="atach";
    Solution  so=Solution();
    int ret=so.countCharacters(input1, input2);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
