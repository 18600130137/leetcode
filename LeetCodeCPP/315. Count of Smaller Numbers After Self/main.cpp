//
//  main.cpp
//  315. Count of Smaller Numbers After Self
//
//  Created by admin on 2019/7/23.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void  merger(vector<pair<int,int>> &helper,int first,int last,vector<int> &ret){
        int count=last-first;
        if(count>1){
            int step=count/2;
            int mid=first+step;
            merger(helper,first,mid,ret);
            merger(helper,mid,last,ret);
            int idx1=first,idx2=mid;
            int seg=0;
            vector<pair<int,int>>  tmp;
            tmp.reserve(count);
            while(idx1<mid || idx2<last){
                if(idx2>=last || ((idx1<mid) && (helper[idx1].second<=helper[idx2].second))){
                    tmp.push_back(helper[idx1]);
                    ret[helper[idx1].first]+=seg;
                    idx1++;
                }else{
                    tmp.push_back(helper[idx2]);
                    seg++;
                    idx2++;
                }
            }
            move(tmp.begin(),tmp.end(),helper.begin()+first);
            
        }
        
    }
    
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int m=nums.size();
        vector<pair<int,int>> helper(m);
        for(int i=0;i<m;i++){
            helper[i]=make_pair(i,nums[i]);
        }
        vector<int>  ret(m,0);
        merger(helper,0,m,ret);
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>  input={5,2,6,1};
    Solution so=Solution();
    vector<int> ret=so.countSmaller(input);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
