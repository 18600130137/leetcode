//
//  main.cpp
//  _1105. Filling Bookcase Shelves
//
//  Created by admin on 2019/7/1.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int m=books.size();
        vector<int> dp(m+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=m;i++){
            int width=books[i-1][0];
            int height=books[i-1][1];
            dp[i]=dp[i-1]+height;
            for(int j=i-1;j>0;j--){
                width+=books[j-1][0];
                if(width>shelf_width){
                    break;
                }
                height=max(height,books[j-1][1]);
                dp[i]=min(dp[i],dp[j-1]+height);
            }
        }
        return dp[m];
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>>  input={{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    Solution so=Solution();
    int ret=so.minHeightShelves(input,4);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
