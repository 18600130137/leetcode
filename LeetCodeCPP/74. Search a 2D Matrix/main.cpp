//
//  main.cpp
//  74. Search a 2D Matrix
//
//  Created by admin on 2019/3/29.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(m==0){
            return false;
        }
        int n=matrix[0].size();
        if(n==0){
            return false;
        }
        int left=0,right=m*n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(matrix[mid/n][mid%n]==target){
                return true;
            }else if(matrix[mid/n][mid%n]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        
        return false;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>>  input={{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    Solution so=Solution();
    bool ret=so.searchMatrix(input, 12);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
