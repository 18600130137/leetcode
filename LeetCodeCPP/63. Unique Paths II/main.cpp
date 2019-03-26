//
//  main.cpp
//  63. Unique Paths II
//
//  Created by admin on 2019/3/26.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles1(vector<vector<int>>& obstacleGrid) {
        int m=(int)obstacleGrid.size();
        if(m==0){
            return 0;
        }
        int n=(int)obstacleGrid[0].size();
        if(n==0){
            return 0;
        }
        cout<<m<<" "<<n<<endl;
        // if(obstacleGrid[m-1][n-1]==1){
        //     return 0;
        // }
        
        obstacleGrid[0][0]=1;
        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]==1){
                obstacleGrid[i][0]=0;
            }else{
                obstacleGrid[i][0]=obstacleGrid[i-1][0];
            }
        }
        for(int i=1;i<n;i++){
            if(obstacleGrid[0][i]==1){
                obstacleGrid[0][i]=0;
            }else{
                obstacleGrid[0][i]=obstacleGrid[0][i-1];
            }
        }
        
        for(auto  item:obstacleGrid){
            for(auto i:item){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    obstacleGrid[i][j]=0;
                }else{
                    obstacleGrid[i][j]=obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
                    //cout<<i<<" "<<j<<" "<<obstacleGrid[i][j]<<endl;
                }
            }
            for(auto  item:obstacleGrid){
                for(auto i:item){
                    cout<<i<<" ";
                }
                cout<<endl;
            }
            cout<<endl<<endl;
        }
        
        return obstacleGrid[m-1][n-1];
        
    }
    
    
    long long uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m=(int)obstacleGrid.size();
        if(m==0){
            return 0;
        }
        int n=(int)obstacleGrid[0].size();
        if(n==0){
            return 0;
        }
        if(obstacleGrid[0][0]==1 or obstacleGrid[m-1][n-1]==1){
            return 0;
        }
        
        vector<long long> helper(n,0);
        helper[0]=1;
        
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    helper[j]=0;
                }else if(j>0){
                    helper[j]+=helper[j-1];
                }
            }
        }
        
        for(auto  item:helper){
            cout<<item<<" ";
        }
        cout<<endl;
        
        
        return helper[n-1];
        
    }
    
};
vector<vector<int>>  getInput(){
    return {{0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},{1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1},{0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},{0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0},{1,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0},{0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0},{0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0},{0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,1},{1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,0,0,0,0,1,1},{0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1},{1,1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0}};
}



int main(int argc, const char * argv[]) {
    vector<vector<int>>  input=getInput();
    Solution so=Solution();
    int ret=so.uniquePathsWithObstacles(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
