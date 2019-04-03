//
//  main.cpp
//  85. Maximal Rectangle
//
//  Created by admin on 2019/4/3.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maximalRectangle1(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0){
            return 0;
        }
        int n=matrix[0].size();
        if(n==0){
            return 0;
        }
        int  max_area=0;
        vector<int> heights(n+1,0);
        for(int i=0;i<m;i++){
            stack<int> s;
            int h=0;
            for(int j=0;j<=n;j++){
                if(j<n){
                    if(matrix[i][j]=='1'){
                        heights[j]++;
                    }else{
                        heights[j]=0;
                    }
                }
                if(s.empty() || heights[j]>=heights[s.top()]){
                    s.push(j);
                }else{
                    while(!s.empty() && heights[j]<heights[s.top()]){
                        int top=s.top();
                        s.pop();
                        int area=heights[top]*(s.empty()?j:j-s.top()-1);
                        if(area>max_area){
                            max_area=area;
                        }
                    }
                    s.push(j);
                }
            }
        }
        
        return max_area;
        
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0){
            return 0;
        }
        int n=matrix[0].size();
        if(n==0){
            return 0;
        }
        int  max_area=0;
        vector<int> h(n,0);
        vector<int> l(n,0);
        vector<int> r(n,n);
        for(int i=0;i<m;i++){
            int left_s=0,right_s=n;
            for(int j=n-1;j>=0;j--){
                if(matrix[i][j]=='1'){
                    r[j]=min(right_s,r[j]);
                }else{
                    r[j]=n;
                    right_s=j;
                }
            }
            
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    h[j]++;
                    l[j]=max(left_s,l[j]);
                }else{
                    h[j]=0;
                    l[j]=0;
                    left_s=j+1;
                }
                max_area=max(max_area,h[j]*(r[j]-l[j]));
            }
            
        }
        
        return max_area;
        
    }
};


int main(int argc, const char * argv[]) {
    vector<vector<char>> input={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    Solution so=Solution();
    int ret=so.maximalRectangle(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
