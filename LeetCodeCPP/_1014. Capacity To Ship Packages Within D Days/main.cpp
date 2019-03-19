//
//  main.cpp
//  _1014. Capacity To Ship Packages Within D Days
//
//  Created by admin on 2019/3/18.
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
    int shipWithinDays(vector<int>& weights, int D) {
        int left=0,right=0;
        for(int i=0;i<weights.size();i++){
            left=max(left,weights[i]);
            right+=weights[i];
        }
        while(left<right){
            int mid=(left+right)/2;
            int need=1,tmp=0;
            for(int i=0;i<weights.size();i++){
                if(tmp+weights[i]>mid){
                    need++;
                    tmp=0;
                }
                tmp+=weights[i];
            }
            if(need>D){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        return left;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input= {1,2,3,4,5,6,7,8,9,10};
    Solution so=Solution();
    int ret=so.shipWithinDays(input,5);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
