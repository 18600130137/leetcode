//
//  main.cpp
//  275. H-Index II
//
//  Created by admin on 2019/7/3.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& ci) {
        int m=ci.size();
        if(m==1){
            return ci[0]>0;
        }
        
        int left=0,right=m-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(ci[mid]==m-mid){
                return ci[mid];
            }else if(ci[mid]<m-mid){
                left=mid+1;
            }else{
                right=mid-1;
            }
            //cout<<left<<" "<<right<<endl;
        }
        
        return m-left;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={0,1,3,5,6};
    Solution so=Solution();
    int ret=so.hIndex(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
