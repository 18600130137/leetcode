//
//  main.cpp
//  128. Longest Consecutive Sequence
//
//  Created by admin on 2019/4/19.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive1(vector<int>& nums) {
        unordered_set<int> nums_set;
        int m=nums.size();
        for(int i=0;i<m;i++){
            nums_set.insert(nums[i]);
        }
        int ret=0;
        for(int i=0;i<m;i++){
            int num=nums[i];
            if(nums_set.find(num)!=nums_set.end()){
                nums_set.erase(num);
                int last=num-1,left=0;
                while(nums_set.find(last)!=nums_set.end()){
                    nums_set.erase(last);
                    left++;
                    last--;
                }
                int next=num+1,right=0;
                while(nums_set.find(next)!=nums_set.end()){
                    nums_set.erase(next);
                    right++;
                    next++;
                }
                ret=max(ret,left+right+1);
            }
        }
        return ret;
    }
    
    int longestConsecutive(vector<int>& nums) {
        int m=nums.size();
        int ret=0;
        unordered_map<int,int> helper;
        
        for(int i=0;i<m;i++){
            if(helper.find(nums[i])==helper.end()){
                int left=helper.find(nums[i]-1)==helper.end()?0:helper[nums[i]-1];
                int right=helper.find(nums[i]+1)==helper.end()?0:helper[nums[i]+1];
                int sum=1+left+right;
                //cout<<nums[i]<<" "<<left<<" "<<right<<" "<<sum<<endl;
                ret=max(ret,sum);
                helper[nums[i]]=sum;
                helper[nums[i]-left]=sum;
                helper[nums[i]+right]=sum;
            }
        }
        // cout<<endl;
        // for(auto  item:helper){
        //     cout<<item.first<<" "<<item.second<<endl;
        // }
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={100,4,200,1,3,2};
    Solution so=Solution();
    int ret=so.longestConsecutive1(input);
    cout<<"The max len is:"<<ret<<endl;
    return 0;
}
