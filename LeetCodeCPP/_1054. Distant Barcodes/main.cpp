//
//  main.cpp
//  _1054. Distant Barcodes
//
//  Created by admin on 2019/5/27.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
    
    
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int m=barcodes.size();
        unordered_map<int,int> helper1;
        for(auto b:barcodes){
            helper1[b]++;
        }
        set<pair<int,int>> helper2;
        for(auto  item:helper1){
            helper2.insert({item.second,item.first});
        }
        int pos=0;
        for(auto iter=helper2.rbegin();iter!=helper2.rend();iter++){
            for(auto i=0;i<iter->first;i++,pos+=2){
                if(pos>=m){
                    pos=1;
                }
                barcodes[pos]=iter->second;
            }
        }
        
        return barcodes;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,1,1,2,2,2};
    Solution so=Solution();
    vector<int> ret=so.rearrangeBarcodes(input);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
