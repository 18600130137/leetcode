//
//  main.cpp
//  _1192. Critical Connections in a Network
//
//  Created by admin on 2019/9/17.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private:
        void h(int u,vector<bool> &vi,vector<int> &dfn,vector<int> &low,vector<int> &parent,vector<vector<int>> &grap,vector<vector<int>> &res){
            static int time=0;
            dfn[u]=low[u]=++time;
            vi[u]=true;
            for(auto  v:grap[u]){
                if(!vi[v]){
                    parent[v]=u;
                    h(v,vi,dfn,low,parent,grap,res);
                    low[u]=min(low[u],low[v]);
                    if(dfn[u]<low[v]){
                        res.push_back({u,v});
                    }
                }else if(v!=parent[u]){
                    low[u]=min(low[u],dfn[v]);
                }
            }
        }
        
    public:
        vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
            vector<bool>  vi(n,false);
            vector<int>   dfn(n,0),low(n,0),parent(n,-1);
            vector<vector<int>>  grap(n,vector<int>()),res;
            for(auto c:connections){
                grap[c[0]].push_back(c[1]);
                grap[c[1]].push_back(c[0]);
            }
            for(int i=0;i<n;i++){
                if(vi[i]) continue;
                h(i,vi,dfn,low,parent,grap,res);
            }
            
            return res;
        }

    int  test1(){
        static int a=1;
        cout<<a++<<endl;
        return -1;
    }
};
int main(int argc, const char * argv[]) {
    int input1=4;
    vector<vector<int>> input2={{0,1},{1,2},{2,0},{1,3}};
    Solution so=Solution();
    vector<vector<int>> ret=so.criticalConnections(input1, input2);
    for(auto r:ret){
        cout<<r[0]<<" "<<r[1]<<endl;
    }
    return 0;
}
