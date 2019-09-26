//
//  main.cpp
//  373. Find K Pairs with Smallest Sums
//
//  Created by admin on 2019/9/24.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    struct mycompare{
        bool operator()(pair<int, int>& p1, pair<int, int>& p2){
            return p1.first + p1.second < p2.first + p2.second;
        }
    };
    
    struct myCompare1{
        bool operator()(vector<int> &v1,vector<int> &v2){
            return v1[0]+v1[1]>v2[0]+v2[1];
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m=nums1.size(),n=nums2.size();
        vector<vector<int>>  ret;
        if(m==0 || n==0 || k<=0){
            return ret;
        }
        // auto my_compare=[](pair<int,int> &p1,pair<int,int> &p2){
        //     return p1.first+p1.second<p2.first+p2.second;
        // };
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycompare>     my_queue;
        
        for(int i=0;i<m &&i<k;i++){
            for(int j=0;j<n &&j<k;j++){
                if(my_queue.size()<k){
                    my_queue.push({nums1[i],nums2[j]});
                }else if(nums1[i]+nums2[j]<my_queue.top().first+my_queue.top().second){
                    my_queue.push({nums1[i],nums2[j]});
                    my_queue.pop();
                }
            }
        }
        while(!my_queue.empty()){
            ret.push_back({my_queue.top().first,my_queue.top().second});
            my_queue.pop();
        }
        return ret;
    }
    
    vector<vector<int>> kSmallestPairs1(vector<int>& nums1, vector<int>& nums2, int k) {
        int m=nums1.size(),n=nums2.size();
        vector<vector<int>> ret;
        if(m==0 || n==0 || k<=0){
            return ret;
        }
        priority_queue<vector<int>,vector<vector<int>>,myCompare1>  my_queue;
        for(int i=0;i<m;i++){
            my_queue.push({nums1[i],nums2[0],0});
        }
        
        while(k-- && !my_queue.empty()){
            vector<int> front=my_queue.top();
            ret.push_back({front[0],front[1]});
            my_queue.pop();
            if(front[2]==n-1){
                continue;
            }
            my_queue.push({front[0],nums2[front[2]+1],front[2]+1});
        }
        
        return ret;
        
        
    }};
int main(int argc, const char * argv[]) {
    vector<int> input1={1,7,11};
    vector<int> input2={2,4,6};
    int k=3;
    Solution so=Solution();
    vector<vector<int>> ret=so.kSmallestPairs1(input1, input2, k);
    for(auto  r:ret){
        cout<<r[0]<<" "<<r[1]<<endl;
    }
    return 0;
}
