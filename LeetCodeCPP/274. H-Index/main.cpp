//
//  main.cpp
//  274. H-Index
//
//  Created by admin on 2019/7/3.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex1(vector<int>& citations) {
        sort(citations.begin(),citations.end(),[](int c1,int c2){
            return c1>c2;
        });
        int m=citations.size();
        for(int i=0;i<m;i++){
            if(citations[i]<i+1){
                return i;
            }
        }
        return m;
        
    }
    
    int hIndex(vector<int>& c) {
        int m=c.size();
        vector<int> buckets(m+1,0);
        for(int i=0;i<m;i++){
            if(c[i]>=m){
                buckets[m]++;
            }else{
                buckets[c[i]]++;
            }
        }
        int count=0;
        for(int i=m;i>=0;i--){
            count+=buckets[i];
            if(count>=i){
                return i;
            }
        }
        
        return 0;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input={3,0,6,1,5};
    Solution so=Solution();
    int ret=so.hIndex(input);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
