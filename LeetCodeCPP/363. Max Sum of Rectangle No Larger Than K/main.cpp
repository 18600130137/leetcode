//
//  main.cpp
//  363. Max Sum of Rectangle No Larger Than K
//
//  Created by admin on 2019/9/11.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty()){
            return 0;
        }
        int m=matrix.size(),n=matrix[0].size();
        int ret=INT_MIN;
        for(int l=0;l<n;l++){
            vector<int>  row(m,0);
            for(int c=l;c<n;c++){
                for(int i=0;i<m;i++){
                    row[i]+=matrix[i][c];
                }
                
                int curAcc=0,localRet=INT_MIN;
                set<int>  helper;
                helper.insert(0);
                for(auto r:row){
                    curAcc+=r;
                    auto iter=helper.lower_bound(curAcc-k);
                    if(iter!=helper.end()){
                        localRet=max(localRet,curAcc-*iter);
                    }
                    helper.insert(curAcc);
                }
                ret=max(ret,localRet);
            }
            
        }
        
        return ret;
    }
    
};
int main(int argc, const char * argv[]) {
    vector<vector<int>> input1={{1,0,1},{0,-2,3}};
    int k = 2;
    Solution so=Solution();
    int ret=so.maxSumSubmatrix(input1, k);
    cout<<"The ret is:"<<ret<<endl;
    
}
