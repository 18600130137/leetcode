//
//  main.cpp
//  331. Verify Preorder Serialization of a Binary Tree
//
//  Created by admin on 2019/8/8.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
private:
    vector<string> split(string preorder){
        vector<string>  ret;
        string item;
        stringstream  ss(preorder);
        while(getline(ss,item,',')){
            ret.push_back(item);
        }
        
        return ret;
    }
    
public:
    bool isValidSerialization1(string preorder) {
        int diff=1;
        int i=0;
        vector<string> sp=split(preorder);
        for(auto  s:sp){
            if(--diff<0){
                return false;
            }
            if(s!="#"){
                diff+=2;
            }
        }
        return diff==0;
    }
    
    bool isValidSerialization(string preorder) {
        int diff=1;
        int i=0;
        vector<string> sp=split(preorder);
        stack<string> helper;
        for(auto  s:sp){
            while(s=="#" && !helper.empty() && helper.top()=="#"){
                helper.pop();
                if(helper.empty()) return false;
                helper.pop();
            }
            helper.push(s);
        }
        return  helper.size()==1 && helper.top()=="#";
    }
};
int main(int argc, const char * argv[]) {
    string input="9,3,4,#,#,1,#,#,2,#,6,#,#";
    Solution so=Solution();
    bool ret=so.isValidSerialization(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
