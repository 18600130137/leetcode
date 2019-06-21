//
//  main.cpp
//  228. Summary Ranges
//
//  Created by admin on 2019/6/21.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int m=nums.size();
        vector<string> ret;
        if(m==0){
            return ret;
        }else if(m==1){
            ret.push_back(to_string(nums[0]));
            return ret;
        }
        
        int start=nums[0],end=start;
        
        for(int i=1;i<m;i++){
            if(nums[i]==nums[i-1]+1){
                end++;
            }else{
                if(start==end){
                    ret.push_back(to_string(start));
                }else{
                    ret.push_back(to_string(start)+"->"+to_string(end));
                }
                start=nums[i];
                end=start;
            }
        }
        if(start==end){
            ret.push_back(to_string(start));
        }else{
            ret.push_back(to_string(start)+"->"+to_string(end));
        }
        
        
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={0,1,2,4,5,7};
    Solution so=Solution();
    vector<string> ret=so.summaryRanges(input);
    for(auto s:ret){
        cout<<s<<" ";
    }
    cout<<endl;
    return 0;
}
