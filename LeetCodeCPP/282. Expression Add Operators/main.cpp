//
//  main.cpp
//  282. Expression Add Operators
//
//  Created by admin on 2019/7/4.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void helper(string &num,int target,vector<string> &ret,string path,int pos,long long eval,long long last){
        if(pos==num.size()){
            if(target==eval){
                ret.push_back(path);
            }
            return;
        }
        for(int i=pos;i<num.size();i++){
            if(i!=pos && num[pos]=='0'){
                break;
            }
            string cur_s=num.substr(pos,i-pos+1);
            long long cur=atoll(cur_s.c_str());
            if(pos==0){
                helper(num,target,ret,path+cur_s,i+1,cur,cur);
            }else{
                helper(num,target,ret,path+"+"+cur_s,i+1,eval+cur,cur);
                helper(num,target,ret,path+"-"+cur_s,i+1,eval-cur,-cur);
                helper(num,target,ret,path+"*"+cur_s,i+1,eval-last+last*cur,last*cur);
            }
            
            
        }
        
        
        
    }
    
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ret;
        if(num.size()==0){
            return ret;
        }
        helper(num,target,ret,"",0,0,0);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<string> ret=so.addOperators("232", 8);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
