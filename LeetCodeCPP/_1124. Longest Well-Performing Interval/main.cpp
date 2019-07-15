//
//  main.cpp
//  _1124. Longest Well-Performing Interval
//
//  Created by admin on 2019/7/15.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int m=hours.size();
        int  ans=0;
        int sum=0;
        unordered_map<int,int> helper;
        for(int i=0;i<m;i++){
            sum+=hours[i]>8?1:-1;
            //cout<<"sum=="<<sum<<endl;
            if(sum>0){
                ans=i+1;
            }else{
                if(helper.count(sum-1)>0){
                    ans=max(ans,i-helper[sum-1]);
                }
            }
            if(helper.count(sum)==0){
                helper[sum]=i;
            }
        }
        
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={9,9,6,0,6,6,9};
    Solution so=Solution();
    int ret=so.longestWPI(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
