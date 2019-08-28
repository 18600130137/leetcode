//
//  main.cpp
//  _1170. Compare Strings by Frequency of the Smallest Character
//
//  Created by admin on 2019/8/28.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int  f(string str){
        vector<int>  helper(26,0);
        for(auto s:str){
            helper[s-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(helper[i]){
                return helper[i];
            }
        }
        return 0;
    }
    
    
public:
    //complexity   O(n2)
    vector<int> numSmallerByFrequency1(vector<string>& queries, vector<string>& words) {
        int m=queries.size();
        int n=words.size();
        vector<int>  cal_words(n,0);
        for(int i=0;i<n;i++){
            cal_words[i]=f(words[i]);
        }
        
        vector<int> ret(m,0);
        for(int i=0;i<m;i++){
            int cal_q=f(queries[i]);
            for(int j=0;j<n;j++){
                if(cal_q<cal_words[j]){
                    ret[i]++;
                }
            }
        }
        
        return ret;
    }
    
    //complexity   O(nlogn)
    vector<int> numSmallerByFrequency2(vector<string>& queries, vector<string>& words) {
        int m=queries.size();
        int n=words.size();
        
        vector<int>  w(n,0);
        for(int i=0;i<n;i++){
            w[i]=f(words[i]);
        }
        sort(w.begin(),w.end());
        
        vector<int> ret(m,0);
        for(int i=0;i<m;i++){
            int q=f(queries[i]);
            auto iterUpper=upper_bound(w.begin(),w.end(),q);
            if(iterUpper==w.end()){
                ret[i]=0;
            }else{
                ret[i]=n-(iterUpper-w.begin());
            }
        }
        
        return ret;
    }
    
    //complexity   O(n)
    vector<int> numSmallerByFrequency3(vector<string>& queries, vector<string>& words) {
        int m=queries.size();
        int n=words.size();
        
        vector<int>  freq(12,0);
        for(int i=0;i<n;i++){
            freq[f(words[i])]++;
        }
        
        for(int i=10;i>=1;i--){
            freq[i-1]+=freq[i];
        }
        vector<int> ret(m,0);
        for(int i=0;i<m;i++){
            ret[i]=freq[f(queries[i])+1];
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<string> q={"bbb","cc"};
    vector<string> w ={"a","aa","aaa","aaaa"};
    Solution so=Solution();
    vector<int> ret=so.numSmallerByFrequency3(q, w);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
