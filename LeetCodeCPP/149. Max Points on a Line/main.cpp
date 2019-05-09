//
//  main.cpp
//  149. Max Points on a Line
//
//  Created by admin on 2019/5/9.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int GCD(int y,int x){
        if(x==0){
            return y;
        }
        return GCD(x,y%x);
    }
    
public:
    int maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        unordered_map<int,unordered_map<int,int>>  helper;
        int ret=0;
        for(int i=0;i<m;i++){
            int tmp_max=0;
            int overlap=0;
            helper.clear();
            for(int j=i+1;j<m;j++){
                int x=points[j][0]-points[i][0];
                int y=points[j][1]-points[i][1];
                if(x==0 && y==0){
                    overlap++;
                    continue;
                }
                int gcd=GCD(y,x);
                if(gcd!=0){
                    x/=gcd;
                    y/=gcd;
                }
                if(helper.count(x)){
                    if(helper[x].count(y)){
                        helper[x][y]++;
                    }else{
                        helper[x][y]=1;
                    }
                }else{
                    helper[x][y]=1;
                }
                tmp_max=max(tmp_max,helper[x][y]);
                
            }
            // cout<<tmp_max<<endl;
            ret=max(ret,tmp_max+overlap+1);
        }
        
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    vector<vector<int>> input={{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    Solution so=Solution();
    int maxLen=so.maxPoints(input);
    cout<<"The max len is:"<<maxLen<<endl;
    return 0;
}
