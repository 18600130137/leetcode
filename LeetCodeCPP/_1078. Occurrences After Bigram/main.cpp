//
//  main.cpp
//  _1078. Occurrences After Bigram
//
//  Created by admin on 2019/6/10.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> findOcurrences1(string text, string first, string second) {
        int m=text.size();
        
        vector<string> saver;
        string tmp="";
        vector<string> ret;
        for(int i=0;i<m;i++){
            if(text[i]==' ' && tmp!=""){
                int s=saver.size();
                if(s>=2 && (saver[s-2]+" "+saver[s-1])==(first+" "+second)){
                    ret.push_back(tmp);
                }
                saver.push_back(tmp);
                tmp="";
            }else{
                tmp+=text[i];
            }
        }
        int s=saver.size();
        if(tmp!="" && s>=2 && (saver[s-2]+" "+saver[s-1])==(first+" "+second)){
            ret.push_back(tmp);
        }
        
        
        return ret;
        
    }
    
    
    vector<string> findOcurrences2(string text, string first, string second) {
        stringstream ss(text);
        vector<string> ret,saver;
        string word;
        while(ss>>word){
            int len=saver.size();
            if(len>=2 && saver[len-2]==first && saver[len-1]==second){
                ret.push_back(word);
            }
            saver.push_back(word);
        }
        
        return ret;
        
    }
    
    vector<string> findOcurrences3(string text, string first, string second) {
        string target=first+" "+second+" ";
        int p=text.find(target);
        vector<string> ret;
        while(p!=string::npos){
            int p1=p+target.size(),p2=p1;
            while(p2<text.size() && text[p2]!=' '){
                p2++;
            }
            ret.push_back(text.substr(p1,p2-p1));
            p=text.find(target,p+1);
        }
        
        return ret;
        
    }
    
    
};

int main(int argc, const char * argv[]) {
    Solution so=Solution();
    vector<string> ret=so.findOcurrences3("alice is a good girl she is a good student","a","good");
    for (auto  s:ret) {
        cout<<s<<" ";
    }
    cout<<endl;
    return 0;
}
