//
//  main.cpp
//  164. Maximum Gap
//
//  Created by admin on 2019/5/17.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int m=nums.size();
        
        if(m<=1){
            return 0;
        }
        
        int min_=nums[0];
        int max_=nums[0];
        
        for(int i=1;i<m;i++){
            min_=min(min_,nums[i]);
            max_=max(max_,nums[i]);
        }
        int aveGap=ceil((max_-min_)*1.0/(m-1));
        //cout<<"m=="<<m<<" aveGap==="<<aveGap<<endl;
        vector<int> minBuket(m-1,INT_MAX);
        vector<int> maxBuket(m-1,INT_MIN);
        for(auto n:nums){
            if(n==min_ || n==max_){
                continue;
            }
            int idx=(n-min_)/aveGap;
            //cout<<"idx=="<<idx<<endl;
            minBuket[idx]=min(n,minBuket[idx]);
            maxBuket[idx]=max(n,maxBuket[idx]);
        }
        
        int prevous=min_;
        int maxGap=INT_MIN;
        for(int i=0;i<m-1;i++){
            if(minBuket[i]==INT_MAX && maxBuket[i]==INT_MIN){
                continue;
            }
            maxGap=max(maxGap,minBuket[i]-prevous);
            prevous=maxBuket[i];
        }
        maxGap=max(maxGap,max_-prevous);
        
        
        return maxGap;
        
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={12115,10639,2351,29639,31300,11245,16323,24899,8043,4076,17583,15872,19443,12887,5286,6836,31052,25648,17584,24599,13787,24727,12414,5098,26096,23020,25338,28472,4345,25144,27939,10716,3830,13001,7960,8003,10797,5917,22386,12403,2335,32514,23767,1868,29882,31738,30157,7950,20176,11748,13003,13852,19656,25305,7830,3328,19092,28245,18635,5806,18915,31639,24247,32269,29079,24394,18031,9395,8569,11364,28701,32496,28203,4175,20889,28943,6495,14919,16441,4568,23111,20995,7401,30298,2636,16791,1662,27367,2563,22169,1607,15711,29277,32386,27365,31922,26142,8792};
    Solution so=Solution();
    int maxGap=so.maximumGap(input);
    cout<<"The max gap is:"<<maxGap<<endl;
    return 0;
}
