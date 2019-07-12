//
//  main.cpp
//  303. Range Sum Query - Immutable
//
//  Created by admin on 2019/7/12.
//  Copyright © 2019年 liu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> helper;
    //1 2 3 4 5
    //1 3 6 10 15
public:
    NumArray(vector<int>& nums) {
        int m=nums.size();
        if(m==0){
            return;
        }
        helper.resize(m,0);
        helper[0]=nums[0];
        for(int i=1;i<m;i++){
            helper[i]+=helper[i-1]+nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if(i>j){
            return -1;
        }else{
            return helper[j]-(i==0?0:helper[i-1]);
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input={-2,0,3,-5,2,-1};
    NumArray* obj = new NumArray(input);
    int ret = obj->sumRange(2,5);
    cout<<"The ret is:"<<ret<<endl;
    return 0;
}
