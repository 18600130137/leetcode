//
//  main.cpp
//  _1157. Online Majority Element In Subarray
//
//  Created by admin on 2019/8/13.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class MajorityChecker {
private:
    unordered_map<int,vector<int>>  helper;
    vector<int> my_arr;
    
    int get_random(int l, int r) {
        return rand() % (r - l + 1) + l;
    }
    
public:
    MajorityChecker(vector<int>& arr) {
        srand(time(nullptr));
        my_arr=arr;
        for(int i=0;i<arr.size();i++){
            helper[arr[i]].push_back(i);
        }
    }
    
    
    int query(int left, int right, int threshold) {
        
        for(int i=0;i<20;i++){
            int r_id=get_random(left,right);
            int cv=my_arr[r_id];
            if(helper[cv].size()<threshold){
                continue;
            }
            auto leftIter=lower_bound(helper[cv].begin(),helper[cv].end(),left);
            auto rightIter=upper_bound(helper[cv].begin(),helper[cv].end(),right);
            if(rightIter-leftIter>=threshold){
                return cv;
            }
        }
        return -1;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={1,1,2,2,1,1};
    MajorityChecker* obj = new MajorityChecker(input);
    int ret1=obj->query(0, 5, 4);
    cout<<"ret1 is:"<<ret1<<endl;
    int ret2=obj->query(0, 3, 3);
    cout<<"ret2 is:"<<ret2<<endl;
    int ret3=obj->query(2, 3, 2);
    cout<<"ret3 is:"<<ret3<<endl;
    return 0;
}
