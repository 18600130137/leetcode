//
//  main.cpp
//  349. Intersection of Two Arrays
//
//  Created by admin on 2019/8/22.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>  s1,s2;
        for(auto  n1:nums1){
            s1.insert(n1);
        }
        for(auto n2:nums2){
            if(s1.find(n2)!=s1.end()){
                s2.insert(n2);
            }
        }
        
        return vector<int>(s2.begin(),s2.end());
    }
};
int main(int argc, const char * argv[]) {
    vector<int> i1={4,9,5};
    vector<int> i2={9,4,9,8,4};
    Solution so=Solution();
    vector<int> ret=so.intersection(i1, i2);
    for(auto r:ret){
        cout<<r<<" ";
    }
    cout<<endl;	
    return 0;
}
