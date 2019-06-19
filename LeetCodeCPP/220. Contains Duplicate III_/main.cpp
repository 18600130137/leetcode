//
//  main.cpp
//  220. Contains Duplicate III_
//
//  Created by admin on 2019/6/19.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool containsNearbyAlmostDuplicate1(vector<int>& nums, int k, int t) {
        int m=nums.size();
        set<long> helper;
        for(int i=0;i<m;i++){
            if(i>=k+1){
                helper.erase(nums[i-k-1]);
            }
            set<long>::iterator iter=helper.lower_bound((long)nums[i]-t);
            //cout<<nums[i]<<" *iter:"<<*iter<<endl;
            if(iter!=helper.end() && *iter-t<=nums[i]){
                return true;
            }
            helper.insert(nums[i]);
        }
        
        return false;
    }
    
    //核心技巧=区间映射
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
        if(k<1 || t<0){
            return false;
        }
        unordered_map<long long,long long> helper;
        for(int i=0;i<nums.size();i++){
            if(i>=k+1){
                long long leftValue=(long)nums[i-k-1]-INT_MIN;
                long long leftBuket=leftValue/((long long)t+1);
                //cout<<"left buket=="<<leftBuket<<endl;
                helper.erase(leftBuket);
            }
            
            long long mapedValue=(long long)nums[i]-INT_MIN;
            long long buket=mapedValue/((long long)t+1);
            //cout<<"buket=="<<buket<<endl;
            if(helper.count(buket) || helper.count(buket+1) && helper[buket+1]-mapedValue<=t ||
               helper.count(buket-1) && mapedValue-helper[buket-1]<=t){
                // for(auto item:helper){
                //     cout<<item.first<<"    "<<item.second<<endl;
                // }
                return true;
            }
            
            helper[buket]=mapedValue;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,5,9,1,5,9};
    Solution so=Solution();
    bool ret=so.containsNearbyAlmostDuplicate(input,2, 3);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
