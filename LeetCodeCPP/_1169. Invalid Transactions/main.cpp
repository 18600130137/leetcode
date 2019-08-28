//
//  main.cpp
//  _1169. Invalid Transactions
//
//  Created by admin on 2019/8/27.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


struct Info{
    string name;
    int time;
    int amount;
    string city;
    string main_str;
};

class Solution {
public:
    vector<string> invalidTransactions1(vector<string>& transactions) {
        int m=transactions.size();
        vector<Info>  trans_obj;
        for(auto  tr:transactions){
            Info tmp;
            string cache="";
            int count=0;
            for(int i=0;i<= tr.size();i++){
                if(i==tr.size() || tr[i]==','){
                    if(i==tr.size()){
                        tmp.city=cache;
                    }else if(count==0){
                        tmp.name=cache;
                    }else if(count==1){
                        tmp.time=stoi(cache);
                    }else if(count==2){
                        tmp.amount=stoi(cache);
                    }
                    count++;
                    cache="";
                }else{
                    cache+=tr[i];
                }
            }
            tmp.main_str=tr;
            trans_obj.push_back(tmp);
        }
        
        vector<string> ret;
        for(int i=0;i<m;i++){
            Info  obj_i=trans_obj[i];
            //cout<<obj_i.amount<<" "<<obj_i.main_str<<endl;
            if(obj_i.amount>=1000){
                ret.push_back(obj_i.main_str);
                continue;
            }
            bool  conflict=false;
            for(int j=0;j<m;j++){
                if(i==j){
                    continue;
                }
                Info obj_j=trans_obj[j];
                if(obj_i.name==obj_j.name && obj_i.city!=obj_j.city && abs(obj_i.time-obj_j.time)<=60){
                    conflict=true;
                    break;
                }
            }
            
            if(conflict){
                ret.push_back(obj_i.main_str);
            }
            
        }
        return ret;
    }
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        int m=transactions.size();
        vector<Info>  trans_obj;
        for(auto  tr:transactions){
            Info tmp;
            string cache="";
            int count=0;
            for(int i=0;i<= tr.size();i++){
                if(i==tr.size() || tr[i]==','){
                    if(i==tr.size()){
                        tmp.city=cache;
                    }else if(count==0){
                        tmp.name=cache;
                    }else if(count==1){
                        tmp.time=stoi(cache);
                    }else if(count==2){
                        tmp.amount=stoi(cache);
                    }
                    count++;
                    cache="";
                }else{
                    cache+=tr[i];
                }
            }
            tmp.main_str=tr;
            trans_obj.push_back(tmp);
        }
        vector<bool>   conflict(m,false);
        vector<string> ret;
        for(int i=0;i<m;i++){
            Info  obj_i=trans_obj[i];
            //cout<<obj_i.amount<<" "<<obj_i.main_str<<endl;
            if(obj_i.amount>=1000){
                conflict[i]=true;
            }
            for(int j=i+1;j<m;j++){
                Info obj_j=trans_obj[j];
                if(obj_i.name==obj_j.name && obj_i.city!=obj_j.city && abs(obj_i.time-obj_j.time)<=60){
                    conflict[i]=true;
                    conflict[j]=true;
                }
            }
        }
        
        
        for(int i=0;i<m;i++){
            if(conflict[i]){
                ret.push_back(trans_obj[i].main_str);
            }
        }
        
        
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    vector<string>  input={"alice,20,800,mtv","alice,50,100,beijing"};
    Solution so=Solution();
    vector<string> ret=so.invalidTransactions(input);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
