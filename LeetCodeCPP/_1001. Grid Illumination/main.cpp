
//
//  main.cpp
//  1001. Grid Illumination
//
//  Created by admin on 2019/2/25.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        unordered_map<int,int> diagonal1;
        unordered_map<int,int> diagonal2;
        unordered_map<long,bool> id;
        
        for(auto lamp:lamps){
            row[lamp[0]]++;
            col[lamp[1]]++;
            diagonal1[lamp[0]-lamp[1]]++;
            diagonal2[lamp[0]+lamp[1]]++;
            id[N*(long)lamp[0]+lamp[1]]=true;
        }
        
        vector<int>  ret;
        for(auto query:queries){
            if(row[query[0]]>0 || col[query[1]]>0 || diagonal1[query[0]-query[1]]>0 || diagonal2[query[0]+query[1]]>0){
                ret.push_back(1);
            }else{
                ret.push_back(0);
            }
            for(int i=query[0]-1;i<=query[0]+1;i++){
                for(int j=query[1]-1;j<=query[1]+1;j++){
                    if(i>=0 && i<N &&j>=0 && j<N && id[N*(long)i+j]){
                        id[N*(long)i+j]=false;
                        row[i]--;
                        col[j]--;
                        diagonal1[i-j]--;
                        diagonal2[i+1]--;
                    }
                }
            }
            
        }
        
        return  ret;
        
        
    }
};




int main(int argc, const char * argv[]) {
    int input1=5;
    vector<vector<int>> input2={{0,0},{4,4}};
    vector<vector<int>> input3={{1,1},{1,0}};
    Solution  so=Solution();
    vector<int> ret=so.gridIllumination(input1,input2, input3);
    for(auto i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}
