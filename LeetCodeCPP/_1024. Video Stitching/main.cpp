//
//  main.cpp
//  _1024. Video Stitching
//
//  Created by admin on 2019/4/8.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    static bool compare(vector<int> &v1,vector<int> &v2){
        return v1[0]<v2[0];
    }
    
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(),clips.end(),compare);
        if(T==0){
            return 0;
        }
        int left=0,right=0;
        int m=clips.size();
        int i=0;
        int step=0;
        while(i<m){
            int maxRight=right;
            while(i<m && clips[i][0]<=right){
                maxRight=max(maxRight,clips[i][1]);
                i++;
            }
            if(right==maxRight){
                if(maxRight<T){
                    return -1;
                }else{
                    return step;
                }
            }
            step++;
            right=maxRight;
            
            if(right>=T){
                break;
            }
            
        }
        if(right<T){
            return -1;
        }
        
        return step;
    }
};

// [[5,7],[1,8],[0,0],[2,3],[4,5],[0,6],[5,10],[7,10]]
// 5

int main(int argc, const char * argv[]) {
    vector<vector<int>> input={{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};
    Solution so=Solution();
    int ret=so.videoStitching(input, 10);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
